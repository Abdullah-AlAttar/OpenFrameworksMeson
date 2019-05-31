
# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_EMPTY']

deps_names = ['gstapp-1.0',
        'gstvideo-1.0',
        'gstbase-1.0',
        'gstreamer-1.0',
        'fontconfig',
        'freetype',
        'sndfile',
        'openal',
        'curl',
        'glfw',
        'GLEW',
        'GL',
        'cairo',
        'gobject-2.0',
        'g',
        'mpg123',
        'X11',
        'pthread',
        'freeimage',
        'boost_filesystem',
        'boost_system',
        'pugixml',
        'uriparser',
        'stdc++',
        'm',
        'gcc_s',
        'c',
        'orc-0.4',
        'gmodule-2.0',
        'rt',
        'dl',
        'expat',
        'png16',
        'z',
        'FLAC',
        'ogg',
        'vorbis',
        'vorbisenc',
        'sndio',
        'idn2',
        'ssl',
        'crypto',
        'Xrandr',
        'Xinerama',
        'Xxf86vm',
        'GLX',
        'GLdispatch',
        'pixman-1',
        'xcb-shm',
        'xcb',
        'xcb-render',
        'Xrender',
        'Xext',
        'ffi',
        'pcre',
        'jpeg',
        'tiff',
        'IlmImf',
        'Half',
        'Iex',
        'gnutls',
        'hogweed',
        'nettle',
        'gmp',
        'Xfixes',
        'Xau',
        'Xdmcp',
        'gomp',
        'lzma',
        'jbig',
        'IlmThread',
        'p11-kit',
        'tasn1',
        'sqlite3',
        'crypt']
cmplr = meson.get_compiler('cpp')
deps = []
foreach dep_name : deps_names
  tmp = dependency(dep_name ,required : false)
  if(not tmp.found())
    tmp = cmplr.find_library(dep_name)
  endif
  if(tmp.found())
    deps += tmp
  endif
endforeach

deps += cmplr.find_library('libopenFrameworks', dirs : join_paths(of_path, 'libs/openFrameworksCompiled/lib/linux64'))
deps += cmplr.find_library('tess2', dirs : join_paths(of_path, 'libs/tess2/lib/linux64'))
deps += cmplr.find_library('kiss', dirs : join_paths(of_path, 'libs/kiss/lib/linux64'))


sources = ['ofApp.cpp']
if get_option('ofxGui')

  ofx_gui_path = join_paths(of_path,'addons','ofxGui', 'src')

  sources += [ join_paths(ofx_gui_path, 'ofxBaseGui.cpp'),
                  join_paths(ofx_gui_path, 'ofxButton.cpp'),
                  join_paths(ofx_gui_path, 'ofxColorPicker.cpp'),
                  join_paths(ofx_gui_path, 'ofxGuiGroup.cpp'),
                  join_paths(ofx_gui_path, 'ofxInputField.cpp'),
                  join_paths(ofx_gui_path, 'ofxLabel.cpp'),
                  join_paths(ofx_gui_path, 'ofxPanel.cpp'),
                  join_paths(ofx_gui_path, 'ofxSlider.cpp'),
                  join_paths(ofx_gui_path, 'ofxSliderGroup.cpp'),
                  join_paths(ofx_gui_path, 'ofxToggle.cpp')]
endif

shlib = static_library('ofmeson',
  sources : sources,
  install : true,
  include_directories : includes,
  dependencies : deps,
  cpp_args : lib_args,
)

test_exe = executable('ofmesontest', 'main.cpp',
  include_directories : includes,
  link_with : shlib,
  dependencies : deps)
test('empty', test_exe)

# Make this library usable as a Meson subproject.
of_meson_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)
