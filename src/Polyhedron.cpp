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
  unsigned int count=0;
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
			
                            Edge e0(Triangle[k - 1][j], Triangle[k][j], id_edge++, count+1);
                           //cout << e0.id << " e0" << endl;
                            count++;
                            if(e0.id==4294967295){
                            	e0.id=count;
							}
                            Edge e1(Triangle[k][j], Triangle[k][j + 1], id_edge++, count+1);
                            count++;
                            if(e1.id==4294967295){
                            	e1.id=count;
							}
						//	cout << e1.id << " e1" << endl;
                            Edge e2(Triangle[k][j + 1], Triangle[k - 1][j], id_edge++, count+1);
                            count++;
                            if(e2.id==4294967295){
                            	e2.id=count;
							}
						//	cout << e2.id << " e2" << endl;
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

                        Edge e0(v, v0, id_edge++,count+1);
                        count++;
                        Edge e1(v0, v1, id_edge++,count+1);
                        count++;
						Edge e2(v1, v, id_edge++, count+1);
						count++;
                        vector<Edge> e = {e0, e1, e2};
                        vector<vertex> ver = {v, v0, v1};
                        faces_1.push_back(Face(ver, e, id_faces++, 0));
                        edges_1.push_back(e0);
                        edges_1.push_back(e1);
                        edges_1.push_back(e2);
                        ver_1.push_back(v);
                        ver_1.push_back(v0);
                        ver_1.push_back(v1);
                        count+=3;
                    }
                }
            }
        }
    }   
    edges = edges_1;
    faces = faces_1;
        }
	/*		
	void _Polyhedron::Triangulation() {
    vector<Edge> edges_1;
    vector<Face> faces_1;
    vector<vertex> ver_1;
    if ((b == 0 && c > 0) || (b >0 && c == 0)) {
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
        }*/	

