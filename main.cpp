
#include <iostream>
#include "UCDUtilities.hpp"
#include "Polyhedron.hpp"
#include "Polygon.hpp"

using namespace Eigen;
using namespace PolygonalLibrary;
using namespace PolyhedronLibrary;
using namespace std;
using namespace Gedim;
int main()
{
	
	Tetrahedron t;
	Cube C;
	Octahedron o;
	Dodecahedron cc;
	Icosahedron i;

	unsigned int p,q,b,c;
	_Polyhedron pp;
	cin >> p >> q >> b >> c ;
				pp=_Polyhedron(i.faces,i.edge,i.vertices,b,c, p,q);
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
	
/*	Gedim::UCDUtilities utilities;
    utilities.ExportPoints("./Cell0Ds.inp",
                        t.vertices);

    utilities.ExportSegments("./Cell1Ds.inp",
                            t.vertices,
                            t.edge	);

*/


    // Conversione dei dati a Eigen
    MatrixXd points = ConvertVerticesToEigen(pp.vertices);
    MatrixXi segments = ConvertEdgesToEigen(pp.edges);

    // Esportazione in UCD
    UCDUtilities utilities;
    utilities.ExportPoints("TetrahedronPoints.inp", points);
    utilities.ExportSegments("TetrahedronSegments.inp", points, segments);

    cout << "Esportazione completata. Apri i file .inp con ParaView.\n";


	return 0;


}