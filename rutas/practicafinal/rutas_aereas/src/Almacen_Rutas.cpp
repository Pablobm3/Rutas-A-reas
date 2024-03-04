#include "Almacen_Rutas.h"

Ruta Almacen_Rutas::GetRuta(const string a) {
    map<string, Ruta>::iterator it = rutas.find(a);
    if (it != rutas.end()) {
        return it->second;
    } else {
        // Manejar el caso en el que la ruta no se encuentra
        // Puedes lanzar una excepción o devolver un objeto Ruta por defecto, dependiendo de tu lógica de aplicación
        // Por ejemplo:
        throw runtime_error("Ruta no encontrada");
    }
}

void Almacen_Rutas::Insertar(const Ruta &R) {
    rutas[R.getCode()] = R;
}

void Almacen_Rutas::Borrar(const Ruta &R) {
    rutas.erase(R.getCode());
}

Almacen_Rutas::iterator Almacen_Rutas::begin() {
    iterator it;
    it.r = rutas.begin();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin() const {
    const_iterator it;
    it.r = rutas.begin();
    return it;
}

Almacen_Rutas::iterator Almacen_Rutas::end() {
    iterator it;
    it.r = rutas.end();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::end() const {
    const_iterator it;
    it.r = rutas.end();
    return it;
}

Almacen_Rutas::iterator Almacen_Rutas::find(const Ruta &r) {
    iterator it;
    it.r = rutas.find(r.getCode());
    return it;
}

istream &operator>>(istream &is, Almacen_Rutas &R) {
    // Implementa la lógica para leer desde el flujo de entrada is y actualizar el objeto R
    // Puedes utilizar el operador >> de Ruta para leer cada ruta individualmente
    // Por ejemplo:

    // Quitar el comentario de la primera línea (solo funciona si siempre hay una y solo una línea al principio como comentario)
    string aux;
    getline(is, aux);

    while (!is.eof()) {
        Ruta ruta;
        is >> ruta;
        R.Insertar(ruta);
    }
    return is;
}

ostream &operator<<(ostream &os, const Almacen_Rutas &R) {
    Almacen_Rutas::const_iterator it;
    for (it = R.begin(); it != R.end(); ++it) {
        os << *it << "\n";
    }
    return os;
}



