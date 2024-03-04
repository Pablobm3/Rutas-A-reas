//
// Created by pablo on 12/12/23.
//

#ifndef PRACTICAFINAL_PAIS_H
#define PRACTICAFINAL_PAIS_H

// Incluimos el archivo de cabecera "Punto.h"
#include "Punto.h"

// Utilizamos el espacio de nombres std
using namespace std;

/**
 * @brief T.D.A Pais
 *
 * Clase que representa un país con una posición, un nombre y una bandera.
 *
 *  Para poder usar el TDA Pais se debe incluir el fichero

  \#include <Pais.h>
 */
class Pais {
private:

    /** @brief Objeto de tipo Punto que representa la posición geográfica del país. */
    Punto p;

    /** @brief Nombre del país. */
    string pais;

    /** @brief Ruta o descripción de la bandera del país. */
    string bandera;

public:

    /** @brief Constructor por defecto de la clase Pais. */
    Pais() {}

    /**
     * @brief Método para obtener el objeto Punto que representa la posición geográfica del país.
     * @return Objeto Punto.
     */
    Punto GetPunto() const {
        return p;
    }

    /**
     * @brief Método para obtener el nombre del país.
     * @return Cadena que representa el nombre del país.
     */
    string GetPais() const {
        return pais;
    }

    /**
     * @brief Método para obtener la ruta o descripción de la bandera del país.
     * @return Cadena que representa la ruta o descripción de la bandera.
     */
    string GetBandera() const {
        return bandera;
    }

    /**
     * @brief Sobrecarga del operador < para comparar dos objetos de tipo Pais.
     * @param P Objeto Pais a comparar.
     * @return Verdadero si el país es menor al país P, falso en caso contrario.
     */
    bool operator<(const Pais &P) const {
        return pais < P.pais;
    }

    /**
     * @brief Sobrecarga del operador == para comparar dos objetos de tipo Pais.
     * @param P Objeto Pais a comparar.
     * @return Verdadero si los países son iguales, falso en caso contrario.
     */
    bool operator==(const Pais &P) const {
        return pais == P.pais;
    }

    /**
     * @brief Sobrecarga del operador == para comparar un objeto Pais con un objeto Punto.
     * @param P Objeto Punto a comparar.
     * @return Verdadero si la posición del país es igual al punto P, falso en caso contrario.
     */
    bool operator==(const Punto &P) const {
        return p == P;
    }

    // Declaración de las funciones amigas para sobrecargar operadores de entrada y salida.

    /**
     * @brief Sobrecarga del operador de inserción para leer un objeto de tipo Pais desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param P Objeto de tipo Pais a leer.
     * @return Flujo de entrada actualizado.
     */
    friend istream &operator>>(istream &is, Pais &P);

    /**
     * @brief Sobrecarga del operador de extracción para escribir un objeto de tipo Pais en un flujo de salida.
     * @param os Flujo de salida.
     * @param P Objeto de tipo Pais a escribir.
     * @return Flujo de salida actualizado.
     */
    friend ostream &operator<<(ostream &os, const Pais &P);

};

#endif //PRACTICAFINAL_PAIS_H
