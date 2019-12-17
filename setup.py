from distutils.core import setup, Extension
setup(name='cmain', version='0.0.1',  \
      ext_modules=[Extension('cmain', ['cmain.c'])])
