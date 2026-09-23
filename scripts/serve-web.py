"""Serve only the built viewer site on loopback, with read-only access to local/game."""
import argparse
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
import json
from pathlib import Path


class Handler(SimpleHTTPRequestHandler):
    extensions_map = {
        **SimpleHTTPRequestHandler.extensions_map,
        '.wasm': 'application/wasm',
        '.js': 'text/javascript',
        '.crp': 'application/octet-stream',
        '.fsh': 'application/octet-stream',
        '.tpg': 'application/octet-stream',
        '.edg': 'application/octet-stream',
        '.jnc': 'application/octet-stream',
        '.map': 'text/plain',
        '.scn': 'application/octet-stream',
    }

    game_dir = None
    game_files_cache = None

    def end_headers(self):
        self.send_header('Cache-Control', 'no-store')
        super().end_headers()

    def do_GET(self):
        if self.path == '/healthz':
            data = b'{"status":"ok"}'
            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.send_header('Content-Length', str(len(data)))
            self.end_headers()
            self.wfile.write(data)
            return
        if self.path == '/api/game-files':
            if not self.game_dir or not self.game_dir.is_dir():
                self.send_error(404, 'local/game directory not found')
                return
            if self.__class__.game_files_cache is None:
                self.__class__.game_files_cache = [
                    p.relative_to(self.game_dir).as_posix()
                    for p in self.game_dir.rglob('*')
                    if p.is_file()
                ]
            data = json.dumps(self.__class__.game_files_cache).encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.send_header('Content-Length', str(len(data)))
            self.end_headers()
            self.wfile.write(data)
            return
        super().do_GET()

    def translate_path(self, path):
        clean_path = path.split('?', 1)[0].split('#', 1)[0]
        if self.game_dir and (clean_path.startswith('/game/') or clean_path.startswith('/local/game/')):
            prefix = '/game/' if clean_path.startswith('/game/') else '/local/game/'
            rel_path = clean_path[len(prefix):]
            target = (self.game_dir / rel_path).resolve()
            if self.game_dir in target.parents or target == self.game_dir:
                return str(target)
            return ''
        return super().translate_path(path)

    def list_directory(self, path):
        self.send_error(403, 'Directory listing is disabled')
        return None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--iteration', default='005-unified-driving')
    parser.add_argument('--port', type=int, default=8000)
    parser.add_argument('--game-dir', default='local/game')
    parser.add_argument('--ready-file', type=Path)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    base = (root/'local/builds').resolve()
    site = (base/args.iteration/'web').resolve()
    game_path = (root / args.game_dir).resolve()

    if base not in site.parents or not (site/'index.html').is_file():
        raise SystemExit('Built site not found. Run scripts/build.ps1 first.')

    Handler.game_dir = game_path if game_path.is_dir() else None
    if Handler.game_dir:
        print(f'Game resources: {Handler.game_dir} (read-only)', flush=True)

    server = ThreadingHTTPServer(('127.0.0.1', args.port), partial(Handler, directory=str(site)))
    port = server.server_address[1]
    if args.ready_file:
        args.ready_file.parent.mkdir(parents=True, exist_ok=True)
        ready_tmp = args.ready_file.with_name(args.ready_file.name + '.tmp')
        ready_tmp.write_text(json.dumps({'port': port, 'pid': __import__('os').getpid()}), encoding='utf-8')
        ready_tmp.replace(args.ready_file)
    print(f'Viewer: http://127.0.0.1:{port}/ (Ctrl+C to stop)', flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == '__main__':
    main()
