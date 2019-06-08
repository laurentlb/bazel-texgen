This is an experiment combining Bazel and a texture generator.

The goal is to see how Bazel properties can be useful for procedural texture
generation, in particular the lazy evaluation, the (possibly remote) caching,
and the distributed execution.

## Credits

* The texture generator was created for [Ctrl-Alt-Test demos](http://www.ctrl-alt-test.fr/).
  See also https://github.com/laurentlb/Ctrl-Alt-Test

* The code for handling png files comes from stb. See https://github.com/nothings/stb
