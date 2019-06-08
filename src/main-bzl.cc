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

Texture::Channel add(int argc, const char* argv[]) {
  Texture::Channel t1 = Load(argv[0]);
  Texture::Channel t2 = Load(argv[1]);
  t1 += t2;
  return t1;
}

Texture::Channel mult(int argc, const char* argv[]) {
  Texture::Channel t1 = Load(argv[0]);
  Texture::Channel t2 = Load(argv[1]);
  t1 *= t2;
  return t1;
}

const struct {
  const char* name;
  fctType callback;
  int arguments;
} allFunctions[] = {
    {"add", add, 2},
    {"conic", conic, 0},
    {"diamond", diamond, 0},
    {"mult", mult, 2},
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
      return 0;
    }
  }

  printf("unknown op `%s`\n", op);
  return 2;
}
