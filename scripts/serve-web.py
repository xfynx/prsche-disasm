"""Serve only the built viewer site on loopback, without uploads or game data."""
import argparse
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path


class Handler(SimpleHTTPRequestHandler):
    extensions_map = {**SimpleHTTPRequestHandler.extensions_map, '.wasm': 'application/wasm', '.js': 'text/javascript'}

    def end_headers(self):
        self.send_header('Cache-Control', 'no-store')
        super().end_headers()

    def list_directory(self, path):
        self.send_error(403, 'Directory listing is disabled')
        return None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--iteration', default='001-car-viewer')
    parser.add_argument('--port', type=int, default=8000)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    base = (root/'local/builds').resolve()
    site = (base/args.iteration/'web').resolve()
    if base not in site.parents or not (site/'index.html').is_file():
        raise SystemExit('Built site not found. Run scripts/build.ps1 first.')
    server = ThreadingHTTPServer(('127.0.0.1', args.port), partial(Handler, directory=str(site)))
    print(f'Viewer: http://127.0.0.1:{args.port}/ (Ctrl+C to stop)', flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == '__main__':
    main()
