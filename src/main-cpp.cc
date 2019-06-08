#include "src/export.hh"
#include "src/texture.hh"

int main() {
  const int size = 4 * 1024;

  Texture::Channel t1(size, size);
  t1.Diamond();

  Texture::Channel t2(size, size);
  t2.Conic();

  t2 *= t1;

  Export("foo.png", t2);
  return 0;
}
