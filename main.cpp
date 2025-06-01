#include <iostream>
#include "UCDUtilities.hpp"
#include "Polyhedron.hpp"
#include "Polygon.hpp"

using namespace Eigen;
using namespace PolygonalLibrary;
using namespace PolyhedronLibrary;
using namespace std;
using namespace Gedim;

int main() {
    unsigned int p, q, b, c;
    cout << "Inserisci p, q, b, c (esempio 3 5 1 0): ";
    cin >> p >> q >> b >> c;

    _Polyhedron pp;

    // Costruisci il poliedro in base a p, q, b, c
    if (p == 3 && q == 3) {
        Tetrahedron t;
        pp = _Polyhedron(t.faces, t.edge, t.vertices, b, c, p, q);
    } else if (p == 4 && q == 3) {
        Cube C;
        pp = _Polyhedron(C.faces, C.edge, C.vertices, b, c, p, q);
    } else if (p == 3 && q == 4) {
        Octahedron o;
        pp = _Polyhedron(o.faces, o.edge, o.vertices, b, c, p, q);
    } else if (p == 5 && q == 3) {
        Dodecahedron d;
        pp = _Polyhedron(d.faces, d.edge, d.vertices, b, c, p, q);
    } else if (p == 3 && q == 5) {
        Icosahedron i;
        pp = _Polyhedron(i.faces, i.edge, i.vertices, b, c, p, q);
    } else {
        cout << "Parametri non validi. Termino.\n";
        return 1;
    }

    pp.OverAll_Triangulation();
    pp.printFaces();  // Stampa facce generate (facoltativo)
    pp.GenerateDual(); // Genera duale (facoltativo)

    // Mostra i vertici generati (per scegliere ID)
    cout << "\nVertici generati:\n";
    for (size_t i = 0; i < pp.vertices.size(); i++) {
        cout << "ID: " << pp.vertices[i].id
             << " - (" << pp.vertices[i].x << ", " << pp.vertices[i].y << ", " << pp.vertices[i].z << ")\n";
    }

    // Input ID vertici per il cammino minimo
    unsigned int id_start, id_end;
    cout << "Inserisci id vertice di partenza: ";
    cin >> id_start;
    cout << "Inserisci id vertice di arrivo: ";
    cin >> id_end;

    // Calcola cammino minimo
    vector<vertex> path = ShortestPath(pp.vertices, pp.edges, id_start, id_end);

    if (!path.empty()) {
        cout << "Cammino minimo trovato:\n";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "ID: " << path[i].id
                 << " (" << path[i].x << ", " << path[i].y << ", " << path[i].z << ")\n";
        }
    } else {
        cout << "Nessun cammino trovato.\n";
    }

    return 0;
}