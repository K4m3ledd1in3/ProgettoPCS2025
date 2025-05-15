
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
	cout << "Tetraedro" << endl;
	Tetrahedron t;
	t.printFaces();
	cout << endl << endl;
	t.dual().printFaces();
	Cube c;
	cout << "Cubo" << endl;
	c.printFaces();
	Octahedron o;
	cout << "Ottaedro" << endl;
	o.printFaces();
	Dodecahedron cc;
	cout << "CC" << endl;
	cc.printFaces();
	Icosahedron i;
	cout << "ICC" << endl;
	i.printFaces();
	return 0;
}