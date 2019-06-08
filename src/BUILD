cc_binary(
    name = "texgen-cpp",
    srcs = ["main-cpp.cc"],
    deps = [":textures"],
)

cc_binary(
    name = "texgen-bzl",
    srcs = ["main-bzl.cc"],
    visibility = ["//:__pkg__"],
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
