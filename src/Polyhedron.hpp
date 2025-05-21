#pragma once

#include "Eigen/Eigen"
#include "Polygon.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;
namespace PolyhedronLibrary{
	class Tetrahedron{
		public:
		vector<Face> faces;
		vector<Edge> edge;
		vector<vertex> vertices;
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
		vertex(1.0,1.0,1.0 , 0), 
		vertex(1.0,-1.0,-1.0, 1), 
		vertex(-1.0,1.0,-1.0, 2),
		vertex(-1.0,-1.0,1.0, 3)};
		for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
		 }
		 edge = {Edge(vertices[0], vertices[1], 0),Edge(vertices[0], vertices[2], 1),
		 		Edge(vertices[0], vertices[3], 2),Edge(vertices[1], vertices[2], 3),
				Edge(vertices[1], vertices[3], 4),Edge(vertices[2], vertices[3], 5)};
		vector<Edge> buff_1 = {edge[0],edge[3],reverseEdge(edge[1])}; // v0, v1, v2
		vector<Edge> buff_2 = {edge[3], edge[5], reverseEdge(edge[4])}; // v2,v3,v1
		vector<Edge> buff_3 = {edge[1],edge[5], reverseEdge(edge[2])}; // v0,v2,v3
		vector<Edge> buff_4 = {edge[0], edge[4], reverseEdge(edge[2])}; // v0,v1,v3
		vector<vertex> buff_v_1 = {vertices[0], vertices[1], vertices[2]};
		vector<vertex> buff_v_2 = {vertices[1], vertices[2], vertices[3]};
		vector<vertex> buff_v_3 = {vertices[0], vertices[2], vertices[3]};
		vector<vertex> buff_v_4 = {vertices[0], vertices[1], vertices[3]};
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
		vector <vertex> vertices;
		const unsigned int nedges = 12;
		const unsigned int nfaces = 6;
		const unsigned int nvertices = 8;
		const vector<unsigned int> code = {3,4};
