#pragma once


#include "Eigen/Eigen"
#include <iostream>
#include <vector>
using namespace std;
using namespace Eigen;


namespace PolygonalLibrary{
class Vertex {
	public:
    double x, y, z;
    
    Vertex() : x(0), y(0), z(0) {}
    Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
};
class Edge {
	public:
    Vertex origin;
    Vertex end;
    unsigned int id;

    Edge() = default;
    Edge(const Vertex& start, const Vertex& final, unsigned int code) : origin(start), end(final), id(code) {}

    double length() const {
        return sqrt((origin.x - end.x) * (origin.x - end.x) +
                    (origin.y - end.y) * (origin.y - end.y) +
                    (origin.z - end.z) * (origin.z - end.z));
    }
};
class Face {
	public:
    vector<Edge> edges;
    vector<Vertex> vertices;
    int id, type; 
   	Face()=default; 
    Face(const vector<Vertex>& vec, const vector<Edge>& edg, unsigned int code, unsigned int type) : vertices(vec), edges(edg), id(code), type(type){}
	
};
Vertex sphericalToCartesian(double phi, double psi);
Face projectSquareToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id);
Face projectTriangleToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id);
Face projectPentagonToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id) ;

void printFace(const Face& f) ;

 }
 
 
 
 /*
 
 #include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace Eigen;

struct Vertex {
    double x, y, z;
    
    Vertex() : x(0), y(0), z(0) {}
    Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
};

struct Edge {
    Vertex origin;
    Vertex end;
    unsigned int id;

    Edge() = default;
    Edge(const Vertex& start, const Vertex& final, unsigned int code) : origin(start), end(final), id(code) {}

    double length() const {
        return sqrt((origin.x - end.x) * (origin.x - end.x) +
                    (origin.y - end.y) * (origin.y - end.y) +
                    (origin.z - end.z) * (origin.z - end.z));
    }
};

struct Face {
    vector<Edge> edges;
    vector<Vertex> vertices;
    int id, type; 
};

Vertex sphericalToCartesian(double phi, double psi) {
    return Vertex(
        cos(phi) * sin(psi),
        sin(phi) * sin(psi),
        cos(psi)
    );
}

Face projectTriangleToSphere(double phi, double psi, double dPhi, double dPsi, int& id) {
    Face f;
    vector<Vertex> vertices = {
        sphericalToCartesian(phi, psi),
        sphericalToCartesian(phi + dPhi, psi),
        sphericalToCartesian(phi + dPhi / 2, psi + dPsi)
    };

    f.edges.push_back(Edge(vertices[0], vertices[1], id++));
    f.edges.push_back(Edge(vertices[1], vertices[2], id++));
    f.edges.push_back(Edge(vertices[2], vertices[0], id++));
    
    f.id = id++;
    f.type = 3;
    return f;
}

Face projectSquareToSphere(double phi, double psi, double dPhi, double dPsi, int& id) {
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
    f.id = id++;
    f.type = 4;
    return f;
}

void printFace(const Face& f) {
    cout << "Face ID: " << f.id << ", Type: " << (f.type == 4 ? "Square" : "Triangle") << endl;
    for (const auto& e : f.edges) {
        cout << "Edge ID: " << e.id 
             << " | From: (" << e.origin.x << ", " << e.origin.y << ", " << e.origin.z << ")"
             << " To: (" << e.end.x << ", " << e.end.y << ", " << e.end.z << ")"
             << " Length: " << e.length() << endl;
    }
    cout << endl;
}

int main() {
    int id = 1;
    double phi = M_PI / 4;
    double psi = M_PI / 4;
    double dPhi = M_PI / 6;
    double dPsi = M_PI / 8;

    Face square = projectSquareToSphere(phi, psi, dPhi, dPsi, id);
    printFace(square);

    Face triangle = projectTriangleToSphere(phi, psi, dPhi, dPsi, id);
    printFace(triangle);

    return 0;
} 
 
 */