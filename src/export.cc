#include "src/interpolation.hxx"
#include "src/stb_image_write.hh"
#include "src/texture.hh"

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
