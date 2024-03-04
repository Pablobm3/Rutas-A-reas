//
// Created by pablo on 13/12/23.
//

#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include "Pais.h"

#include <set>
using namespace std;

/**
 * @brief T.D.A Paises
 *
 * Clase que representa un conjunto de países
 *
 * Para poder usar el TDA Paises se debe incluir el fichero
 *
 * \#include <Paises.h>
 *
 * @see Pais
 */
class Paises{
private:
    /** @brief Conjunto de países representado como un set.
     * @see Pais*/
    set<Pais> datos;
public:
    /** @brief Constructor por defecto de la clase Paises. */
    Paises(){}

    /**
     * @brief Inserta un país en el conjunto.
     * @param P Objeto de tipo Pais a insertar en el conjunto.
     */
    void Insertar(const Pais &P);

    /**
     * @brief Borra un país del conjunto.
     * @param P Objeto de tipo Pais a borrar del conjunto.
     */
    void Borrar(const Pais &P);

    /** @brief Clase iterator para iterar sobre los elementos del conjunto. */
    class iterator{
    private:
        set<Pais>::iterator p;
    public:
        /** @brief Constructor por defecto del iterator. */
        iterator(){}

        /** @brief Operador de incremento. */
        iterator & operator ++(){
            ++p;
            return * this;
        }

        /** @brief Operador de decremento. */
        iterator & operator --(){
            --p;
            return * this;
        }

        /** @brief Operador de asignación. */
        iterator & operator=(const iterator & it) {
            p = it.p;
            return *this;
        }

        /** @brief Operador de igualdad. */
        bool operator ==(const iterator  & it){
            return it.p ==p;
        }

        /** @brief Operador de desigualdad. */
        bool operator !=(const iterator  & it){
            return it.p !=p;
        }

        /** @brief Operador de acceso. */
        const Pais & operator*()const{
            return *p;
        }

        friend class Paises;
    };

    /** @brief Clase const_iterator para iterar sobre los elementos del conjunto de forma constante. */
    class const_iterator{
    private:
        set<Pais>::const_iterator p;
    public:
        /** @brief Constructor por defecto del const_iterator. */
        const_iterator(){}

        /** @brief Constructor a partir de un elemento iterator. */
        const_iterator(const iterator & it){
            p=it.p;
        }

        /** @brief Operador de asignación. */
        const_iterator & operator=(const iterator & it){
            p=it.p;
            return *this;
        }

        /** @brief Operador de incremento. */
        const_iterator & operator ++(){
            ++p;
            return * this;
        }

        /** @brief Operador de decremento. */
        const_iterator & operator --(){
            --p;
            return * this;
        }

        /** @brief Operador de igualdad. */
        bool operator ==(const const_iterator  & it){
            return it.p ==p;
        }

        /** @brief Operador de desigualdad. */
        bool operator !=(const const_iterator  & it){
            return it.p !=p;
        }

        /** @brief Operador de acceso. */
        const Pais &operator*()const {
            return *p;
        }

        friend class Paises;
    };

    /** @brief Devuelve un iterator al primer elemento del conjunto. */
    iterator begin();

    /** @brief Devuelve un const_iterator al primer elemento del conjunto (constante). */
    const_iterator begin()const;

    /** @brief Devuelve un iterator al último elemento del conjunto. */
    iterator end();

    /** @brief Devuelve un const_iterator al último elemento del conjunto (constante). */
    const_iterator end()const;

    /**
     * @brief Busca un país en el conjunto por su posición geográfica.
     * @param p Objeto de tipo Punto que representa la posición geográfica.
     * @return Iterator al país encontrado, o end() si no se encuentra.
     */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de inserción para leer un objeto de tipo Paises desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Objeto de tipo Paises a leer.
     * @return Flujo de entrada actualizado.
     */
    friend istream & operator>>(istream & is, Paises & R);

    /**
     * @brief Sobrecarga del operador de extracción para escribir un objeto de tipo Paises en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Objeto de tipo Paises a escribir.
     * @return Flujo de salida actualizado.
     */
    friend ostream & operator<<(ostream & os, const Paises &R);

    /**
     * @brief Busca un país en el conjunto por su nombre.
     * @param p Objeto de tipo Pais que se busca.
     * @return Iterator al país encontrado, o end() si no se encuentra.
     */
    iterator find(const Pais &p);
};

#endif //PRACTICAFINAL_PAISES_H
