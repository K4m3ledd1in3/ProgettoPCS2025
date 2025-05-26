
#include <iostream>
#include "UCDUtilities.hpp"
#include "Polyhedron.hpp"
#include "Polygon.hpp"

using namespace Eigen;
using namespace PolygonalLibrary;
using namespace PolyhedronLibrary;
using namespace std;

int main()
{
	
	Tetrahedron t;
	Cube C;
	Octahedron o;
	Dodecahedron cc;
	Icosahedron i;
<<<<<<< HEAD
	unsigned int p,q,b,c;
	_Polyhedron pp;
	cin >> p >> q >> b >> c ;
				pp=_Polyhedron(t.faces, t.edge, t.vertices,b,c, p,q);
				pp.OverAll_Triangulation();
				pp.printFaces();
				pp.GenerateDual();	
/*	switch(p){
		case 3:
			switch(q){
				case 3:
				pp=_Polyhedron(t.faces, t.edge, t.vertices,b,c, p,q);
				pp.OverAll_Triangulation();
				pp.printFaces();
				pp.GenerateDual();
				case 4:
				pp=_Polyhedron(o.faces, o.edge, o.vertices,b,c, p,q);
				pp.OverAll_Triangulation();
				pp.printFaces();
				pp.GenerateDual();	
				case 5:
				pp=_Polyhedron(i.faces, i.edge, i.vertices,b,c,p,q);
				pp.OverAll_Triangulation();
				pp.printFaces();
				pp.GenerateDual();					
			}
			break;
		case 4:
			if(q==3){
				pp=_Polyhedron(C.faces, C.edge, C.vertices,b,c,p,q);
				pp.printFaces();
				pp.GenerateDual();						
			}
			break;
		case 5:
			if(q==3){
				pp=_Polyhedron(cc.faces, cc.edge, cc.vertices,b,c,p,q);
				pp.printFaces();
				pp.GenerateDual();						
			}
			break;
		default: break;
	}*/
=======
<<<<<<< HEAD
    _Polyhedron pp(t.faces, t.edge, t.vertices,5,5, 3,3);
    pp.Triangulation_2();	
   	pp.GenerateDual();
    pp.printFaces();
	

	
	Gedim::UCDUtilities utilities;
    utilities.ExportPoints("./Cell0Ds.inp",
                        t.vertices);

    utilities.ExportSegments("./Cell1Ds.inp",
                            t.vertices,
                            t.edge	);
							
                   

=======
     _Polyhedron pp(t.faces, t.edge, t.vertices,5,5, 3,3);
     pp.Triangulation_2();	
   	 pp.GenerateDual();
     pp.printFaces();
>>>>>>> dadd1b56d30ee0e82b06640aaf43cf94a40d8be7
>>>>>>> 67570a6ce427b2ad0186b358d34f41864499db93
	return 0;


}