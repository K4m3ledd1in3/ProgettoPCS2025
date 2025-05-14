#include "Eigen/Eigen"
#include <iostream>
#include "Polygon.hpp"
#include <vector>
using namespace std;
using namespace Eigen;


namespace PolygonalLibrary{

Vertex sphericalToCartesian(double phi, double psi) {
    return Vertex(
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
             << " Length: " << e.length() << " Length2D_XY: " << e.length_2d_xy() << endl;
    }
    cout << endl;
}
}