/*	void _Polyhedron::First_Triangulation(
    vector<vertex>& vertices,
    vector<Edge>& edges,
    Face& originalFace,
    unsigned int& cv,
    unsigned int& ce,
    unsigned int& cf,
    vector<Face>& fill,
    bool flag
    )
{
    const double heightRatio = sqrt(3.0) / 4.0;
    vertex shared01, shared12, shared02;
    if (originalFace.edges[1].end != originalFace.edges[0].end) {
        if (originalFace.edges[1].end == originalFace.edges[0].origin || 
            originalFace.edges[1].origin == originalFace.edges[0].origin)
            shared01 = originalFace.edges[0].origin;
        else if (originalFace.edges[0].end == originalFace.edges[1].origin)
            shared01 = originalFace.edges[0].end;
    } else {
        shared01 = originalFace.edges[0].end;
    }
    if (originalFace.edges[2].end != originalFace.edges[1].end) {
        if (originalFace.edges[2].end == originalFace.edges[1].origin || 
            originalFace.edges[2].origin == originalFace.edges[1].origin)
            shared12 = originalFace.edges[1].origin;
        else if (originalFace.edges[1].end == originalFace.edges[2].origin)
            shared12 = originalFace.edges[1].end;
    } else {
        shared12 = originalFace.edges[1].end;
    }
    if (originalFace.edges[2].end != originalFace.edges[0].end) {
        if (originalFace.edges[2].end == originalFace.edges[0].origin || 
            originalFace.edges[2].origin == originalFace.edges[0].origin)
            shared02 = originalFace.edges[0].origin;
        else if (originalFace.edges[0].end == originalFace.edges[2].origin)
            shared02 = originalFace.edges[0].end;
    } else {
        shared02 = originalFace.edges[0].end;
    }
    vertex center = vertex(
        0.5 * (originalFace.edges[2].origin.x + originalFace.edges[2].end.x),
        0.5 * (originalFace.edges[2].origin.y + originalFace.edges[2].end.y),
        0.5 * (originalFace.edges[2].origin.z + originalFace.edges[2].end.z),
        cv++
    );
    vertex apex = vertex(
        (shared01.x - center.x) * heightRatio + center.x,
        (shared01.y - center.y) * heightRatio + center.y,
        (shared01.z - center.z) * heightRatio + center.z,
        cv++
    );
    vertex midEdge0 = vertex(
        0.5 * (originalFace.edges[0].origin.x + originalFace.edges[0].end.x),
        0.5 * (originalFace.edges[0].origin.y + originalFace.edges[0].end.y),
        0.5 * (originalFace.edges[0].origin.z + originalFace.edges[0].end.z),
        cv++
    );
    vertex midEdge1 = vertex(
        0.5 * (originalFace.edges[1].origin.x + originalFace.edges[1].end.x),
        0.5 * (originalFace.edges[1].origin.y + originalFace.edges[1].end.y),
        0.5 * (originalFace.edges[1].origin.z + originalFace.edges[1].end.z),
        cv++
    );
    vertices.insert(vertices.end(), {center, apex, midEdge0, midEdge1, shared02, shared12, shared01});

    Edge edge_center_to_apex(center, apex, ce++);
    Edge edge_apex_to_shared01(apex, shared01, ce++);
    Edge edge_apex_to_midEdge0(apex, midEdge0, ce++);
    Edge edge_apex_to_shared12(apex, shared12, ce++);
    Edge edge_midEdge1_to_apex(midEdge1, apex, ce++);
    Edge edge_shared02_to_apex(shared02, apex, ce++);
    Edge edge_shared01_to_midEdge0(shared01, midEdge0, ce++);
    Edge edge_midEdge0_to_shared02(midEdge0, shared02, ce++);
    Edge edge_shared01_to_midEdge1(shared01, midEdge1, ce++);
    Edge edge_midEdge1_to_shared12(midEdge1, shared12, ce++);
    Edge edge_shared12_to_center(shared12, center, ce++);
    Edge edge_shared02_to_center(shared02, center, ce++);
    edges.insert(edges.end(), {
        edge_center_to_apex, edge_apex_to_shared01, edge_apex_to_midEdge0,
        edge_apex_to_shared12, edge_midEdge1_to_apex, edge_shared02_to_apex,
        edge_shared01_to_midEdge0, edge_midEdge0_to_shared02,
        edge_shared01_to_midEdge1, edge_midEdge1_to_shared12,
        edge_shared12_to_center, edge_shared02_to_center
    });
	
    Face face0({center, shared12, apex}, {edge_apex_to_shared12, edge_shared12_to_center, edge_center_to_apex}, cf++, 0);
    printFace(face0);
	Face face1({shared02, center, apex}, {edge_shared02_to_center, edge_center_to_apex, edge_shared02_to_apex}, cf++, 0);
    Face face2({midEdge0, shared02, apex}, {edge_midEdge0_to_shared02, edge_shared02_to_apex, edge_apex_to_midEdge0}, cf++, 0);
    Face face3({shared01, midEdge0, apex}, {edge_shared01_to_midEdge0, reverseEdge(edge_apex_to_midEdge0), edge_apex_to_shared01}, cf++, 0);
    Face face4({shared01, midEdge1, apex}, {edge_shared01_to_midEdge1, edge_midEdge1_to_apex, edge_apex_to_shared01}, cf++, 0);
    Face face5({midEdge1, apex, shared12}, {edge_midEdge1_to_apex, edge_apex_to_shared12, reverseEdge(edge_midEdge1_to_shared12)}, cf++, 0);
	Face face6({shared01, shared12, shared02}, {
    Edge(shared01, shared12, ce++),
    Edge(shared12, shared02, ce++),
    Edge(shared02, shared01, ce++)
}, cf++, 0);

    fill.insert(fill.end(), {face0, face1, face2, face3, face4, face5, face6});
}*/

	void _Polyhedron::First_Triangulation(
    vector<vertex>& vertices,
    vector<Edge>& edges,
    Face& originalFace,
    unsigned int& cv,
    unsigned int& ce,
    unsigned int& cf,
    vector<Face>& fill,
    bool flag
)
{
    const double heightRatio = sqrt(3.0) / 4.0;
    
    Edge v_0 = originalFace.edges[0];
    Edge v_1 = originalFace.edges[1];
    Edge v_2 = originalFace.edges[2];

    vertex shared01, shared12, shared02;
    if (v_1.end != v_0.end) {
        if (v_1.end == v_0.origin || v_1.origin == v_0.origin)
            shared01 = v_0.origin;
        else if (v_0.end == v_1.origin)
            shared01 = v_0.end;
    } else {
        shared01 = v_0.end;
    }

    if (v_2.end != v_1.end) {
        if (v_2.end == v_1.origin || v_2.origin == v_1.origin)
            shared12 = v_1.origin;
        else if (v_1.end == v_2.origin)
            shared12 = v_1.end;
    } else {
        shared12 = v_1.end;
    }

    if (v_2.end != v_0.end) {
        if (v_2.end == v_0.origin || v_2.origin == v_0.origin)
            shared02 = v_0.origin;
        else if (v_0.end == v_2.origin)
            shared02 = v_0.end;
    } else {
        shared02 = v_0.end;
    }
    vertex center = vertex(
        0.5 * (v_2.origin.x + v_2.end.x),
        0.5 * (v_2.origin.y + v_2.end.y),
        0.5 * (v_2.origin.z + v_2.end.z),
        cv++
    );
    vertex apex = vertex(
        (shared01.x - center.x) * heightRatio + center.x,
        (shared01.y - center.y) * heightRatio + center.y,
        (shared01.z - center.z) * heightRatio + center.z,
        cv++
    );
    vertex midEdge0 = vertex(
        0.5 * (v_0.origin.x + v_0.end.x),
        0.5 * (v_0.origin.y + v_0.end.y),
        0.5 * (v_0.origin.z + v_0.end.z),
        cv++
    );
    vertex midEdge1 = vertex(
        0.5 * (v_1.origin.x + v_1.end.x),
        0.5 * (v_1.origin.y + v_1.end.y),
        0.5 * (v_1.origin.z + v_1.end.z),
        cv++
    );
    vertices.insert(vertices.end(), {center, apex, midEdge0, midEdge1, shared02, shared12, shared01});
    Edge edge_center_to_apex(center, apex, ce++);
    Edge edge_apex_to_shared01(apex, shared01, ce++);
    Edge edge_apex_to_midEdge0(apex, midEdge0, ce++);
    Edge edge_apex_to_shared12(apex, shared12, ce++);
    Edge edge_midEdge1_to_apex(midEdge1, apex, ce++);
    Edge edge_shared02_to_apex(shared02, apex, ce++);
    Edge edge_shared01_to_midEdge0(shared01, midEdge0, ce++);
    Edge edge_midEdge0_to_shared02(midEdge0, shared02, ce++);
    Edge edge_shared01_to_midEdge1(shared01, midEdge1, ce++);
    Edge edge_midEdge1_to_shared12(midEdge1, shared12, ce++);
    Edge edge_shared12_to_center(shared12, center, ce++);
    Edge edge_shared02_to_center(shared02, center, ce++);
    edges.insert(edges.end(), {
        edge_center_to_apex, edge_apex_to_shared01, edge_apex_to_midEdge0,
        edge_apex_to_shared12, edge_midEdge1_to_apex, edge_shared02_to_apex,
        edge_shared01_to_midEdge0, edge_midEdge0_to_shared02,
        edge_shared01_to_midEdge1, edge_midEdge1_to_shared12,
        edge_shared12_to_center, edge_shared02_to_center
    });
    Face face0({center, shared12, apex}, {edge_apex_to_shared12, edge_shared12_to_center, edge_center_to_apex}, cf++, 0);
    printFace(face0);
    Face face1({shared02, center, apex}, {edge_shared02_to_center, edge_center_to_apex, edge_shared02_to_apex}, cf++, 0);
    Face face2({midEdge0, shared02, apex}, {edge_midEdge0_to_shared02, edge_shared02_to_apex, edge_apex_to_midEdge0}, cf++, 0);
    Face face3({shared01, midEdge0, apex}, {edge_shared01_to_midEdge0, reverseEdge(edge_apex_to_midEdge0), edge_apex_to_shared01}, cf++, 0);
    Face face4({shared01, midEdge1, apex}, {edge_shared01_to_midEdge1, edge_midEdge1_to_apex, edge_apex_to_shared01}, cf++, 0);
    Face face5({midEdge1, apex, shared12}, {edge_midEdge1_to_apex, edge_apex_to_shared12, reverseEdge(edge_midEdge1_to_shared12)}, cf++, 0);
    Face face6({shared01, shared12, shared02}, {
        Edge(shared01, shared12, ce++),
        Edge(shared12, shared02, ce++),
        Edge(shared02, shared01, ce++)
    }, cf++, 0);

    fill.insert(fill.end(), {face0, face1, face2, face3, face4, face5/*, face0, face1, face6*/});
}
	void _Polyhedron::Second_Triangulation_Lower(
	vector<vertex>& vertices,
    vector<Edge>& edges,
    vector<Face>& _f_,
    unsigned int& cv,
    unsigned int& ce,
    unsigned int& cf,
    vector<Face>& fill,
    bool flag, vector<vertex>& neigh){
	}
	void Second_Triangulation_Lateral(vector<vertex>&,
    								vector<Edge>&,
    								vector<Face>&,
    								unsigned int&,
    								unsigned int&,
    								unsigned int&,
    								vector<Face>&,
    								bool, 
									vector<vertex>&){									
	}	
    void _Polyhedron::Triangulation_2() {
    vector<Edge> edges_1;
    vector<Face> faces_1;
    vector<vertex> ver_1;
    vector<vertex> ver_2;
	vector<Face> faces_2;
	vector<Edge> edges_2;	
    vector<vertex> ver_3;
	vector<Face> faces_3;
	vector<Edge> edges_3;	
	unsigned int id_f1=0;
	unsigned int id_v1=0;
	unsigned int id_e1=0;
	unsigned int id_f2=0;
	unsigned int id_v2=0;
	unsigned int id_e2=0;
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
                bool flg=false;
                if (k > 0) {
                    for (size_t j = 0; j < k + 1 ; j++) {   
                         if (j + 1 >= Triangle[k].size() || j >= Triangle[k - 1].size()) continue;
						    Edge e1(Triangle[k][j], Triangle[k][j + 1], id_edge++);	
							Edge e2(Triangle[k][j + 1], Triangle[k - 1][j], id_edge++);
                            Edge e0(Triangle[k - 1][j], Triangle[k][j], id_edge++);
                            vector<Edge> _e = {e0, e1, e2};
                            vector<vertex> ver = {Triangle[k - 1][j], Triangle[k][j], Triangle[k][j + 1]};
                            if(j>0){		
							vector<vertex> hidden = {Triangle[k - 1][j], Triangle[k-1][j-1], Triangle[k][j]};
						    Edge _e1(Triangle[k][j], Triangle[k - 1][j-1], -1);
							Edge _e2(Triangle[k-1][j-1], Triangle[k-1][j], -1);
                            vector<Edge> _e = {e0,_e2,_e1};
                            Face fb_1(hidden, _e, id_faces++, 0);
                            faces_1.push_back(fb_1);
                            flg=true;
                            vector<vertex> _v_ = {};
                            First_Triangulation(ver_2,edges_2,fb_1,id_v1,id_e1,id_f1,faces_2,flg);
						    }
						    Face fb(ver, _e, id_faces++, 0);
                            faces_1.push_back(fb);
                            flg=true;
                            Face miss;
                            vector<vertex> _v_ = {};
                            First_Triangulation(ver_2,edges_2,fb,id_v1,id_e1,id_f1,faces_2,flg);
                            edges_1.push_back(e1); 
							edges_1.push_back(e2);
							edges_1.push_back(e0);
                            ver_1.push_back(Triangle[k - 1][j]);
                            ver_1.push_back(Triangle[k][j]);
                            ver_1.push_back(Triangle[k][j + 1]);
                        }
                    } 
					else if(k==0) {
                    	vertex c;
                        Edge e0(v, v0, id_edge++);
                        Edge e1(v0, v1, id_edge++);
                        Edge e2(v1, v, id_edge++);
                        vector<Edge> e = {e0, e1, e2};
                        vector<vertex> ver = {v, v0, v1};
                        Face fb(ver, e, id_faces++, 0);
                        faces_1.push_back(fb);
                        flg=false;
                         vector<vertex> _v_ ={};
                        First_Triangulation(ver_2,edges_2,fb,id_v1,id_e1,id_f1,faces_2,flg);
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
		void _Polyhedron::OverAll_Triangulation(){
			if ((b == 0 && c > 0) || (b >0 && c == 0)) {
				_Polyhedron::Triangulation();
			}
			else if(b>0 && c>0 && b==c){
				_Polyhedron::Triangulation_2();
			}
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
    for (const auto& e : dual_edges) {
        cout << "Edge " << e.id << ": (" << e.origin.x << ", " << e.origin.y << ", " << e.origin.z
             << ") -> (" << e.end.x << ", " << e.end.y << ", " << e.end.z
             << ") length: " << e.length() << "\n";
    }
	//bulk of the face.	
	map<unsigned int, vector<unsigned int>> vertex_to_faces;
	for (const auto& face : faces) {
    for (const auto& v : face.vertices) {
        vertex_to_faces[v.id].push_back(face.id);
    }
	}
	}
    #include <Eigen/Dense>

    
        
}
MatrixXd ConvertVerticesToEigen(const std::vector<vertex>& vertices) {
        MatrixXd points(3, vertices.size());
        for (size_t i = 0; i < vertices.size(); ++i) {
            points(0, i) = vertices[i].x;
            points(1, i) = vertices[i].y;
            points(2, i) = vertices[i].z;
        }
        return points;
    }

    MatrixXi ConvertEdgesToEigen(const std::vector<Edge>& edges) {
        MatrixXi segments(2, edges.size());
        for (size_t i = 0; i < edges.size(); ++i) {
            segments(0, i) = edges[i].origin.id;
            segments(1, i) = edges[i].end.id;
        }
        return segments;
    }