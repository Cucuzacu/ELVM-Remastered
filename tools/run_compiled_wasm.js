const fs = require('fs');
const wasmBuffer = fs.readFileSync('output.wasm');

const importObject = {
  env: {
    putchar: (char) => {
      process.stdout.write(String.fromCharCode(char));
    },
    getchar: () => {
      const buffer = Buffer.alloc(1);
      const n = fs.readSync(0, buffer, 0, 1);
      return n > 0 ? buffer[0] : -1;
    },
    exit: () => {
      console.log("\n[Program Exited]");
      process.exit();
    }
  }
};

WebAssembly.instantiate(wasmBuffer, importObject)
  .then(wasmModule => {
    wasmModule.instance.exports._start();
  })
  .catch(err => {
    console.error("Execution error:", err);
  });