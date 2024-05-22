cmake_minimum_required(VERSION 3.21)

project(mxml_example)

include(ExternalProject)

# build mxml
set(mxml_install_dir ${CMAKE_BINARY_DIR}/mxml/inst)
file(MAKE_DIRECTORY ${mxml_install_dir}/include)
ExternalProject_Add(mxml
        SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/mxml
        BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/mxml
        CONFIGURE_COMMAND ./configure --prefix ${mxml_install_dir} --disable-shared --disable-threads
        BUILD_COMMAND     make
)

# add mxml static library
add_library(mxml_static STATIC IMPORTED GLOBAL)
target_include_directories(mxml_static INTERFACE ${mxml_install_dir}/include)
set_target_properties(mxml_static
        PROPERTIES
        IMPORTED_LOCATION ${mxml_install_dir}/lib/libmxml4.a)
add_dependencies(mxml_static mxml)


# example usage of mxml
add_executable(mxml_example)
target_sources(mxml_example PRIVATE main.c)
target_link_libraries(mxml_example PRIVATE mxml_static)
