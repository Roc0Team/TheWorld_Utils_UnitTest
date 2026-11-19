cmake_minimum_required(VERSION 3.21)

project(TheWorld_Utils_UnitTest LANGUAGES CXX)

if(NOT WIN32 OR NOT MSVC)
	message(FATAL_ERROR "TheWorld_Utils_UnitTest requires Windows and MSVC.")
endif()

if(NOT DEFINED THEWORLD_EXTERNAL_ROOT)
	set(THEWORLD_EXTERNAL_ROOT "${PROJECT_SOURCE_DIR}/..")
endif()
if(NOT DEFINED THEWORLD_LIB_DIR)
	set(THEWORLD_LIB_DIR "${THEWORLD_EXTERNAL_ROOT}/TheWorld_GDN_Viewer/x64")
endif()

set(_vs_root "$ENV{VSINSTALLDIR}")
if(NOT _vs_root AND CMAKE_VS_INSTALLATION_PREFIX)
	set(_vs_root "${CMAKE_VS_INSTALLATION_PREFIX}")
endif()
if(NOT _vs_root)
	get_filename_component(_vs_root "${CMAKE_CXX_COMPILER}" DIRECTORY)
	foreach(_level RANGE 1 7)
		get_filename_component(_vs_root "${_vs_root}" DIRECTORY)
	endforeach()
endif()
find_path(THEWORLD_VSTEST_INCLUDE_DIR CppUnitTest.h
	HINTS "${_vs_root}/VC/Auxiliary/VS/UnitTest/include"
	REQUIRED)
find_library(THEWORLD_VSTEST_LIBRARY Microsoft.VisualStudio.TestTools.CppUnitTestFramework
	HINTS "${_vs_root}/VC/Auxiliary/VS/UnitTest/lib/x64"
	REQUIRED)
find_program(THEWORLD_VSTEST_EXECUTABLE vstest.console.exe
	HINTS
		"${_vs_root}/Common7/IDE/CommonExtensions/Microsoft/TestWindow"
		"${_vs_root}/Common7/IDE/Extensions/TestPlatform"
	REQUIRED)

if(TARGET TheWorld_Utils)
	set(_utils_link TheWorld_Utils)
else()
	set(_utils_debug "${THEWORLD_LIB_DIR}/TheWorld_Utils_d.lib")
	set(_utils_release "${THEWORLD_LIB_DIR}/TheWorld_Utils.lib")
	foreach(_library IN ITEMS "${_utils_debug}" "${_utils_release}")
		if(NOT EXISTS "${_library}")
			message(FATAL_ERROR "Required TheWorld_Utils library not found: ${_library}")
		endif()
	endforeach()
	set(_utils_link
		"$<$<CONFIG:Debug>:${_utils_debug}>"
		"$<$<CONFIG:Release>:${_utils_release}>")
endif()

add_library(TheWorld_Utils_UnitTest MODULE
	pch.cpp
	TheWorld_Utils_UnitTest.cpp
)
target_include_directories(TheWorld_Utils_UnitTest PRIVATE
	"${THEWORLD_VSTEST_INCLUDE_DIR}"
	"${THEWORLD_EXTERNAL_ROOT}/TheWorld_Utils"
	"${THEWORLD_EXTERNAL_ROOT}/plog/include"
	"${THEWORLD_EXTERNAL_ROOT}/GSL/include"
	"${THEWORLD_EXTERNAL_ROOT}/eigen"
)
target_compile_features(TheWorld_Utils_UnitTest PRIVATE cxx_std_20)
target_compile_definitions(TheWorld_Utils_UnitTest PRIVATE
	UNICODE
	_UNICODE
	"$<$<CONFIG:Debug>:_DEBUG>"
	"$<$<CONFIG:Release>:NDEBUG>"
)
target_link_libraries(TheWorld_Utils_UnitTest PRIVATE
	${_utils_link}
	"${THEWORLD_VSTEST_LIBRARY}"
)

# MSTest headers autolink x64\Microsoft.VisualStudio.TestTools.CppUnitTestFramework.lib.
get_filename_component(_vstest_arch_lib_dir "${THEWORLD_VSTEST_LIBRARY}" DIRECTORY)
get_filename_component(_vstest_lib_dir "${_vstest_arch_lib_dir}" DIRECTORY)
target_link_directories(TheWorld_Utils_UnitTest PRIVATE "${_vstest_lib_dir}")

set_target_properties(TheWorld_Utils_UnitTest PROPERTIES
	CXX_EXTENSIONS OFF
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
	PREFIX ""
	OUTPUT_NAME_DEBUG "TheWorld_Utils_UnitTest_d"
	OUTPUT_NAME_RELEASE "TheWorld_Utils_UnitTest"
	RUNTIME_OUTPUT_DIRECTORY "${THEWORLD_LIB_DIR}/$<0:>"
	LIBRARY_OUTPUT_DIRECTORY "${THEWORLD_LIB_DIR}/$<0:>"
	ARCHIVE_OUTPUT_DIRECTORY "${THEWORLD_LIB_DIR}/$<0:>"
)

enable_testing()
add_test(NAME TheWorld_Utils_UnitTest
	COMMAND "${THEWORLD_VSTEST_EXECUTABLE}"
		"$<TARGET_FILE:TheWorld_Utils_UnitTest>"
		/Platform:x64)
