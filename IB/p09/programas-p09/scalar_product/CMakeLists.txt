# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Ricardo David Rodríguez Pane
# @date Nov 10, 2023
# @brief simple CMakeLists.txt
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make

cmake_minimum_required(VERSION 3.0)
project(producto_escalar)

# Agregar los archivos fuente
set(SOURCES src/main.cc src/scalar_product.cc)

# Agregar un ejecutable
add_executable(producto_escalar ${SOURCES})
