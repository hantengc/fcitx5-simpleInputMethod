cmake_minimum_required(VERSION 3.11)
project(sogouim)

find_package(PkgConfig)
find_package(Gettext)
pkg_search_module(PKG_X11 x11)
pkg_search_module(PKG_XTST xtst)

if ((NOT PKG_X11_FOUND) OR (NOT PKG_XTST_FOUND))
	message(STATUS "will not build ${PROJECT_NAME}, PKG_X11_FOUND: [${PKG_X11_FOUND}] PKG_XTST_FOUND: [${PKG_XTST_FOUND}]")
	return()
endif()

message(STATUS "x11, xtst FOUND, will build ${PROJECT_NAME}")

find_package(Fcitx5Core REQUIRED)
include("${FCITX_INSTALL_CMAKECONFIG_DIR}/Fcitx5Utils/Fcitx5CompilerSettings.cmake")

add_subdirectory(src)