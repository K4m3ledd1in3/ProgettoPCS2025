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
//


Face projectTriangleToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id) {
    Face f;
    vector<Vertex> vertices = {
        sphericalToCartesian(phi, psi),
        sphericalToCartesian(phi + dPhi, psi),
        sphericalToCartesian(phi + dPhi / 2, psi + dPsi)
    };
    f.edges.push_back(Edge(vertices[0], vertices[1], id++));
    f.edges.push_back(Edge(vertices[1], vertices[2], id++));
    f.edges.push_back(Edge(vertices[2], vertices[0], id++));
    f.id = f_id;
    f.type = 3;
    return f;
}

Face projectSquareToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id) {
    Face f;
    
    vector<Vertex> vertices = {
        sphericalToCartesian(phi, psi),
        sphericalToCartesian(phi + dPhi, psi),
        sphericalToCartesian(phi + dPhi, psi + dPsi),
        sphericalToCartesian(phi, psi + dPsi)
    };

    f.edges.push_back(Edge(vertices[0], vertices[1], id++));
    f.edges.push_back(Edge(vertices[1], vertices[2], id++));
    f.edges.push_back(Edge(vertices[2], vertices[3], id++));
    f.edges.push_back(Edge(vertices[3], vertices[0], id++));
    f.id = f_id;
    f.type = 4;
    return f;
}

Face projectPentagonToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id) {
    Face f;
    const int numVertices = 5;
    vector<Vertex> vertices;
	//vertices.resize(5);
    double radius = sin(dPsi); 
    double centerX = cos(phi) * sin(psi);
    double centerY = sin(phi) * sin(psi);
    double centerZ = cos(psi);
    for (int i = 0; i < numVertices; ++i) {
        double angle = 2 * M_PI * i / numVertices;
        double localPhi = phi + radius * cos(angle) * dPhi;
        double localPsi = psi + radius * sin(angle) * dPsi;
        vertices.push_back(sphericalToCartesian(localPhi, localPsi));
    }
    for (int i = 0; i < numVertices; ++i) {
        f.edges.push_back(Edge(vertices[i], vertices[(i + 1) % numVertices], id++));
    }
    f.id = f_id;
    f.type = 5; 
    return f;
}





//
void printFace(const Face& f) {
    cout << "Face ID: " << f.id << ", Type: ";
    if(f.type==4){
    	cout << "Square" << endl;
    }
    else if(f.type==3){
    	cout << "Triangle" << endl;    	
	}else{
    	cout << "Pentagon" << endl;		
	}
    for (const auto& e : f.edges) {
        cout << "Edge ID: " << e.id 
             << " | From: (" << e.origin.x << ", " << e.origin.y << ", " << e.origin.z << ")"
             << " To: (" << e.end.x << ", " << e.end.y << ", " << e.end.z << ")"
             << " Length: " << e.length() << endl;
    }
    cout << endl;
}

}