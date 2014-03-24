from distutils.core import setup, Extension

fugue_hash_module = Extension('fugue_hash',
                               sources = ['fuguemodule.c',
                                          'fugue.c',
										  'sha3/fugue.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'fugue_hashs',
       version = '1.0',
       description = 'Bindings for fugue proof of work used by Fuguecoin',
       ext_modules = [fugue_hash_module])