Cube() {
    vertices.reserve(nvertices);
    edge.reserve(nedges);
    faces.resize(nfaces);

    vertices = {
        vertex(-1.0,-1.0,-1.0,0), // v0
        vertex( 1.0,-1.0,-1.0,1), // v1
        vertex( 1.0, 1.0,-1.0,2), // v2
        vertex(-1.0, 1.0,-1.0,3), // v3
        vertex(-1.0,-1.0, 1.0,4), // v4
        vertex( 1.0,-1.0, 1.0,5), // v5
        vertex( 1.0, 1.0, 1.0,6), // v6
        vertex(-1.0, 1.0, 1.0,7)  // v7
    };

    for (size_t i = 0; i < nvertices; i++) {
        vertices[i].normalize();
    }

    edge = {
        Edge(vertices[0], vertices[1], 0),  
        Edge(vertices[1], vertices[2], 1),
        Edge(vertices[2], vertices[3], 2),
        Edge(vertices[3], vertices[0], 3),

        Edge(vertices[4], vertices[5], 4), 
        Edge(vertices[5], vertices[6], 5),
        Edge(vertices[6], vertices[7], 6),
        Edge(vertices[7], vertices[4], 7),

        Edge(vertices[0], vertices[4], 8),  
        Edge(vertices[1], vertices[5], 9),
        Edge(vertices[2], vertices[6], 10),
        Edge(vertices[3], vertices[7], 11)
    };

    vector<Edge> buff_1 = {edge[0], edge[1], edge[2], edge[3]}; 
    vector<Edge> buff_2 = {edge[4], edge[5], edge[6], edge[7]}; 
    vector<Edge> buff_3 = {edge[0], edge[9], reverseEdge(edge[4]), reverseEdge(edge[8])};
    vector<Edge> buff_4 = {edge[1], edge[10], reverseEdge(edge[5]), reverseEdge(edge[9])}; 
    vector<Edge> buff_5 = {edge[2], edge[11], reverseEdge(edge[6]), reverseEdge(edge[10])};
    vector<Edge> buff_6 = {edge[3], edge[8], reverseEdge(edge[7]), reverseEdge(edge[11])};

    vector<vertex> buff_v_1 = {vertices[0], vertices[1], vertices[2], vertices[3]};
    vector<vertex> buff_v_2 = {vertices[4], vertices[5], vertices[6], vertices[7]};
    vector<vertex> buff_v_3 = {vertices[0], vertices[1], vertices[5], vertices[4]};
    vector<vertex> buff_v_4 = {vertices[1], vertices[2], vertices[6], vertices[5]};
    vector<vertex> buff_v_5 = {vertices[2], vertices[3], vertices[7], vertices[6]};
    vector<vertex> buff_v_6 = {vertices[3], vertices[0], vertices[4], vertices[7]};

    faces[0] = Face(buff_v_1, buff_1, 0, 0);
    faces[1] = Face(buff_v_2, buff_2, 1, 0);
    faces[2] = Face(buff_v_3, buff_3, 2, 0);
    faces[3] = Face(buff_v_4, buff_4, 3, 0);
    faces[4] = Face(buff_v_5, buff_5, 4, 0);
    faces[5] = Face(buff_v_6, buff_6, 5, 0);
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
		vector <vertex> vertices;
		const unsigned int nedges = 12;
		const unsigned int nfaces = 8;
		const unsigned int nvertices = 6;
		unsigned int b,c;
		const vector<unsigned int> code = {4,3};
	Octahedron() {
    vertices.reserve(nvertices);
    edge.reserve(nedges);
    faces.resize(nfaces);

    vertices = {
        vertex(1.0, 0.0, 0.0, 0), // v0
        vertex(-1.0, 0.0, 0.0, 1), // v1
        vertex(0.0, 1.0, 0.0, 2), // v2
        vertex(0.0, -1.0, 0.0, 3), // v3
        vertex(0.0, 0.0, 1.0, 4), // v4 
        vertex(0.0, 0.0, -1.0, 5)  // v5 
    };

    for (size_t i = 0; i < nvertices; ++i) {
        vertices[i].normalize();
    }

    edge = {
        Edge(vertices[0], vertices[2], 0),   // v0 -> v2
        Edge(vertices[0], vertices[3], 1),   // v0 -> v3
        Edge(vertices[0], vertices[4], 2),   // v0 -> v4
        Edge(vertices[0], vertices[5], 3),   // v0 -> v5
        Edge(vertices[1], vertices[2], 4),   // v1 -> v2
        Edge(vertices[1], vertices[3], 5),   // v1 -> v3
        Edge(vertices[1], vertices[4], 6),   // v1 -> v4
        Edge(vertices[1], vertices[5], 7),   // v1 -> v5
        Edge(vertices[2], vertices[4], 8),   // v2 -> v4
        Edge(vertices[2], vertices[5], 9),   // v2 -> v5
        Edge(vertices[3], vertices[4],10),   // v3 -> v4
        Edge(vertices[3], vertices[5],11)    // v3 -> v5
    };

 
    /*faces[0] = Face(
        {vertices[0], vertices[2], vertices[4]},
        {edge[0], edge[8], reverseEdge(edge[2])},
        0, 0
    );

    faces[1] = Face(
        {vertices[2], vertices[1], vertices[4]},
        {reverseEdge(edge[4]), edge[6], reverseEdge(edge[8])},
        1, 0
    );

    faces[2] = Face(
        {vertices[1], vertices[3], vertices[4]},
        {edge[5], edge[10], reverseEdge(edge[6])},
        2, 0
    );

    faces[3] = Face(
        {vertices[3], vertices[0], vertices[4]},
        {reverseEdge(edge[1]), edge[2], reverseEdge(edge[10])},
        3, 0
    );

    faces[4] = Face(
        {vertices[0], vertices[5], vertices[2]},
        {edge[3], reverseEdge(edge[9]), reverseEdge(edge[0])},
        4, 0
    );

    faces[5] = Face(
        {vertices[2], vertices[5], vertices[1]},
        {edge[9], edge[7], edge[4]},
        5, 0
    );

    faces[6] = Face(
        {vertices[1], vertices[5], vertices[3]},
        {reverseEdge(edge[7]), (edge[5]), edge[11]},
        6, 0
    );

    faces[7] = Face(
        {vertices[3], vertices[5], vertices[0]},
        {reverseEdge(edge[11]),reverseEdge(edge[1]) , (edge[3])},
        7, 0
    );*/

faces[0] = Face(  
    {vertices[0], vertices[2], vertices[4]},
    {edge[0], edge[8], reverseEdge(edge[2])},
    0, 0
);

faces[1] = Face(  
    {vertices[2], vertices[1], vertices[4]},
    {edge[4], edge[6], reverseEdge(edge[8])},
    1, 0
);

faces[2] = Face(  
    {vertices[1], vertices[3], vertices[4]},
    {edge[5], edge[10], reverseEdge(edge[6])},
    2, 0
);

faces[3] = Face(  
    {vertices[3], vertices[0], vertices[4]},
    {edge[1], edge[2], reverseEdge(edge[10])},
    3, 0
);


faces[4] = Face(  
    {vertices[2], vertices[0], vertices[5]},
    {reverseEdge(edge[0]), edge[3], edge[9]},
    4, 0
);

faces[5] = Face( 
    {vertices[1], vertices[2], vertices[5]},
    {reverseEdge(edge[4]), reverseEdge(edge[9]), edge[7]},
    5, 0
);

faces[6] = Face( 
    {vertices[3], vertices[1], vertices[5]},
    {reverseEdge(edge[5]), reverseEdge(edge[7]), edge[11]},
    6, 0
);

faces[7] = Face(  
    {vertices[0], vertices[3], vertices[5]},
    {reverseEdge(edge[1]), reverseEdge(edge[11]), reverseEdge(edge[3])},
    7, 0
);

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
		vector <vertex> vertices;
		vector<unsigned int> code = {3,4};
		const unsigned int nedges = 30;
		const unsigned int nfaces = 12;
		const unsigned int nvertices = 20;
/*		Dodecahedron() {
    		const double c = (1.0 + sqrt(5.0)) / 2.0;
    		const double a = 1.0;
    		const double b = 1.0 / c;


    vertices.reserve(nvertices);
    edge.reserve(nedges);
    faces.resize(nfaces);
    vertices = {
        vertex(-a, -a, -a), vertex(-a, -a,  a), vertex(-a,  a, -a), vertex(-a,  a,  a),
        vertex( a, -a, -a), vertex( a, -a,  a), vertex( a,  a, -a), vertex( a,  a,  a),
        vertex( 0, -b, -c), vertex( 0, -b,  c), vertex( 0,  b, -c), vertex( 0,  b,  c),
        vertex(-b, -c, 0), vertex(-b,  c, 0), vertex( b, -c, 0), vertex( b,  c, 0),
        vertex(-c, 0, -b), vertex( c, 0, -b), vertex(-c, 0,  b), vertex( c, 0,  b)
    };

    for (size_t i = 0; i < nvertices; ++i) {
        vertices[i].normalize();
    }

    edge = {
    Edge(vertices[0], vertices[8],  0),  Edge(vertices[8], vertices[4],  1),  Edge(vertices[4], vertices[17], 2),
    Edge(vertices[17], vertices[6], 3),  Edge(vertices[6], vertices[10], 4), Edge(vertices[10], vertices[2], 5),
    Edge(vertices[2], vertices[16], 6),  Edge(vertices[16], vertices[0], 7), Edge(vertices[0], vertices[12], 8),
    Edge(vertices[12], vertices[1], 9),  Edge(vertices[1], vertices[18], 10), Edge(vertices[18], vertices[16], 11),
    Edge(vertices[1], vertices[9], 12),  Edge(vertices[9], vertices[5], 13), Edge(vertices[5], vertices[14], 14),
    Edge(vertices[14], vertices[4], 15), Edge(vertices[5], vertices[19], 16), Edge(vertices[19], vertices[14], 17),
    Edge(vertices[15], vertices[7], 18), Edge(vertices[15], vertices[6], 19), Edge(vertices[15], vertices[7], 20),
    Edge(vertices[7], vertices[19], 21), Edge(vertices[7], vertices[11], 22), Edge(vertices[11], vertices[3], 23),
    Edge(vertices[3], vertices[13], 24), Edge(vertices[13], vertices[2], 25), Edge(vertices[3], vertices[1], 26),
    Edge(vertices[3], vertices[11], 27), Edge(vertices[11], vertices[19], 28), Edge(vertices[13], vertices[16], 29)
};

faces[0] = Face(
    { vertices[0], vertices[8], vertices[4], vertices[17], vertices[6] },
    { edge[0], edge[1], edge[2], edge[3], edge[4] }, 0, 0
);

faces[1] = Face(
    { vertices[6], vertices[10], vertices[2], vertices[16], vertices[17] },
    { edge[4], edge[5], edge[6], edge[7], reverseEdge(edge[3]) }, 1, 0
);

faces[2] = Face(
    { vertices[16], vertices[0], vertices[12], vertices[1], vertices[18] },
    { edge[7], edge[8], edge[9], edge[10], reverseEdge(edge[6]) }, 2, 0
);

faces[3] = Face(
    { vertices[18], vertices[16], vertices[0], vertices[12], vertices[1] },
    { reverseEdge(edge[10]), edge[11], reverseEdge(edge[7]), reverseEdge(edge[8]), edge[12] }, 3, 0
);

faces[4] = Face(
    { vertices[4], vertices[14], vertices[5], vertices[9], vertices[1] },
    { reverseEdge(edge[1]), edge[15], edge[14], reverseEdge(edge[13]), reverseEdge(edge[12]) }, 4, 0
);

faces[5] = Face(
    { vertices[9], vertices[5], vertices[19], vertices[14], vertices[4] },
    { edge[13], edge[16], edge[17], reverseEdge(edge[15]), reverseEdge(edge[14]) }, 5, 0
);

faces[6] = Face(
    { vertices[14], vertices[15], vertices[6], vertices[4] },
    { edge[17], edge[18], edge[19], reverseEdge(edge[2]) }, 6, 0
);

faces[7] = Face(
    { vertices[15], vertices[7], vertices[19], vertices[5], vertices[14] },
    { edge[18], edge[20], edge[21], reverseEdge(edge[16]), reverseEdge(edge[17]) }, 7, 0
);

faces[8] = Face(
    { vertices[19], vertices[11], vertices[7], vertices[15], vertices[14] },
    { edge[21], edge[28], edge[27], reverseEdge(edge[20]), (edge[18]) }, 8, 0
);

faces[9] = Face(
    { vertices[11], vertices[3], vertices[13], vertices[2], vertices[10] },
    { edge[27], edge[23], edge[24], edge[25], reverseEdge(edge[28]) }, 9, 0
);

faces[10] = Face(
    { vertices[2], vertices[16], vertices[10], vertices[6], vertices[13] },
    { edge[25], reverseEdge(edge[6]), reverseEdge(edge[5]), reverseEdge(edge[4]), reverseEdge(edge[24]) }, 10, 0
);

faces[11] = Face(
    { vertices[3], vertices[1], vertices[12], vertices[0], vertices[16] },
    { reverseEdge(edge[23]), edge[26], reverseEdge(edge[9]), reverseEdge(edge[8]), reverseEdge(edge[11]) }, 11, 0
);

}*/

Dodecahedron() {
    const double C0 = (1.0 + sqrt(5.0)) / 4.0;
    const double C1 = (3.0 + sqrt(5.0)) / 4.0;

    vertices.reserve(20);
    edge.reserve(30);
    faces.resize(12);

    vertices = {
        vertex( 0.0,  0.5,   C1), // V0
        vertex( 0.0,  0.5,  -C1), // V1
        vertex( 0.0, -0.5,   C1), // V2
        vertex( 0.0, -0.5,  -C1), // V3
        vertex(  C1,  0.0,  0.5), // V4
        vertex(  C1,  0.0, -0.5), // V5
        vertex( -C1,  0.0,  0.5), // V6
        vertex( -C1,  0.0, -0.5), // V7
        vertex( 0.5,   C1,  0.0), // V8
        vertex( 0.5,  -C1,  0.0), // V9
        vertex(-0.5,   C1,  0.0), // V10
        vertex(-0.5,  -C1,  0.0), // V11
        vertex(  C0,   C0,   C0), // V12
        vertex(  C0,   C0,  -C0), // V13
        vertex(  C0,  -C0,   C0), // V14
        vertex(  C0,  -C0,  -C0), // V15
        vertex( -C0,   C0,   C0), // V16
        vertex( -C0,   C0,  -C0), // V17
        vertex( -C0,  -C0,   C0), // V18
        vertex( -C0,  -C0,  -C0)  // V19
    };
    for (auto& v : vertices) {
        v.normalize();
    }
    using E = Edge;
    auto e = [&](int from, int to, int id) {
        return E(vertices[from], vertices[to], id);
    };
    edge = {
        e(0, 2, 0),   e(2, 14, 1),  e(14, 4, 2),   e(4, 12, 3),   e(12, 0, 4),
        e(0, 12, 5),  e(12, 8, 6),  e(8, 10, 7),   e(10, 16, 8),  e(16, 0, 9),
        e(0, 16, 10), e(16, 6, 11), e(6, 18, 12),  e(18, 2, 13),  e(2, 0, 14),
        e(7, 6, 15),  e(6, 16, 16), e(16, 10, 17), e(10, 17, 18), e(17, 7, 19),
        e(7, 17, 20), e(17, 1, 21), e(1, 3, 22),   e(3, 19, 23),  e(19, 7, 24),
        e(7, 19, 25), e(19, 11, 26),e(11, 18, 27), e(18, 6, 28),  e(6, 7, 29)
    };
    
    auto re = [](Edge& ed) -> Edge {
        return reverseEdge(ed);
    };
    faces[0] = Face({vertices[0], vertices[2], vertices[14], vertices[4], vertices[12]},
                    {edge[0], edge[1], edge[2], edge[3], edge[4]}, 0, 0);
    faces[1] = Face({vertices[0], vertices[12], vertices[8], vertices[10], vertices[16]},
                    {edge[5], edge[6], edge[7], edge[8], edge[9]}, 1, 0);
    faces[2] = Face({vertices[0], vertices[16], vertices[6], vertices[18], vertices[2]},
                    {edge[10], edge[11], edge[12], edge[13], edge[14]}, 2, 0);       
    faces[3] = Face({vertices[7], vertices[6], vertices[16], vertices[10], vertices[17]},
                    {edge[15], re(edge[11]), re(edge[8]), edge[18], edge[19]}, 3, 0);
    faces[4] = Face({vertices[7], vertices[17], vertices[1], vertices[3], vertices[19]},
                    {edge[20], edge[21], edge[22], edge[23], edge[24]}, 4, 0);

    faces[5] = Face({vertices[7], vertices[19], vertices[11], vertices[18], vertices[6]},
                    {edge[25], edge[26], edge[27], re(edge[12]), re(edge[15])}, 5, 0);


    Edge e30 = e(9,11,30);
    Edge e31 = e(11,19,31);
    Edge e32 = e(19,3,32);
    Edge e33 = e(3,15,33);
    Edge e34 = e(15,9,34);
    faces[6] = Face({vertices[9], vertices[11], vertices[19], vertices[3], vertices[15]},
                    {e30, e31, e32, e33, e34}, 6, 0);

    Edge e35 = e(9,15,35);
    Edge e36 = e(15,5,36);
    Edge e37 = e(5,4,37);
    Edge e38 = e(4,14,38);
    Edge e39 = e(14,9,39);
    faces[7] = Face({vertices[9], vertices[15], vertices[5], vertices[4], vertices[14]},
                    {e35, e36, e37, e38, e39}, 7, 0);

    faces[8] = Face({vertices[9], vertices[14], vertices[2], vertices[18], vertices[11]},
                    {re(e39), re(edge[1]), re(edge[13]), re(edge[27]), re(e30)}, 8, 0);

    Edge e41 = e(13,1,41);
    faces[9] = Face({vertices[13], vertices[1], vertices[17], vertices[10], vertices[8]},
                    {e41, re(edge[21]), re(edge[18]), re(edge[7]), re(edge[6])}, 9, 0);

    Edge e42 = e(13,8,42);
    faces[10] = Face({vertices[13], vertices[8], vertices[12], vertices[4], vertices[5]},
                     {e42, edge[6], re(edge[3]), re(edge[2]), re(e37)}, 10, 0);

    faces[11] = Face({vertices[13], vertices[5], vertices[15], vertices[3], vertices[1]},
                     {re(e41), re(e36), re(e33), re(edge[22]), re(edge[21])}, 11, 0);
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
		vector <vertex> vertices;
		unsigned int b,c;
		vector<unsigned int> code = {3,4};
		const unsigned int nedges = 30;
		const unsigned int nfaces = 20;
		const unsigned int nvertices = 12;
		Icosahedron(){
			const double phi = (1.0 + sqrt(5.0)) / 2.0;   
			vertices.reserve(nvertices);
			edge.reserve(nedges);
			faces.resize(nfaces); 
			vertices = {
 					vertex(-1.0, phi, 0.0),
					vertex(1.0, phi, 0.0),
					vertex(-1.0, -phi, 0.0),
					vertex(1.0, -phi, 0.0),
					vertex(0.0, -1.0, phi),
					vertex(0.0, 1.0, phi),
					vertex(0.0, -1.0, -phi),
 					vertex(0.0, 1.0, -phi),
					vertex(phi, 0.0, -1.0),
					vertex(phi, 0.0, 1.0),
					vertex(-phi, 0.0, -1.0),
					vertex(-phi, 0.0, 1.0),	
		};
			for(size_t i = 0; i<nvertices; i++){
		 	vertices[i].normalize();
			}
        edge = {
            Edge(vertices[0], vertices[1], 0),  Edge(vertices[0], vertices[5], 1),  Edge(vertices[0], vertices[7], 2),  Edge(vertices[0], vertices[10], 3), Edge(vertices[0], vertices[11], 4),
            Edge(vertices[1], vertices[5], 5),  Edge(vertices[1], vertices[7], 6),  Edge(vertices[1], vertices[8], 7),  Edge(vertices[1], vertices[9], 8),
            Edge(vertices[2], vertices[3], 9),  Edge(vertices[2], vertices[4], 10), Edge(vertices[2], vertices[6], 11), Edge(vertices[2], vertices[10], 12), Edge(vertices[2], vertices[11], 13),
            Edge(vertices[3], vertices[4], 14), Edge(vertices[3], vertices[6], 15), Edge(vertices[3], vertices[8], 16), Edge(vertices[3], vertices[9], 17),
            Edge(vertices[4], vertices[5], 18), Edge(vertices[4], vertices[9], 19), Edge(vertices[5], vertices[9], 20), Edge(vertices[6], vertices[7], 21),
            Edge(vertices[6], vertices[8], 22), Edge(vertices[6], vertices[10], 23), Edge(vertices[7], vertices[8], 24), Edge(vertices[7], vertices[10], 25),
            Edge(vertices[8], vertices[9], 26), Edge(vertices[10], vertices[11], 27), Edge(vertices[11], vertices[4], 28), Edge(vertices[11], vertices[5], 29)
        };
        vector<Edge> b0  = { edge[4], edge[29], reverseEdge(edge[1]) };
        vector<vertex> v0 = { vertices[0], vertices[11], vertices[5] };
        faces[0] = Face(v0, b0 , 0, 0);
        vector<Edge> b1  = { edge[1], reverseEdge(edge[5]), reverseEdge(edge[0]) };
        vector<vertex> v1 = { vertices[0], vertices[5], vertices[1] };
        faces[1] = Face(v1, b1 , 1, 0);
        vector<Edge> b2  = { edge[0], edge[6], reverseEdge(edge[2]) };
        vector<vertex> v2 = { vertices[0], vertices[1], vertices[7] };
        faces[2] = Face(v2, b2 , 2, 0);
        vector<Edge> b3  = { edge[2], edge[25], reverseEdge(edge[3]) };
        vector<vertex> v3 = { vertices[0], vertices[7], vertices[10] };
        faces[3] = Face(v3, b3 , 3, 0);
        //vector<Edge> b4  = { edge[3], reverseEdge(edge[12]), reverseEdge(edge[4]) };
        /*vector<Edge> b4  = { edge[3], reverseEdge(edge[12]), edge[4] };
		vector<vertex> v4 = { vertices[0], vertices[10], vertices[11] };*/
		vector<Edge> b4  = { edge[3], edge[27], reverseEdge(edge[4]) };
		vector<vertex> v4 = { vertices[0], vertices[10], vertices[11] };
		
        faces[4] = Face(v4, b4 , 4, 0);
        //vector<Edge> b5  = { edge[5], (edge[20]), reverseEdge(edge[1]) };
        vector<Edge> b5  = { edge[5], reverseEdge(edge[20]), reverseEdge(edge[1]) };
		vector<vertex> v5 = { vertices[1], vertices[5], vertices[9] };
        faces[5] = Face(v5, b5 , 5, 0);
        //vector<Edge> b6  = { edge[29], reverseEdge(edge[28]), edge[10] };
        vector<Edge> b6  = { edge[29], reverseEdge(edge[28]), reverseEdge(edge[10]) };
		vector<vertex> v6 = { vertices[5], vertices[11], vertices[4] };
        faces[6] = Face(v6, b6 , 6, 0);
        //vector<Edge> b7  = { edge[27], reverseEdge(edge[12]), edge[13] };
        vector<Edge> b7  = { edge[27], reverseEdge(edge[13]), reverseEdge(edge[12]) };
		vector<vertex> v7 = { vertices[11], vertices[10], vertices[2] };
        faces[7] = Face(v7, b7 , 7, 0);
        //vector<Edge> b8  = { edge[25], reverseEdge(edge[6]), edge[11] };
        /*vector<Edge> b8  = { edge[25], reverseEdge(edge[6]), reverseEdge(edge[11]) };
        vector<vertex> v8 = { vertices[10], vertices[7], vertices[6] };*/
        vector<Edge> b8  = { reverseEdge(edge[25]), reverseEdge(edge[21]), edge[23] };
		vector<vertex> v8 = { vertices[10], vertices[7], vertices[6] };
        faces[8] = Face(v8, b8 , 8, 0);
        //vector<Edge> b9  = { edge[6], reverseEdge(edge[7]), edge[8] };
        vector<Edge> b9  = { edge[6], edge[7], reverseEdge(edge[8]) };
        vector<vertex> v9 = { vertices[7], vertices[1], vertices[8] };
        faces[9] = Face(v9, b9 , 9, 0);
        vector<Edge> b10 = { reverseEdge(edge[17]), edge[14],(edge[19])};
        vector<vertex> v10= { vertices[3], vertices[9], vertices[4] };
        faces[10]= Face(v10, b10,10, 0);
        vector<Edge> b11 = { edge[14], reverseEdge(edge[10]), (edge[9]) };
        vector<vertex> v11= { vertices[3], vertices[4], vertices[2] };
        faces[11]= Face(v11, b11,11, 0);
        vector<Edge> b12 = { edge[9], (edge[15]), edge[11] };
        vector<vertex> v12= { vertices[3], vertices[2], vertices[6] };
        faces[12]= Face(v12, b12,12, 0);
        vector<Edge> b13 = { edge[15], edge[22], reverseEdge(edge[16]) };
        vector<vertex> v13= { vertices[3], vertices[6], vertices[8] };
        faces[13]= Face(v13, b13,13, 0);
        vector<Edge> b14 = { edge[16], (edge[26]), reverseEdge(edge[17]) };
        vector<vertex> v14= { vertices[3], vertices[8], vertices[9] };
        faces[14]= Face(v14, b14,14, 0);
        vector<Edge> b15 = { edge[19], reverseEdge(edge[20]), reverseEdge(edge[18]) };
        vector<vertex> v15= { vertices[4], vertices[9], vertices[5] };
        faces[15]= Face(v15, b15,15, 0);
        vector<Edge> b16 = { edge[10], reverseEdge(edge[28]), reverseEdge(edge[13]) };
        vector<vertex> v16= { vertices[2], vertices[4], vertices[11] };
        faces[16]= Face(v16, b16,16, 0);
        vector<Edge> b17 = { reverseEdge(edge[11]), edge[12], reverseEdge(edge[23]) };
        vector<vertex> v17= { vertices[6], vertices[2], vertices[10] };
        faces[17]= Face(v17, b17,17, 0);
        vector<Edge> b18 = { reverseEdge(edge[22]), edge[21], edge[24] };
        vector<vertex> v18= { vertices[8], vertices[6], vertices[7] };
        faces[18]= Face(v18, b18,18, 0);
        vector<Edge> b19 = { reverseEdge(edge[26]), reverseEdge(edge[7 ]), edge[8 ] };
        vector<vertex> v19= { vertices[9], vertices[8], vertices[1] };
        faces[19]= Face(v19, b19,19, 0);
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
	class mesh_Polyhedron
	{
		public:
		vector<Face> faces;
		vector <Edge> edges;
		vector <vertex> vertices;
		unsigned int p;
		unsigned int q;
		unsigned int b;
		unsigned int c;
		unsigned int NumVer;
		unsigned int NumEdg;
		unsigned int NumFcs;
		mesh_Polyhedron(
		vector<Face> fcs, vector<Edge> edgs, vector<vertex> vrtcs, 
		unsigned int b0, unsigned int c0, unsigned int p0, unsigned int q0
		 ){
			faces = fcs;
			edges = edgs;
			vertices = vrtcs; 
			b = b0;
			c = c0;
			p = p0;
			q = q0;
		}	
void Triangulation() {
    vector<Edge> edges_1;
    vector<Face> faces_1;
    vector<vertex> ver_1;
    if ((b == 0 && c != 0) || (b != 0 && c == 0)) {
        if (p == 3) {
            unsigned int T = b * b + c * b + c * c;

            switch (q) {
                case 3:
                    NumVer = 2 * T + 2; NumEdg = 6 * T; NumFcs = 4 * T;
                    break;
                case 4:
                    NumVer = 4 * T + 2; NumEdg = 12 * T; NumFcs = 8 * T;
                    break;
                case 5:
                    NumVer = 10 * T; NumEdg = 30 * T; NumFcs = 20 * T;
                    break;
            }

            faces_1.reserve(NumFcs);
            edges_1.reserve(NumEdg);
            edges.reserve(NumEdg);
            vertices.reserve(NumVer);
            ver_1.reserve(NumVer);

            unsigned int id_edge = 0;
            unsigned int id_faces = 0;
            vertex v;
            vertex v1;
            map<unsigned int, vector<vertex>> Triangle;
            vector<size_t> index_edges(3);
                size_t cv = 0;
        	if(b==0){
        		b=c;
			}else{
				c=b;
			}
    for (size_t i = 0; i < faces.size(); i++) {
               for (size_t k = 0; k < b ; k++) {
                    Triangle[k].resize(k + 2);
					vertex v0;
					vertex v_origin;	
			  		
			if (faces[i].edges[1].end != faces[i].edges[0].end) 
			{
    		if (faces[i].edges[1].end == faces[i].edges[0].origin) {
        	v = faces[i].edges[0].origin;

        	v0 = vertex(
            (faces[i].edges[0].end.x - faces[i].edges[0].origin.x) * (k + 1) / float(b) + faces[i].edges[0].origin.x,
            (faces[i].edges[0].end.y - faces[i].edges[0].origin.y) * (k + 1) / double(b) + faces[i].edges[0].origin.y,
            (faces[i].edges[0].end.z - faces[i].edges[0].origin.z) * (k + 1) / double(b) + faces[i].edges[0].origin.z,
            cv++
        	)	;

        	v1 = vertex(
            (faces[i].edges[1].end.x - faces[i].edges[1].origin.x) * (b - k - 1) / double(b) + faces[i].edges[1].origin.x,
            (faces[i].edges[1].end.y - faces[i].edges[1].origin.y) * (b - k - 1) / double(b) + faces[i].edges[1].origin.y,
            (faces[i].edges[1].end.z - faces[i].edges[1].origin.z) * (b - k - 1) / double(b) + faces[i].edges[1].origin.z,
            cv++
        	);

    		} else if (faces[i].edges[1].origin == faces[i].edges[0].origin) {
        	v = faces[i].edges[0].origin;

        	v0 = vertex(
            (faces[i].edges[0].end.x - faces[i].edges[0].origin.x) * (k + 1) / float(b) + faces[i].edges[0].origin.x,
            (faces[i].edges[0].end.y - faces[i].edges[0].origin.y) * (k + 1) / double(b) + faces[i].edges[0].origin.y,
            (faces[i].edges[0].end.z - faces[i].edges[0].origin.z) * (k + 1) / double(b) + faces[i].edges[0].origin.z,
            cv++
        	);

        	v1 = vertex(
            (faces[i].edges[1].end.x - faces[i].edges[1].origin.x) * (k + 1) / double(b) + faces[i].edges[1].origin.x,
            (faces[i].edges[1].end.y - faces[i].edges[1].origin.y) * (k + 1) / double(b) + faces[i].edges[1].origin.y,
            (faces[i].edges[1].end.z - faces[i].edges[1].origin.z) * (k + 1) / double(b) + faces[i].edges[1].origin.z,
            cv++
        	);

    		} else if (faces[i].edges[0].end == faces[i].edges[1].origin) {
        	v = faces[i].edges[0].end;

        	v0 = vertex(
            (faces[i].edges[0].end.x - faces[i].edges[0].origin.x) * (b - k - 1) / float(b) + faces[i].edges[0].origin.x,
            (faces[i].edges[0].end.y - faces[i].edges[0].origin.y) * (b - k - 1) / double(b) + faces[i].edges[0].origin.y,
            (faces[i].edges[0].end.z - faces[i].edges[0].origin.z) * (b - k - 1) / double(b) + faces[i].edges[0].origin.z,
            cv++
        	);

        	v1 = vertex(
            (faces[i].edges[1].end.x - faces[i].edges[1].origin.x) * (k + 1) / double(b) + faces[i].edges[1].origin.x,
            (faces[i].edges[1].end.y - faces[i].edges[1].origin.y) * (k + 1) / double(b) + faces[i].edges[1].origin.y,
            (faces[i].edges[1].end.z - faces[i].edges[1].origin.z) * (k + 1) / double(b) + faces[i].edges[1].origin.z,
            cv++
        	);
    		}
			}
			else if (faces[i].edges[0].end == faces[i].edges[1].end)
			{
    		v = faces[i].edges[0].end;

    		v0 = vertex(
        	(	faces[i].edges[0].end.x - faces[i].edges[0].origin.x) * (b - k - 1) / double(b) + faces[i].edges[0].origin.x,
        	(faces[i].edges[0].end.y - faces[i].edges[0].origin.y) * (b - k - 1) / double(b) + faces[i].edges[0].origin.y,
        	(faces[i].edges[0].end.z - faces[i].edges[0].origin.z) * (b - k - 1) / double(b) + faces[i].edges[0].origin.z,
        	cv++
    		);

    		v1 = vertex(
        	(faces[i].edges[1].end.x - faces[i].edges[1].origin.x) * (b - k - 1) / double(b) + faces[i].edges[1].origin.x,
        	(faces[i].edges[1].end.y - faces[i].edges[1].origin.y) * (b - k - 1) / double(b) + faces[i].edges[1].origin.y,
        	(faces[i].edges[1].end.z - faces[i].edges[1].origin.z) * (b - k - 1) / double(b) + faces[i].edges[1].origin.z,
        		cv++
    		);	
			}

                    Triangle[k][0] = v0;
                    Triangle[k][k+1] = v1;
                    for (size_t j = 0; j < k; j++) {				
                    double t = double(j+1) / (k + 1);
					vertex v2(
    				v0.x + t * (v1.x - v0.x),
 				   	v0.y + t * (v1.y - v0.y),
    				v0.z + t * (v1.z - v0.z),
    				cv++
					);
                        Triangle[k][j+1] = v2; 
                    }
                    if (k > 0) {
                        for (size_t j = 0; j < k + 1 ; j++) {
                            
                         if (j + 1 >= Triangle[k].size() || j >= Triangle[k - 1].size()) continue;
							
                            Edge e0(Triangle[k - 1][j], Triangle[k][j], id_edge++);
                            Edge e1(Triangle[k][j], Triangle[k][j + 1], id_edge++);
                            Edge e2(Triangle[k][j + 1], Triangle[k - 1][j], id_edge++);

                            vector<Edge> e = {e0, e1, e2};
                            vector<vertex> ver = {Triangle[k - 1][j], Triangle[k][j], Triangle[k][j + 1]};
                            if(j>0){		
							vector<vertex> hidden = {Triangle[k - 1][j], Triangle[k-1][j-1], Triangle[k][j]};
						    Edge _e1(Triangle[k][j], Triangle[k - 1][j-1], -1);
							Edge _e2(Triangle[k-1][j-1], Triangle[k-1][j], -1);
                            vector<Edge> _e = {_e1, _e2, e0};
                            faces_1.push_back(Face(hidden, _e, id_faces++, 0));
						    }
                            faces_1.push_back(Face(ver, e, id_faces++, 0));

                            edges_1.push_back(e0);
                            edges_1.push_back(e1);
                            edges_1.push_back(e2);

                            ver_1.push_back(Triangle[k - 1][j]);
                            ver_1.push_back(Triangle[k][j]);
                            ver_1.push_back(Triangle[k][j + 1]);
                        }
                    } else if(k==0) {
                    	vertex c;

                        Edge e0(v, v0, id_edge++);
                        Edge e1(v0, v1, id_edge++);
                        Edge e2(v1, v, id_edge++);
                        vector<Edge> e = {e0, e1, e2};
                        vector<vertex> ver = {v, v0, v1};
                        faces_1.push_back(Face(ver, e, id_faces++, 0));
                        edges_1.push_back(e0);
                        edges_1.push_back(e1);
                        edges_1.push_back(e2);
                        ver_1.push_back(v);
                        ver_1.push_back(v0);
                        ver_1.push_back(v1);
                    }
                }
            }
        }
    }   
    edges = edges_1;
    faces = faces_1;
        }  

void GenerateDual() {
    map<unsigned int, vector<unsigned int>> M;  
    map<unsigned int, vertex> centroid;    
    size_t n = faces[0].vertices.size();    //platonic solid  
    for (const auto& face : faces) {
        double cx = 0, cy = 0, cz = 0;
        for (const auto& v : face.vertices) {
            cx += v.x;
            cy += v.y;
            cz += v.z;
        }
        centroid[face.id] = vertex(cx / n, cy / n, cz / n, face.id);
        centroid[face.id].normalize();
    }
    
    for (size_t i = 0; i < faces.size(); ++i) {
        for (size_t j = i + 1; j < faces.size(); ++j) {
            int shared = 0;
            for (const auto& vi : faces[i].vertices) {
                for (const auto& vj : faces[j].vertices) {
                    if (vi == vj) shared++;
                }
            }
            if (shared == 2) {
                M[faces[i].id].push_back(faces[j].id);
                M[faces[j].id].push_back(faces[i].id);
            }
        }
    }
    vector<Edge> dual_edges;
    unsigned int id_edg = 0;

    for (size_t i = 0; i < faces.size(); ++i) {
        unsigned int fid = faces[i].id;
        for (unsigned int adj_id : M[fid]) {
            bool already_added = false;
            for (const auto& e : dual_edges) {
                if ((e.origin == centroid[fid] && e.end == centroid[adj_id]) ||
                    (e.end == centroid[fid] && e.origin == centroid[adj_id])) {
                    already_added = true;
                    break;
                }
            }

            if (!already_added) {
                Edge e(centroid[fid], centroid[adj_id], id_edg++);
                dual_edges.push_back(e);
            }
        }
    }
	cout << "--0"<<endl;
	
    for (const auto& e : dual_edges) {
        cout << "Edge " << e.id << ": (" << e.origin.x << ", " << e.origin.y << ", " << e.origin.z
             << ") -> (" << e.end.x << ", " << e.end.y << ", " << e.end.z
             << ") length: " << e.length() << "\n";
    }
	cout << "--0"<<endl;
}
		
	void printFaces() {
    			for(auto face: faces){
				printFace(face);
				}
				}
	

    };


}

