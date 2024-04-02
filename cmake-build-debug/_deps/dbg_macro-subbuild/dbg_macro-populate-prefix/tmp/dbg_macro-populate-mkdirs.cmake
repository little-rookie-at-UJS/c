# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-src"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-build"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/tmp"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/src/dbg_macro-populate-stamp"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/src"
  "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/src/dbg_macro-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/src/dbg_macro-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/DELLPC/Desktop/code/c++/cmake-build-debug/_deps/dbg_macro-subbuild/dbg_macro-populate-prefix/src/dbg_macro-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
