#[cfg(not(target_arch = "wasm32"))]
fn main() {
    if let Err(error) = porsche_viewer::native::run_cli(std::env::args().skip(1)) {
        eprintln!("{error}");
        std::process::exit(1);
    }
}

#[cfg(target_arch = "wasm32")]
fn main() {}
