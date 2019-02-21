prebuilt_cxx_library(
  name = 'to_string',
  header_only = True,
  header_namespace = '',
  exported_headers = [
    'to_string.hpp',
  ],
  licenses = [
    'LICENSE',
  ], 
  visibility = [
    'PUBLIC',
  ],
)

cxx_binary(
  name = 'main',
  srcs = [
    'main.cpp',
  ],
  deps = [
    ':to_string',
  ],
)