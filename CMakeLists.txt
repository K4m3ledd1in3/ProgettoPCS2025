cmake_minimum_required(VERSION 3.9)

project(PolygonalMesh LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.9)
project(PolygonalMesh VERSION 1.0.0 LANGUAGES CXX)

# C++20 obbligatorio
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Avvisi in debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# Compatibilità Windows
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif()

# Dependencies
################################################################################

# Eigen (per vettori, matrici, ecc.)
find_package(Eigen3 CONFIG REQUIRED)
set(POLYGONALMESH_LIBS Eigen3::Eigen)

# Thread
find_package(Threads REQUIRED)
list(APPEND POLYGONALMESH_LIBS Threads::Threads)

# Google Test
find_package(GTest REQUIRED)
list(APPEND POLYGONALMESH_LIBS
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
)

# Struttura progetto
################################################################################

# Sorgenti logici e modulo ParaView exporter
add_subdirectory(src)
add_subdirectory(ExportParaview)
add_subdirectory(PolygonalMesh)

# Includi tutti i file raccolti dalle sottodirectory
add_executable(${PROJECT_NAME}
    main.cpp
    ${polygonalMesh_sources}
    ${polygonalMesh_headers}
    ${src_paraview_sources}
    ${src_paraview_headers}
)

# Include directories (headers locali)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${polygonalMesh_includes}
        ${src_paraview_includes}
)

# Link alle librerie
target_link_libraries(${PROJECT_NAME} PRIVATE ${POLYGONALMESH_LIBS})

# Opzioni per librerie condivise (utile con ParaView)
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)

# Copia automatica dei file di input (se previsti)
file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMesh/Cell0Ds.csv
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMesh/Cell1Ds.csv
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMesh/Cell2Ds.csv
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

# Target per i test
enable_testing()

add_executable(${PROJECT_NAME}_tests
    test/main_test.cpp
    ${polygonalMesh_test_sources}
)

target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${POLYGONALMESH_LIBS})
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${polygonalMesh_includes})
add_test(NAME PolygonalMeshTests COMMAND ${PROJECT_NAME}_tests)
