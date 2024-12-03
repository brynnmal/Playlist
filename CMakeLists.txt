cmake_minimum_required(VERSION 3.29)
project(PlaylistProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlaylistProject MainDLL.cpp DLL.cpp DLL.hpp DNode.cpp DNode.hpp Playlist.cpp Playlist.hpp Song.cpp Song.hpp)
