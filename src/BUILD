cc_binary(
    name = "texgen-cpp",
    srcs = ["main-cpp.cc"],
    deps = [":textures"],
)

cc_library(
    name = "textures",
    srcs = glob(
        ["*.cc"],
        exclude = ["main*.cc"],
    ),
    hdrs = glob([
        "*.hh",
        "*.hxx",
    ]),
)
