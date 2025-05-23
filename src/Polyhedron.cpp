#include "Eigen/Eigen"
#include "Polygon.hpp"
#include <iostream>
#include "Polyhedron.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

namespace PolyhedronLibrary{
	vector<vertex> ShortestPath(vector<vertex>& v, vector<Edge>& e){
		return v;
	}
	
	void Icosahedron::display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
		
	void Icosahedron::printFaces() {
    		for(auto face: faces){
		printFace(face);
			}	
			}
	void _Polyhedron::printFaces() {
    			for(auto face: faces){
				printFace(face);
				}
				}
	void Dodecahedron::display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
		
	void Dodecahedron::printFaces() {
    		for(auto face: faces){
				printFace(face);
			}	
			}	
			
	void Octahedron::display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
	void Octahedron::printFaces() {
    		for(auto face: faces){
		printFace(face);
		}	
		}
	void Cube::display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << this->vertices[i].x << "," << this->vertices[i].y << "," << this->vertices[i].z << ")" << endl;}
		}
	void Cube::printFaces() {
    for(auto face: faces){
		printFace(face);
	}	
	}
	
	void Tetrahedron::display() const{
			for(size_t i=0; i<vertices.size(); i++){
				cout << "(" << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << ")" << endl;}
		}
	void Tetrahedron::printFaces() {
    for(auto face: faces){
		printFace(face);
	}	
	}
			
	void _Polyhedron::Triangulation() {
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
		
		
		
	void _Polyhedron::First_Triangulation(vector<vertex>& vertices , 
						vector <Edge>& e, Face& f, unsigned int& cv, 
						unsigned int& ce, unsigned int& cf,
						  vector<Face>& fill, bool flag){
			const double t = sqrt(3) / 4;
			vertex v0, v1;
			vertex v; // vertices comune 01.
			vertex v_12; //vertices comune 12.
			vertex v_02; //vertice comune 02.	
			if (f.edges[1].end != f.edges[0].end) 
			{
			if (f.edges[1].end == f.edges[0].origin) {
        	v = f.edges[0].origin;
    		} else if (f.edges[1].origin == f.edges[0].origin) {
        	v = f.edges[0].origin;
    		} else if (f.edges[0].end == f.edges[1].origin) {
        	v = f.edges[0].end;
    		}
			}
			else if (f.edges[0].end == f.edges[1].end)
			{
    		v = f.edges[0].end;	
			}
				
			if (f.edges[2].end != f.edges[1].end) 
			{
    		if (f.edges[2].end == f.edges[1].origin) {
        	v_12 = f.edges[1].origin;
    		} else if (f.edges[2].origin == f.edges[1].origin) {
        	v_12 = f.edges[1].origin;
    		} else if (f.edges[1].end == f.edges[2].origin) {
        	v_12 = f.edges[1].end;
    		}
			}
			else if (f.edges[1].end == f.edges[2].end)
			{
    		v_12 = f.edges[1].end;	
			}
					
			if (f.edges[2].end != f.edges[0].end) 
			{
    		if (f.edges[2].end == f.edges[0].origin) {
        	v_02 = f.edges[0].origin;
    		} else if (f.edges[2].origin == f.edges[0].origin) {
        	v_02 = f.edges[0].origin;
    		} else if (f.edges[0].end == f.edges[2].origin) {
        	v_02 = f.edges[0].end;
    		}
			}
			else if (f.edges[0].end == f.edges[2].end)
			{
    		v_02 = f.edges[0].end;	
			}
				
			vertex _middle_base(
			0.5*(f.edges[2].origin.x+f.edges[2].end.x),(0.5*(f.edges[2].origin.y+f.edges[2].end.y)),(0.5*(f.edges[2].origin.z+f.edges[2].end.z))
			,cv++);
			vertex _up_base0(
			(v.x-_middle_base.x)*t+_middle_base.x, (v.y-_middle_base.y)*t+_middle_base.y,(v.z-_middle_base.z)*t+_middle_base.z,cv++);
			vertices.push_back(_middle_base);
			vertices.push_back(_up_base0);
			
			Edge e_base_to_up_0(_middle_base, _up_base0,ce++);
			Edge e_base_to_up_1(_up_base0, v, ce++);
			e.push_back(e_base_to_up_0); e.push_back(e_base_to_up_1);
			v0=vertex(
			0.5*(f.edges[0].origin.x+f.edges[0].end.x),0.5*(f.edges[0].origin.y+f.edges[0].end.y),(0.5*(f.edges[0].origin.z+f.edges[0].end.z))
			,cv++);
			v1=vertex(
			0.5*(f.edges[1].origin.x+f.edges[1].end.x),(0.5*(f.edges[1].origin.y+f.edges[1].end.y)),(0.5*(f.edges[1].origin.z+f.edges[1].end.z))
			,cv++);
			vertices.push_back(v0);
			vertices.push_back(v1);
			vertices.push_back(v_02);
			vertices.push_back(v_12);
			vertices.push_back(v);			
			Edge e_00u_m(_up_base0, v0,  ce++);//
			Edge e_01u_m(_up_base0, v_12, ce++);//
			e.push_back(e_00u_m); 	e.push_back(e_01u_m);
			Edge e_10u_m(v1, _up_base0, ce++);//
			Edge e_11u_m(v_02, _up_base0,ce++);//			
			e.push_back(e_10u_m); 	e.push_back(e_11u_m);			
			Edge e00(v,v0, ce++);//
			Edge e01(v0,v_02,ce++);//
			e.push_back(e00); 	
			e.push_back(e01);			
			Edge e10(v,v1, ce++);//
			Edge e11(v1,v_12,ce++);//			
				
			e.push_back(e11); 	
			e.push_back(e10);

			if(flag){
			Edge  v_12_to_m(v_12,_middle_base, ce++);
			Edge  v_02_to_m(v_02,_middle_base, ce++);			
			e.push_back(v_12_to_m); 
			e.push_back(v_02_to_m);					
			fill.push_back(Face(
			vector<vertex>{_middle_base, v_12, _up_base0},
			vector<Edge>{e_01u_m, v_12_to_m, e_base_to_up_0},
			cf++,0
			));
			fill.push_back(Face(
			vector<vertex>{v_02, _middle_base, _up_base0},
			vector<Edge>{v_02_to_m, e_base_to_up_0, e_11u_m},
			cf++,0
			));
			}	
			fill.push_back(Face(
			vector<vertex>{v0, v_02, _up_base0},
			vector<Edge>{e01, e_11u_m, e_00u_m},
			cf++,0
			));
			fill.push_back(Face(
			vector<vertex>{v, v0, _up_base0},
			vector<Edge>{e00, reverseEdge(e_00u_m), e_base_to_up_1},
			cf++,0
			));
			fill.push_back(Face(
			vector<vertex>{v, v1, _up_base0},
			vector<Edge>{e10, e_10u_m, e_base_to_up_1},
			cf++,0
			));
			fill.push_back(Face(
			vector<vertex>{v1, _up_base0, v_12},
			vector<Edge>{e_10u_m, e_01u_m, reverseEdge(e11)},
			cf++,0
			));		
}


    void _Polyhedron::Triangulation_2() {
    vector<Edge> edges_1;
    vector<Face> faces_1;
    vector<vertex> ver_1;
    vector<vertex> ver_2;
	vector<Face> faces_2;
	vector<Edge> edges_2;
	unsigned int id_f1=0;
	unsigned int id_v1=0;
	unsigned int id_e1=0;
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

                            vector<Edge> _e = {e0, e1, e2};
                            vector<vertex> ver = {Triangle[k - 1][j], Triangle[k][j], Triangle[k][j + 1]};
                            if(j>0){		
							vector<vertex> hidden = {Triangle[k - 1][j], Triangle[k-1][j-1], Triangle[k][j]};
						    Edge _e1(Triangle[k][j], Triangle[k - 1][j-1], -1);
							Edge _e2(Triangle[k-1][j-1], Triangle[k-1][j], -1);
                            vector<Edge> _e = {_e1, _e2, e0};
                            Face fb_1(hidden, _e, id_faces++, 0);
                            faces_1.push_back(fb_1);
                            First_Triangulation(ver_2,edges_2,fb_1,id_v1,id_e1,id_f1,faces_2,true);
						    }
						    Face fb(ver, _e, id_faces++, 0);
                            faces_1.push_back(fb);
                            First_Triangulation(ver_2,edges_2,fb,id_v1,id_e1,id_f1,faces_2,true);							
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
                        Face fb(ver, e, id_faces++, 0);
                        faces_1.push_back(fb);
                        First_Triangulation(ver_2,edges_2,fb,id_v1,id_e1,id_f1,faces_2,false);	
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
    edges = edges_2;
    faces = faces_2;
        } 
		
		
	void _Polyhedron::GenerateDual() {
    	map<unsigned int, vector<unsigned int>> M;  
    	map<unsigned int, vertex> centroid;    
    	size_t n = faces[0].vertices.size();     
    	for (const auto& face : faces) {
        double cx = 0, cy = 0, cz = 0;
        for (const auto& v : face.vertices) {
            cx += v.x;
            cy += v.y;
            cz += v.z;
        }
        centroid[face.id] = vertex(cx / n, cy / n, cz / n);
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
	
	map<unsigned int, vector<unsigned int>> vertex_to_faces;
	for (const auto& face : faces) {
    for (const auto& v : face.vertices) {
        vertex_to_faces[v.id].push_back(face.id);
    }
	}
	}		
	
}