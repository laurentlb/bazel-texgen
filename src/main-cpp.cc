#include "src/interpolation.hxx"
#include "src/texture.hh"
#include "src/stb_image_write.hh"

static unsigned char floatToByte(float value)
{
  return (unsigned char)(clamp(value) * 255);
}

void Export(const char* filename, const Texture::Channel & a) {
  const unsigned int size = a.Width() * a.Height();
  char* buffer = (char*) malloc(size);
  for (unsigned int i = 0; i < size; ++i)
    {
      buffer[i] = floatToByte(a[i]);
    }
  stbi_write_png(filename, a.Width(), a.Height(), 1, buffer, 0);
  free(buffer);
}


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
