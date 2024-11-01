# enhance-ssr-cpp

A basic cpp example for [Enhance SSR](https://enhance.dev/wasm).

## Build

Prerequisites:
- Install [libextism](https://extism.org/docs/install/)
- Install [libextism-cpp]() (following directions to build/install the cpp libs)

Get the Enhance `.wasm` file in the place the project expects it:

```bash
mkdir -p vendor && \
  cd vendor && \
  curl -L https://github.com/enhance-dev/enhance-ssr-wasm/releases/download/v0.0.4/enhance-ssr.wasm.gz | gunzip > enhance-ssr.wasm
```

You might need to update `CMakeLists.txt` to make the values appropriate for your
platform/compiler.

(Also ensure you have e.g. DYLD_LIBRARY_PATH set to include wherever libextism-cpp was installed, e.g.
`/usr/local/lib`, and wherever you have `jsoncpp`, e.g., `/opt/homebrew/lib`)

```bash
cmake -B build
cmake --build build -j
./build/serve
```

## Demo

Point a browser to `http://localhost:3456` and you'll see the enhanced SSR component!
