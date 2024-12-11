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

# Trouver SFML (assurez-vous que SFML est installé sur votre système)
# find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Lier les bibliothèques SFML au projet
# target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

# Définir les chemins d'inclusion si nécessaire (exemple : headers spécifiques)
# target_include_directories(${PROJECT_NAME} PRIVATE include/)
