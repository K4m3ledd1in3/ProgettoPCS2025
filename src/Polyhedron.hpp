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
		Dodecahedron() {
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
        vector<Edge> b4  = { edge[3], edge[12], reverseEdge(edge[4]) };
        vector<vertex> v4 = { vertices[0], vertices[10], vertices[11] };
        faces[4] = Face(v4, b4 , 4, 0);
        vector<Edge> b5  = { edge[5], reverseEdge(edge[20]), reverseEdge(edge[1]) };
        vector<vertex> v5 = { vertices[1], vertices[5], vertices[9] };
        faces[5] = Face(v5, b5 , 5, 0);
        vector<Edge> b6  = { edge[29], reverseEdge(edge[28]), edge[10] };
        vector<vertex> v6 = { vertices[5], vertices[11], vertices[4] };
        faces[6] = Face(v6, b6 , 6, 0);
        vector<Edge> b7  = { edge[27], reverseEdge(edge[12]), edge[13] };
        vector<vertex> v7 = { vertices[11], vertices[10], vertices[2] };
        faces[7] = Face(v7, b7 , 7, 0);
        vector<Edge> b8  = { edge[25], reverseEdge(edge[6]), edge[11] };
        vector<vertex> v8 = { vertices[10], vertices[7], vertices[6] };
        faces[8] = Face(v8, b8 , 8, 0);
        vector<Edge> b9  = { edge[6], reverseEdge(edge[7]), edge[8] };
        vector<vertex> v9 = { vertices[7], vertices[1], vertices[8] };
        faces[9] = Face(v9, b9 , 9, 0);
        vector<Edge> b10 = { reverseEdge(edge[17]), reverseEdge(edge[19]), edge[14] };
        vector<vertex> v10= { vertices[3], vertices[9], vertices[4] };
        faces[10]= Face(v10, b10,10, 0);
        vector<Edge> b11 = { edge[14], reverseEdge(edge[10]), reverseEdge(edge[9 ]) };
        vector<vertex> v11= { vertices[3], vertices[4], vertices[2] };
        faces[11]= Face(v11, b11,11, 0);
        vector<Edge> b12 = { edge[9], edge[11], reverseEdge(edge[15]) };
        vector<vertex> v12= { vertices[3], vertices[2], vertices[6] };
        faces[12]= Face(v12, b12,12, 0);
        vector<Edge> b13 = { edge[15], edge[22], reverseEdge(edge[16]) };
        vector<vertex> v13= { vertices[3], vertices[6], vertices[8] };
        faces[13]= Face(v13, b13,13, 0);
        vector<Edge> b14 = { edge[16], reverseEdge(edge[26]), reverseEdge(edge[17]) };
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
	class mesh_Polyhedron{
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
		
		mesh_Polyhedron Triangulation(){
					unsigned int buff_f = NumFcs;
					unsigned int buff_v = NumVer;
					unsigned int buff_e = NumEdg;
			if((b==0 && c!=0) ||(b!=0 && c==0)){
				if(p==3){
					unsigned int T = b*b + c*b + c*c;
					switch(q){
						case 3:	 
							NumVer = 2*T + 2 ; NumEdg = 6*T; NumFcs = 4*T ;
							break;
						case 4:
							NumVer = 4*T + 2 ; NumEdg = 2*T; NumFcs = 8*T ;
							break;
						case 5:
							NumVer = 10*T ; NumEdg = 30*T; NumFcs = 20*T ;							
							break;
								
					}
					faces.resize(NumFcs);
					edges.reserve(NumEdg);
					vertices.reserve(NumVer);
					for(size_t i = 0; i<NumFcs; i++){
							for(auto e: faces[i].edges){
								for(size_t k = 0; k<b-1; k++){
									bool flag = true;
									vertex v(
									(e.end.x - e.origin.x) * (k+1) / b + e.origin.x, 
									(e.end.y - e.origin.y) * (k+1) / b + e.origin.y,
									(e.end.z - e.origin.z) * (k+1) / b + e.origin.z, 
									buff_v, k+1);
									for(auto h: vertices){
										if(v==h){
										   flag = false;
										}
									}
									if(flag){
									vertices.push_back(v);
									buff_v++;
								    }
								}				
						}
						
					}
					
					for(auto v: vertices){
							cout << "(" << v.x << "," << v.y << "," << v.z << ")" << ", " << v.marker <<  endl ;}
					}
					}
								return *this;
				}

		

			};
}

