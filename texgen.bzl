def texgen(name, op, args):
    argPaths = ["$(location {})".format(arg) for arg in args]
    native.genrule(
        name = name,
        outs = [name + ".png"],
        tools = ["//src:texgen-bzl"],
        cmd = "$(location //src:texgen-bzl) $@ {} {}".format(op, " ".join(argPaths)),
        srcs = depset(args).to_list(),
    )
