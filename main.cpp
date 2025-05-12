
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
	t.display();
	Cube c;
	c.display();
/*    int id = 1;
    double phi = M_PI / 4;
    double psi = M_PI / 4;
    double dPhi = M_PI / 6;
    double dPsi = M_PI / 8;

    Face square = projectSquareToSphere(phi, psi, dPhi, dPsi, id,0);
    printFace(square);

    Face triangle = projectTriangleToSphere(phi, psi, dPhi, dPsi, id,1);
    printFace(triangle);
    phi+=phi;
    
    Face triangle_2 = projectTriangleToSphere(phi, psi, dPhi, dPsi, id,2);
    printFace(triangle_2);
    
    dPhi = M_PI / 6;  
    dPsi = M_PI / 6;  
    Face pentagon = projectPentagonToSphere(phi, psi, dPhi, dPsi, id,3);
	printFace(pentagon);
  	phi+=dPhi;
  	phi+=dPsi;
    Face pentagon_2 = projectPentagonToSphere(phi, psi, dPhi, dPsi, id,4);
	printFace(pentagon_2);*/

	return 0;
}
