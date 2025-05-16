
#include <iostream>
#include "UCDUtilities.hpp"
#include "Polyhedron.hpp"
#include "Polygon.hpp"

using namespace Eigen;
using namespace PolygonalLibrary;
using namespace PolyhedronLibrary;
using namespace std;

int main()
<<<<<<< HEAD
{
	cout << "Tetraedro" << endl;
=======
{	cout << "Tetraedro" << endl;
>>>>>>> 0f6c835ecb0ebcd3a029c9c293c420d94b786414
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
	cout << "Dodecaedro" << endl;
	cc.printFaces();
	Icosahedron i;
	cout << "ICC" << endl;
	i.printFaces();
	return 0;
}