if get_option('as_d').enabled()
    add_languages('d', native: false, required: true)
endif

if get_option('as_java').enabled()
    add_languages('java', native: false, required: true)
endif

if get_option('as_cython').enabled()
    add_languages('cython', native: false, required: true)
    py3 = import('python').find_installation()
		py3_dep = py3.dependency(required : false)
		
		# Cython extension module
		slib = py3.extension_module(
		    'pizza_test',                      # Python module name
		    ['pizza_test.pyx'] + test_code,
		    dependencies : [py3_dep],
		    install : true,
		)
		
		pydir = meson.current_build_dir()
endif