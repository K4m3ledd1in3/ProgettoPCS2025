
#include <iostream>
#include "UCDUtilities.hpp"
#include "Polyhedron.hpp"
#include "Polygon.hpp"

using namespace Eigen;
using namespace PolygonalLibrary;
using namespace PolyhedronLibrary;
using namespace std;

int main()
{	cout << "Tetraedro" << endl;
	Tetrahedron t;
	Cube c;
	Octahedron o;
	Dodecahedron cc;
	Icosahedron i;
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
							
                   

	return 0;


}