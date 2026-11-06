"""Shared native/game audit with optional pinned multiobject emulation support.

Keep the existing auditor unchanged: historical batches pin its exact bytes.
"""
import importlib.util
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('supported_game_base',ROOT/'scripts/research/audit-v2-native-game-batch.py')
base=importlib.util.module_from_spec(spec)
spec.loader.exec_module(base)
legacy_emulated=base.audit_emulated
legacy_audit=base.audit
active_config=None

def audit_emulated(item,cache,sha):
    cfg=cache.document(ROOT/item['config'])
    if not cfg.get('support_sources'):
        return legacy_emulated(item,cache,sha)
    assert active_config is not None,'supported emulation needs a game integration config'
    game=cache.document(active_config)
    build_cfg=cache.document(ROOT/game['build_config'])
    build=cache.document(ROOT/build_cfg['run']/('build-'+game['build_attempt']+'.json'))
    # Canonical comparison inputs must be the actual current game compiler inputs.
    base.ManifestReader(ROOT).verify(build,'source',expected_hash_mode='crlf-to-lf')
    sources=set(build['compiled_source_roots'])
    expected={row['source'] for row in cfg['support_sources']}
    expected.add((ROOT/item['config']).parent.joinpath(cfg['source']).relative_to(ROOT).as_posix())
    assert expected<=sources,('emulated providers absent from game roots',expected-sources)
    from v2_supported_emulation import audit_supported_emulation
    return audit_supported_emulation(base,item,cache,sha)


def audit(config_path):
    global active_config
    assert active_config is None
    active_config=Path(config_path).resolve()
    try:return legacy_audit(config_path)
    finally:active_config=None

base.audit_emulated=audit_emulated
base.audit=audit
if __name__=='__main__':
    base.main()
