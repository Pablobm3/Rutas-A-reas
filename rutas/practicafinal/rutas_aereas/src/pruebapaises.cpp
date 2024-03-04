#include <iostream>
#include <fstream>
#include "Paises.h"

using namespace std;

int main() {
    Paises conjuntoPaises;

    ifstream inputFile("\home/pablo/Descargas/bien/rutas/practicafinal/datos/paises.txt");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo paises.txt" << endl;
        return 1;
    }

    inputFile >> conjuntoPaises;
    inputFile.close();

    cout << "Conjunto de países leído desde el archivo:" << endl;
    cout << conjuntoPaises << endl;

    string nombrePais;
    cout << "Introduce el nombre del país a buscar: ";
    getline(cin, nombrePais);

    Pais paisBusqueda;
    paisBusqueda.GetPunto(); // Punto por defecto, no lo estamos utilizando en este caso.
    paisBusqueda.GetPais() = nombrePais;

    Paises::iterator it = conjuntoPaises.find(paisBusqueda);

    if (it != conjuntoPaises.end()) {
        cout << "País encontrado: " << *it << endl;
    } else {
        cout << "País no encontrado." << endl;
    }

    return 0;
}
