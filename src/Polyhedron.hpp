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
		faces.resize(nfaces);
		vertices = {
		Vertex(1.0,1.0,1.0 , 0), 
		Vertex(1.0,-1.0,-1.0, 1), 
		Vertex(-1.0,1.0,-1.0, 2),
		Vertex(-1.0,-1.0,1.0, 3)};
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
		faces[2] = Face(buff_v_3, buff_3, 2 , 0);
		faces[3] = Face(buff_v_4, buff_4, 3 , 0);		 		
		}
		Tetrahedron dual(){
			return *this;
		}
		void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << ")" << endl;}
		}
	void printFaces() {
    for(auto face: faces){
		printFace(face);
	}	
	}
		
		};
		class Cube{
			public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		const unsigned int nedges = 12;
		const unsigned int nfaces = 6;
		const unsigned int nvertices = 8;
		const vector<unsigned int> code = {3,4};
		Cube(){
		vertices.reserve(nvertices);
		edge.reserve(nedges);
		faces.resize(nfaces);
		vertices = {
		Vertex(-1.0,-1.0,-1.0,0), 
		Vertex(1.0,-1.0,-1.0,1), 
		Vertex(1.0,1.0,-1.0,2),
		Vertex(-1.0,1.0,-1.0,3),
		Vertex(-1.0,-1.0,1.0,4), 
		Vertex(1.0,-1.0,1.0,5), 
		Vertex(1.0,1.0,1.0,6),
		Vertex(-1.0,1.0,1.0,7)				
		};
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
		 }	 
		edge = {
		Edge(vertices[0], vertices[1],0),
		Edge(vertices[1], vertices[2],1),
		Edge(vertices[2], vertices[3],2),
		Edge(vertices[3], vertices[0],3),
		Edge(vertices[5], vertices[4],4),
		Edge(vertices[6], vertices[5],5),
		Edge(vertices[7], vertices[6],6),
		Edge(vertices[7], vertices[4],7),
		Edge(vertices[4], vertices[0],8),
		Edge(vertices[5], vertices[1],9),
		Edge(vertices[6], vertices[2],10),
		Edge(vertices[7], vertices[3],11)
		};
		vector<Edge> buff_1 ={edge[0], edge[1],edge[2],edge[3]};
		vector<Edge> buff_2 ={edge[4], edge[5], edge[6], edge[7]};
		vector<Edge> buff_3 ={edge[0],edge[9],edge[4],edge[8]};
		vector<Edge> buff_4 ={edge[1],edge[10],edge[5],edge[9]};
		vector<Edge> buff_5 ={edge[2],edge[11],edge[6],edge[10]};
		vector<Edge> buff_6 ={edge[3],edge[8],edge[7],edge[11]};
		vector<Vertex> buff_v_1 = {vertices[0], vertices[1], vertices[2], vertices[3]};
		vector<Vertex> buff_v_2 = {vertices[4], vertices[5], vertices[6], vertices[7]};
		vector<Vertex> buff_v_3 = {vertices[0], vertices[1], vertices[5], vertices[4]};
		vector<Vertex> buff_v_4 = {vertices[1], vertices[2], vertices[6], vertices[5]};
		vector<Vertex> buff_v_5 = {vertices[2], vertices[3], vertices[7], vertices[6]};
		vector<Vertex> buff_v_6 = {vertices[3], vertices[0], vertices[4], vertices[7]};
		faces[0] = Face(buff_v_1, buff_1, 0 , 0);
		faces[1] = Face(buff_v_2, buff_2, 1 , 0);
		faces[2] = Face(buff_v_3, buff_3, 2 , 0);
		faces[3] = Face(buff_v_4, buff_4, 3 , 0);
		faces[4] = Face(buff_v_5, buff_5, 4 , 0);
		faces[5] = Face(buff_v_6, buff_6, 5 , 0);		
	}

	void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
	void printFaces() {
    for(auto face: faces){
		printFace(face);
	}	
	}
	};
		class Octahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		const unsigned int nedges = 12;
		const unsigned int nfaces = 8;
		const unsigned int nvertices = 6;
		unsigned int b,c;
		const vector<unsigned int> code = {4,3};
		Octahedron(){
		vertices.reserve(nvertices);
		edge.reserve(nedges);
		faces.resize(nfaces);
		vertices = {
		Vertex(1.0,0.0,0.0,0), 
		Vertex(-1.0,0.0,0.0,1), 
		Vertex(0.0,1.0,0.0,2),
		Vertex(0.0,-1.0,0.0,3),
		Vertex(0.0,0.0,1.0,4), 
		Vertex(0.0,0.0,-1.0,5), 				
		};	
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
		 }			 
		edge = {
		Edge(vertices[0], vertices[2],0),
		Edge(vertices[0], vertices[3],1),
		Edge(vertices[0], vertices[4],2),
		Edge(vertices[0], vertices[5],3),
		Edge(vertices[1], vertices[2],4),
		Edge(vertices[1], vertices[3],5),
		Edge(vertices[1], vertices[4],6),
		Edge(vertices[1], vertices[5],7),
		Edge(vertices[2], vertices[4],8),
		Edge(vertices[2], vertices[5],9),
		Edge(vertices[3], vertices[4],10),
		Edge(vertices[3], vertices[5],11)
		};	

		vector<Edge> buff_1 ={edge[0], edge[8],edge[2]};
		vector<Edge> buff_2 ={edge[4], edge[6], edge[8]};
		vector<Edge> buff_3 ={edge[5],edge[10],edge[6]};	
		vector<Edge> buff_4 ={edge[1],edge[2],edge[10]};	
		vector<Edge> buff_5 ={edge[3],edge[9],edge[0]};	
		vector<Edge> buff_6 ={edge[9],edge[7],edge[4]};	
		vector<Edge> buff_7 ={edge[7],edge[11],edge[5]};
		vector<Edge> buff_8 ={edge[11],edge[3],edge[1]};		
		
		vector<Vertex> buff_v_1 = {vertices[0], vertices[2], vertices[4]};
		vector<Vertex> buff_v_2 = {vertices[2], vertices[1], vertices[4]};
		vector<Vertex> buff_v_3 = {vertices[1], vertices[3], vertices[4]};
		vector<Vertex> buff_v_4 = {vertices[3], vertices[0], vertices[4]};
		vector<Vertex> buff_v_5 = {vertices[0], vertices[5], vertices[2]};
		vector<Vertex> buff_v_6 = {vertices[2], vertices[5], vertices[1]};
		vector<Vertex> buff_v_7 = {vertices[1], vertices[5], vertices[3]};
		vector<Vertex> buff_v_8 = {vertices[3], vertices[5], vertices[0]};	
			
		faces[0] = Face(buff_v_1, buff_1, 0 , 0);
		faces[1] = Face(buff_v_2, buff_2, 1 , 0);
		faces[2] = Face(buff_v_3, buff_3, 2 , 0);
		faces[3] = Face(buff_v_4, buff_4, 3 , 0);
		faces[4] = Face(buff_v_5, buff_5, 4 , 0);
		faces[5] = Face(buff_v_6, buff_6, 5 , 0);
		faces[6] = Face(buff_v_7, buff_7, 6 , 0);
		faces[7] = Face(buff_v_8, buff_8, 7 , 0);			
		
	}

		void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
		void printFaces() {
    		for(auto face: faces){
		printFace(face);
		}	
		}
		
};
	class Dodecahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		vector<unsigned int> code = {3,4};
		const unsigned int nedges = 30;
		const unsigned int nfaces = 12;
		const unsigned int nvertices = 20;
		Dodecahedron(){
			const double phi = (1.0 + sqrt(5.0)) / 2.0;   
    		const double a = 1.0;
   			const double b = 1.0 / phi;                       
    		const double c = phi;
			vertices.reserve(nvertices);
			edge.reserve(nedges);
			faces.resize(nfaces); 
		vertices = {
 		Vertex(-a, -a, -a), Vertex(-a, -a, a), Vertex(-a, a, -a), Vertex(-a, a, a),
		Vertex(+a, -a, -a), Vertex(a, -a, a), Vertex(a, a, -a), Vertex(a, a, a),
        Vertex( 0, -b, -c), Vertex( 0, -b, c), Vertex( 0, b, -c), Vertex( 0, b, c),
        Vertex(-b, -c, 0), Vertex(-b, c, 0), Vertex(b, -c, 0), Vertex(b, c, 0),
        Vertex(-c, 0, -b), Vertex(c, 0, -b), Vertex(-c, 0, b), Vertex(c, 0, b)
		};
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();

		}
	edge={
	Edge(vertices[0],vertices[8],0), Edge(vertices[0],vertices[12],1), Edge(vertices[0],vertices[16],2),
    Edge(vertices[1],vertices[9],3), Edge(vertices[1], vertices[12],4), Edge(vertices[1], vertices[18],5),
    Edge(vertices[2],vertices[10],6), Edge(vertices[2],vertices[13],7), Edge(vertices[2],vertices[16],8),
    Edge(vertices[3],vertices[11],9), Edge(vertices[3],vertices[13],10), Edge(vertices[3],vertices[15],11),
    Edge(vertices[4],vertices[8],12), Edge(vertices[4],vertices[17],13), Edge(vertices[4],vertices[19],14),
    Edge(vertices[5],vertices[9],15), Edge(vertices[5],vertices[14],16), Edge(vertices[5],vertices[19],17),
    Edge(vertices[6],vertices[10],18), Edge(vertices[6],vertices[13],19), Edge(vertices[6],vertices[17],20),
    Edge(vertices[7],vertices[11],21), Edge(vertices[7],vertices[15],22), Edge(vertices[7],vertices[19],23),
    Edge(vertices[8],vertices[9],24), Edge(vertices[8],vertices[10],25), Edge(vertices[9],vertices[11],26),
    Edge(vertices[10],vertices[11],27), Edge(vertices[11],vertices[13],28), Edge(vertices[9],vertices[13],29),
	Edge(vertices[13],vertices[15],30), Edge(vertices[13],vertices[19],31), Edge(vertices[16],vertices[17],32),
	Edge(vertices[16],vertices[18],33), Edge(vertices[17],vertices[19],34), Edge(vertices[18],vertices[19],35)
	};	
		vector<Edge> buff_1 ={edge[0],edge[12], edge[13],edge[32],edge[2]};
		vector<Edge> buff_2 ={edge[2],edge[8],edge[6],edge[25],edge[0]};
		vector<Edge> buff_3 ={edge[1],edge[4],edge[5],edge[33],edge[2]};	
		vector<Edge> buff_4 ={edge[3],edge[15],edge[17],edge[35],edge[5]};	
		vector<Edge> buff_5 ={edge[4],edge[1],edge[0],edge[24],edge[3]};	
		vector<Edge> buff_6 ={edge[7],edge[10],edge[9],edge[27],edge[6]};	
		vector<Edge> buff_7 ={edge[8],edge[32],edge[20],edge[19],edge[7]};
		vector<Edge> buff_8 ={edge[11],edge[22],edge[21],edge[28],edge[10]};		
		vector<Edge> buff_9 ={edge[12],edge[25],edge[18],edge[20],edge[13]};
		vector<Edge> buff_10 ={edge[15],edge[26],edge[21],edge[23],edge[17]};
		vector<Edge> buff_11 ={edge[18],edge[27],edge[26],edge[29],edge[19]};
		vector<Edge> buff_12 ={edge[22],edge[11],edge[10],edge[31],edge[23]};		
		vector<Vertex> buff_v_1 = {vertices[0], vertices[8], vertices[4], vertices[17], vertices[16]};
		vector<Vertex> buff_v_2 = {vertices[0], vertices[16], vertices[2],vertices[10], vertices[8]};
		vector<Vertex> buff_v_3 = {vertices[0], vertices[12], vertices[1],vertices[18], vertices[16]};
		vector<Vertex> buff_v_4 = {vertices[1], vertices[9], vertices[5],vertices[19], vertices[18]};
		vector<Vertex> buff_v_5 = {vertices[1], vertices[12], vertices[0],vertices[8], vertices[9]};
		vector<Vertex> buff_v_6 = {vertices[2], vertices[13], vertices[3],vertices[11], vertices[10]};
		vector<Vertex> buff_v_7 = {vertices[2], vertices[16], vertices[17],vertices[6], vertices[13]};
		vector<Vertex> buff_v_8 = {vertices[3], vertices[15], vertices[7],vertices[11], vertices[13]};	
		vector<Vertex> buff_v_9 = {vertices[4], vertices[8], vertices[10],vertices[6], vertices[17]};
		vector<Vertex> buff_v_10 = {vertices[5], vertices[9], vertices[11],vertices[7], vertices[19]};
	    vector<Vertex> buff_v_11 = {vertices[6], vertices[10], vertices[11],vertices[9], vertices[13]};		
		vector<Vertex> buff_v_12 = {vertices[7], vertices[15], vertices[3],vertices[13], vertices[19]};
		faces[0] = Face(buff_v_1, buff_1, 0 , 0);
		faces[1] = Face(buff_v_2, buff_2, 1 , 0);
		faces[2] = Face(buff_v_3, buff_3, 2 , 0);
		faces[3] = Face(buff_v_4, buff_4, 3 , 0);
		faces[4] = Face(buff_v_5, buff_5, 4 , 0);
		faces[5] = Face(buff_v_6, buff_6, 5 , 0);
		faces[6] = Face(buff_v_7, buff_7, 6 , 0);
		faces[7] = Face(buff_v_8, buff_8, 7 , 0);
		faces[8] = Face(buff_v_9, buff_9, 8 , 0);
		faces[9] = Face(buff_v_10, buff_10, 9 , 0);
		faces[10] = Face(buff_v_11, buff_11, 10 , 0);
		faces[11] = Face(buff_v_12, buff_12, 11 , 0);
		}
		void display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
		
		void printFaces() {
    		for(auto face: faces){
		printFace(face);
			}	
			}
			
	};	
	class Icosahedron{
		public:
		vector<Face> faces;
		vector <Edge> edge;
		vector <Vertex> vertices;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		Icosahedron(){
			
		};			
			
	};

}