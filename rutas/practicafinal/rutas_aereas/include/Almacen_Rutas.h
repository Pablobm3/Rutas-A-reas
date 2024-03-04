
#ifndef _ALMACEN_RUTAS_
#define _ALMACEN_RUTAS_

#include "Ruta.h"
#include <set>
#include <map>

using namespace std;

/**
 * @class T.D.A. Almacen_Rutas
 * @brief Facilita el almacenamiento y manejo de un conjunto de Rutas
 *
 * Permite el trabajo con un conjunto de Rutas
 *
 * Para poder usar el TDA Ruta se debe incluir el fichero

  \#include <Ruta.h>
 *
 *
 */
class Almacen_Rutas{
private:

    /**
     * @brief Conjunto de Rutas almacenadas en un mapa con códigos únicos
     *
     * @see Ruta
     */
    map <string, Ruta> rutas;

public:

    /**
     * @brief Obtiene una ruta específica por su código
     *
     * @param codigo Código de la ruta a obtener
     * @return Devuelve un objeto Ruta
     */
    Ruta GetRuta(const string codigo);

    /**
     * @brief Constructor por defecto de la clase Almacen_Rutas
     */
    Almacen_Rutas(){}

    /**
     * @brief Inserta una nueva Ruta en el conjunto de Rutas
     *
     * @param R Ruta a insertar
     */
    void Insertar(const Ruta &R);

    /**
     * @brief Borra una Ruta del conjunto de Rutas
     *
     * @param R Ruta a borrar
     */
    void Borrar(const Ruta &R);

    /**
     * @class iterator
     * @brief Permite recorrer un objeto de la clase Almacen_Rutas de manera más cómoda
     */
    class iterator{
    private:

        /**
         * @brief Iterador de un conjunto de Rutas
         */
        map<string, Ruta>::iterator r;

    public:

        /**
         * @brief Constructor por defecto del iterator
         */
        iterator(){}

        /**
         * @brief Operador de incremento
         *
         * @return Devuelve una referencia a sí mismo
         */
        iterator & operator ++(){
            ++r;
            return * this;
        }

        /**
         * @brief Operador de decremento
         *
         * @return Devuelve una referencia a sí mismo
         */
        iterator & operator --(){
            --r;
            return * this;
        }

        /**
         * @brief Operador de asignación
         *
         * @param it iterator del que asignar
         * @return Devuelve una referencia a sí mismo
         */
        iterator & operator = (const iterator & it) {
            r = it.r;
            return *this;
        }

        /**
         * @brief Operador de igualdad
         *
         * @param it iterator con el que comparar
         * @return true si tienen el mismo valor, false en caso contrario
         */
        bool operator ==(const iterator  & it){
            return it.r ==r;
        }

        /**
         * @brief Operador de desigualdad
         *
         * @param it iterator con el que comparar
         * @return true si no tienen el mismo valor, false en caso contrario
         */
        bool operator !=(const iterator  & it){
            return it.r !=r;
        }

        /**
         * @brief Operador de acceso
         *
         * @return Devuelve una referencia al elemento de la clase Ruta sobre el que itera
         */
        const Ruta & operator*()const{
            return r->second;
        }

        friend class Almacen_Rutas;
        friend class const_iterator;

    };

    /**
     * @class const_iterator
     * @brief Permite recorrer un objeto de la clase Almacen_Rutas de manera más cómoda
     */
    class const_iterator{
    private:

        /**
         * @brief Iterador constante de un conjunto de Rutas
         */
        map<string, Ruta>::const_iterator r;

    public:

        /**
         * @brief Constructor por defecto del const_iterator
         */
        const_iterator(){}

        /**
         * @brief Constructor a partir de un elemento iterator
         *
         * @param it iterator desde el que construir el nuevo const_iterator
         */
        const_iterator(const iterator & it){
            r=it.r;
        }

        /**
         * @brief Operador de asignación
         *
         * @param it iterator del que asignar
         * @return Devuelve una referencia a sí mismo
         */
        const_iterator & operator=(const iterator & it){
            r=it.r;
            return *this;
        }

        /**
         * @brief Operador de incremento
         *
         * @return Devuelve una referencia a sí mismo
         */
        const_iterator & operator ++(){
            ++r;
            return * this;
        }

        /**
         * @brief Operador de decremento
         *
         * @return Devuelve una referencia a sí mismo
         */
        const_iterator & operator --(){
            --r;
            return * this;
        }

        /**
         * @brief Operador de igualdad
         *
         * @param it const_iterator con el que comparar
         * @return true si tienen el mismo valor, false en caso contrario
         */
        bool operator ==(const const_iterator  & it){
            return it.r ==r;
        }

        /**
         * @brief Operador de desigualdad
         *
         * @param it const_iterator con el que comparar
         * @return true si no tienen el mismo valor, false en caso contrario
         */
        bool operator !=(const const_iterator  & it){
            return it.r !=r;
        }

        /**
         * @brief Operador de acceso
         *
         * @return Devuelve una referencia de solo lectura al elemento de la clase Ruta sobre el que itera
         */
        const Ruta &operator*()const {
            return r->second;
        }

        friend class Almacen_Rutas;
    };

    /**
     * @brief Apunta al comienzo de los datos
     *
     * @return Devuelve un iterator sobre el comienzo de los datos
     *
     * @see iterator
     */
    iterator begin();

    /**
     * @brief Apunta al comienzo de los datos
     *
     * @return Devuelve un const_iterator sobre el comienzo de los datos
     *
     * @see const_iterator
     */
    const_iterator begin()const;

    /**
     * @brief Apunta al final de los datos
     *
     * @return Devuelve un iterator sobre el final de los datos
     *
     * @see iterator
     */
    iterator end();

    /**
     * @brief Apunta al final de los datos
     *
     * @return Devuelve un const_iterator sobre el final de los datos
     *
     * @see const_iterator
     */
    const_iterator end()const;

    /**
     * @brief Encuentra una Ruta en el conjunto de rutas actual
     *
     * @param r Ruta a encontrar
     * @return Devuelve un iterator sobre la Ruta r si se encuentra, o end() si no se encuentra
     */
    iterator find(const Ruta &r);

    /**
     * @brief Operador de entrada
     *
     * @param is Flujo de entrada desde el que se van a leer los datos
     * @param R Objeto de la clase Almacen_Rutas en el que se introducen los datos leídos
     * @return Devuelve un flujo de entrada, permitiendo la concatenación de entradas
     */
    friend istream & operator>>(istream & is, Almacen_Rutas & R);

    /**
     * @brief Operador de salida
     *
     * @param os Flujo de salida por el que se van a sacar los datos
     * @param R Objeto de la clase Almacen_Rutas del que se van a leer los datos
     * @return Devuelve un flujo de salida, permitiendo la concatenación de salidas
     */
    friend ostream & operator<<(ostream & os, const Almacen_Rutas &R);
};

#endif // _ALMACEN_RUTAS_
