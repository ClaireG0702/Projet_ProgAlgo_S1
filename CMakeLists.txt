cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(MyGame)

# Définir la version C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les fichiers source
file(GLOB_RECURSE SOURCES src/*.cpp)

# Indiquer les fichiers au compilateur
add_executable(${PROJECT_NAME} ${SOURCES})
