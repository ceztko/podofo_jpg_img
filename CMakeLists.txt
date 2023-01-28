
cmake_minimum_required( VERSION 3.1 )

project( podofo_jpg_img )

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( PODOFO_BUILD_LIB_ONLY ON CACHE INTERNAL "" FORCE )
set( PODOFO_SHARED ON CACHE INTERNAL "" FORCE )
add_subdirectory( 3rdparty/podofo )

enable_testing()

add_definitions( -DPODOFO_SHARED )
add_definitions( -Dpodofo_shared_EXPORTS )

set( SRC main.cpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/podofo/src
	${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src/podofo )

link_directories( ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src/podofo )
link_directories( ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src )

add_executable( podofo_jpg_img ${SRC} )

target_link_libraries( podofo_jpg_img podofo_shared )

add_test( NAME podofo_jpg_img
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/podofo_jpg_img
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )

file( COPY ${CMAKE_CURRENT_SOURCE_DIR}/1.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

