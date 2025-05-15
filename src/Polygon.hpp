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
    unsigned int id;
    Vertex() : x(0), y(0), z(0) {}
    Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    Vertex(double _x, double _y, double _z, unsigned int id) : x(_x), y(_y), z(_z), id(id) {}
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    void normalize(){
    	double buff = length();
    	x/=buff;
    	y/=buff;
    	z/=buff;	
	}
/*	Vertex& operator=(const Vertex& other){
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->id = other.id;
		return *this;
	}*/
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
    double length_2d_xy() const{
    	        return sqrt((origin.x - end.x) * (origin.x - end.x) +
                    (origin.y - end.y) * (origin.y - end.y));
	}
	Edge reverseEdge() const{
	return Edge(end, origin, id);
	}


};


class Face {
	public:
    vector<Edge> edges;
    vector<Vertex> vertices;
    unsigned int id, type; 
   	Face()=default; 
    Face(const vector<Vertex>& vec, const vector<Edge>& edg, unsigned int code, unsigned int type) {
	vertices.reserve(vec.size()) ;
	edges.reserve(edg.size());
	 vertices=vec; edges=edg;
	  id=code; 
	  this->type=type;}
	
};
Vertex sphericalToCartesian(double phi, double psi);
Face projectPentagonToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id) ;
Face projectSquareToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id);
Face projectTriangleToSphere(double phi, double psi, double dPhi, double dPsi, int& id, int f_id);
void printFace(Face f) ;
Edge reverseEdge(Edge e);

 }
 