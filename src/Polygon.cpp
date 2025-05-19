#include "Eigen/Eigen"
#include <iostream>
#include "Polygon.hpp"
#include <vector>
using namespace std;
using namespace Eigen;


namespace PolygonalLibrary{

vertex sphericalToCartesian(double phi, double psi) {
    return vertex(
        cos(phi) * sin(psi),
        sin(phi) * sin(psi),
        cos(psi)
    );
}


void printFace(Face f) {
    cout << "Face ID: " << f.id << endl;

    for (auto e : f.edges) {
        cout << "Edge ID: " << e.id 
             << " | From: (" << e.origin.x << ", " << e.origin.y << ", " << e.origin.z << ")"
             << " To: (" << e.end.x << ", " << e.end.y << ", " << e.end.z << ")"
             << " Length: " << e.length() << endl;
    }
    cout << endl;
}
Edge reverseEdge(Edge e){
	return Edge(e.end, e.origin, e.id);
}

vertex getThirdVertexFromTriangleEdges(const Edge& e0, const Edge& e1) {

    if (e1.origin != e0.origin && e1.origin != e0.end) {
        return e1.origin;
    } else if (e1.end != e0.origin && e1.end != e0.end) {
        return e1.end;
    } else {
        std::cerr << "Error: Cannot determine third vertex from given edges!" << std::endl;
        return vertex(); 
    }
}
}