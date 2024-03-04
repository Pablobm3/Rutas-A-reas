#include <iostream>
#include <fstream>
#include "Pais.h"

using namespace std;

int main() {

    Pais pais;

    ifstream inputFile("/home/pablo/Descargas/bien/rutas/practicafinal/datos/paises.txt");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo paises.txt" << endl;
        return 1;
    }

    inputFile >> pais;
    inputFile.close();


    cout << "País leído desde el archivo:" << endl;
    cout << pais << endl;


    cout << "Posición del país: " << pais.GetPunto() << endl;
    cout << "Nombre del país: " << pais.GetPais() << endl;
    cout << "Bandera del país: " << pais.GetBandera() << endl;

    Pais otroPais;
    otroPais = pais;

    if (pais == otroPais) {
        cout << "Los países son iguales." << endl;
    } else {
        cout << "Los países no son iguales." << endl;
    }

    return 0;
}
