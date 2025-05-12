#pragma once

#include "Eigen/Eigen"
#include "Polygon.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;
namespace PolyhedronLibrary{
	class Tetrahedron{
		public:
		vector<Face> faces;
		vector<Edge> edge;
		vector<Vertex> vertices;
		unsigned int nvertices = 4;
		unsigned int nedges = 6;
		unsigned int nfaces = 4;
		unsigned int b,c;
		
		vector<unsigned int> code = {3,3};
		Tetrahedron(){
		vertices.reserve(nvertices);
		edge.reserve(nedges);
		faces.reserve(nfaces);
		vertices = {
		Vertex(1.0,1.0,1.0), 
		Vertex(1.0,-1.0,-1.0), 
		Vertex(-1.0,1.0,-1.0),
		Vertex(-1.0,-1.0,1.0)};
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
		 }
		 edge = {Edge(vertices[0], vertices[1], 0),Edge(vertices[0], vertices[2], 1),
		 		Edge(vertices[0], vertices[3], 2),Edge(vertices[1], vertices[2], 3),
				Edge(vertices[1], vertices[3], 4),Edge(vertices[2], vertices[3], 5)};
		vector<Edge> buff_1 = {edge[0],edge[3],edge[1]}; // v0, v1, v2
		vector<Edge> buff_2 = {edge[5], edge[3], edge[4]}; // v2,v3,v1
		vector<Edge> buff_3 = {edge[1],edge[5], edge[2]}; // v0,v2,v3
		vector<Edge> buff_4 = {edge[0], edge[4], edge[2]}; // v0,v1,v3
		vector<Vertex> buff_v_1 = {vertices[0], vertices[1], vertices[2]};
		vector<Vertex> buff_v_2 = {vertices[2], vertices[3], vertices[1]};
		vector<Vertex> buff_v_3 = {vertices[0], vertices[2], vertices[3]};
		vector<Vertex> buff_v_4 = {vertices[0], vertices[1], vertices[3]};
		faces[0] = Face(buff_v_1, buff_1, 0 , 0);
		faces[1] = Face(buff_v_2, buff_2, 1 , 0);
		faces[2] = Face(buff_v_2, buff_2, 2 , 0);
		faces[3] = Face(buff_v_3, buff_3, 3 , 0);		 		
		}
		Tetrahedron dual(){
			return *this;
		}
		void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << ")" << endl;}
		}
		};
	class Octahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		Octahedron()=default;
	}
	;
	class Cube{
			public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		unsigned int nedges = 12;
		unsigned int nfaces = 8;
		unsigned int nvertices = 8;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		
		Cube(){
		vertices.reserve(nvertices);
		edge.reserve(nedges);
		faces.reserve(nfaces);
		vertices = {
		Vertex(1.0,1.0,1.0), 
		Vertex(1.0,1.0,-1.0), 
		Vertex(1.0,-1.0,1.0),
		Vertex(-1.0,1.0,1.0),
		Vertex(-1.0,-1.0,1.0), 
		Vertex(1.0,-1.0,-1.0), 
		Vertex(-1.0,1.0,-1.0),
		Vertex(-1.0,-1.0,-1.0)				
		};
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
		 }
		edge = {
		Edge(vertices[0], vertices[1],0),
		Edge(vertices[0], vertices[2],1),
		Edge(vertices[0], vertices[3],2),
		Edge(vertices[1], vertices[5],3),
		Edge(vertices[1], vertices[6],4),
		Edge(vertices[2], vertices[5],5),
		Edge(vertices[2], vertices[4],6),
		Edge(vertices[3], vertices[4],7),
		Edge(vertices[3], vertices[6],8),
		Edge(vertices[4], vertices[7],9),
		Edge(vertices[5], vertices[7],10),
		Edge(vertices[6], vertices[7],11)
		};
		//devo aggiungere le facce del cubo
	}
	Octahedron dual(){
			Octahedron c;
			return c;
		}
	void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << ")" << endl;}
		}
	};

	class Dodecahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		Dodecahedron()=default;		
	};	
	class Icosahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		Icosahedron()=default;			
			
	};

}