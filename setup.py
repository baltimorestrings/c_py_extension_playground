from distutils.core import setup, Extension
module1 = Extension("cplay.greet",
                    sources = ["src/cplay/greet.c"]
)

setup(ext_modules=[module1])

