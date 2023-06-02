load("@aspect_rules_js//js:defs.bzl", "js_run_binary")

def kiwic(src, format, out = None, name = None, cpp_copyable = None, cpp_sparse = None, dedup = None, **kwargs):
    """Runs kiwic on a .kiwi file generating a language-specific output.

    Args:
        src: input .kiwi file
        format: one of "binary" (bkiwi), "cpp", "callback-cpp", or "ts"
        out: if provided, override default output filename
    """
    if not name:
        name = "kiwic_" + format + "_" + src
    if not out:
        ext = {
            "binary": ".bkiwi",
            "cpp": ".h",
            "callback-cpp": "-callback.h",
            "js": ".js",
            "skew": ".sk",
            "ts": ".d.ts",
        }[format]
        out = src.replace(".kiwi", ext)

    # js_run_binary runs in the outdir, so we need to prefix locations with ../../../
    # https://github.com/aspect-build/rules_js/pull/108#issuecomment-1132306346
    args = [
        "--schema",
        "../../../$(location {})".format(src),
        "--" + format,
        "../../../$(location {})".format(out),
    ]

    if cpp_copyable:
        args += ["--cpp-copyable", ",".join(cpp_copyable)]
    if cpp_sparse:
        args += ["--cpp-sparse", ",".join(cpp_sparse)]
    if dedup:
        args += ["--js-dedup", ",".join(dedup)]

    js_run_binary(
        name = name,
        tool = "//share/kiwi:kiwic",
        srcs = [src],
        outs = [out],
        args = args,
        **kwargs
    )
