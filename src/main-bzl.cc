#include <stdio.h>
#include <string.h>

#include "src/export.hh"
#include "src/texture.hh"

typedef Texture::Channel (*fctType)(int argc, const char* argv[]);

const int size = 4 * 1024;

Texture::Channel diamond(int argc, const char* argv[]) {
  Texture::Channel t(size, size);
  t.Diamond();
  return t;
}

Texture::Channel conic(int argc, const char* argv[]) {
  Texture::Channel t(size, size);
  t.Conic();
  return t;
}

const struct {
  const char* name;
  fctType callback;
  int arguments;
} allFunctions[] = {
    {"diamond", diamond, 0},
    {"conic", conic, 0},
};

int main(int argc, const char* argv[]) {
  if (argc < 3) {
    printf("usage: %s output.png op args...\n", argv[0]);
    return 1;
  }

  const char* output = argv[1];
  const char* op = argv[2];
  int remainingArgc = argc - 3;
  const char** remainingArgv = argv + 3;

  for (int i = 0; i < sizeof(allFunctions) / sizeof(allFunctions[0]); i++) {
    const auto& function = allFunctions[i];
    if (strcmp(argv[2], function.name) == 0) {
      if (remainingArgc != function.arguments) {
        printf("op `%s` expected %d args, got %d\n", op, function.arguments,
               remainingArgc);
        return 1;
      }
      Texture::Channel t = function.callback(remainingArgc, remainingArgv);
      Export(output, t);
    }
  }

  printf("unknown op `%s`\n", op);
  return 2;
}
