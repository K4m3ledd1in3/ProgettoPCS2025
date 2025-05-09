# src/CMakeLists.txt

# Elenco dei file sorgente (aggiungi altri se ne hai)
set(polygonalMesh_sources
    Polyhedron.cpp
    Cell0D.cpp
    Cell1D.cpp
    Cell2D.cpp
    Cell3D.cpp
    GeodesicBuilder.cpp
)

# Elenco dei file header
set(polygonalMesh_headers
    Polyhedron.hpp
    Cell0D.hpp
    Cell1D.hpp
    Cell2D.hpp
    Cell3D.hpp
    GeodesicBuilder.hpp
)

# Includi la directory corrente come include path
set(polygonalMesh_includes ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

# Esporta anche sources e headers verso il livello superiore
set(polygonalMesh_sources ${polygonalMesh_sources} PARENT_SCOPE)
set(polygonalMesh_headers ${polygonalMesh_headers} PARENT_SCOPE)
