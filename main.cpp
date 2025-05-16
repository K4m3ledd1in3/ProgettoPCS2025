
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
<<<<<<< HEAD
	
	/*//Per visualizzare online le mesh
    Gedim::UCDUtilities utilities;
    utilities.ExportPoints("./Cell0Ds.inp",
                           mesh.cell0Ds_coordinates);

    utilities.ExportSegments("./Cell1Ds.inp",
                             mesh.cell0Ds_coordinates,
                             mesh.cell1Ds_extrema);
    */
   Gedim::UCDUtilities utils;

   

    // 2. Estrai coordinate in una matrice
	MatrixXd coords(3, t.vertices.size());
    for (size_t i = 0; i < t.vertices.size(); ++i) {
        coords(0, i) = t.vertices[i].x;
        coords(1, i) = t.vertices[i].y;
        coords(2, i) = t.vertices[i].z;
    }

    // 3. Costruisci la lista degli indici dei vertici per il solido (un tetraedro ha 4 vertici)
    vector<vector<unsigned int>> celle = {
        {0, 1, 2, 3}
    };

    // 4. Esporta il file per ParaView
    utils.ExportPolyhedra("tetraedro.inp", coords, celle);
=======
	Icosahedron i;
	cout << "ICC" << endl;
	i.printFaces();
>>>>>>> bb02cd1349c5864febbc1406ea952d7be64b5130
	return 0;
}