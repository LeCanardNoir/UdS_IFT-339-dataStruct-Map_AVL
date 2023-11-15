# CMakeList.txt : projet CMake pour map, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (map "main.cpp" "map.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET map PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
