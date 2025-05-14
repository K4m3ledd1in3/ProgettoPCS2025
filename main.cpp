
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
	t.printFaces();
	cout << endl << endl;
	t.dual().printFaces();
	Cube c;
	cout << "c" << endl;
	c.printFaces();
	Octahedron o;
	cout << "o" << endl;
	o.printFaces();
	Dodecahedron cc;
	cout << "CC" << endl;
	cc.printFaces();
	
	return 0;
}