
#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H




#include "imagenES.h"
#include <iostream>
#include "Punto.h"
#include "string"
#include "list"


using namespace std;

/**
  @brief T.D.A. Ruta

  Una instancia del tipo de dato abstracto Ruta nos permite almacenar diferentes puntos junto a un codigo.

  El TDA Ruta proporciona además distintas herramientas para la manipulación de dichas rutas.

  Para poder usar el TDA Ruta se debe incluir el fichero

  \#include <Ruta.h>

**/

class Ruta{

    /**
      @brief string que contiene el codigo de la ruta.

    **/

    string code;

    /**
      @brief Lista que almacena los diferentes puntos de una ruta.

    **/

    list<Punto> puntos;


public:

    /**
     * @brief Constructor por defecto .
     * @post Genera una instancia de la clase Ruta.
     * @return Ruta, el objeto ruta creado.
     */

    Ruta();

    /**
     * @brief Inserta un nuevo punto al inicio de la lista de puntos de la ruta.
     * @param n Punto a insertar.
     * @post El punto n se inserta al inicio de la lista de puntos de la ruta.
     */


    void Insertar(const Punto & n);

    /**
     * @brief Elimina un punto específico de la lista de puntos de la ruta.
     * @param n Punto a eliminar.
     * @post El Punto n , quedara eliminada de la list si existe.
     */

    void Borrar(const Punto & n);

    /**
     * @brief Obtiene el código único asociado a la ruta.
     * @return string, el código de la ruta.
     */

    string getCode()const;


    /**
     * @brief Establece el código de la ruta con el valor proporcionado.
     * @param code Nuevo código para la ruta.
     * @post El código de la ruta se actualiza con el valor proporcionado.
     *
     */


    void SetCode(const string & code);


    /**
     * @brief Sobrecarga el operador de igualdad para comparar dos rutas.
     * @param R Ruta con la que se compara la ruta actual.
     * @return bool, true si las rutas son iguales, false en caso contrario.
     */

    bool operator==(const Ruta & R)const;


    class const_iterator;
    class iterator{
    private:
        list<Punto>::iterator p;
    public:

        /**
	    * @brief Constructor por defecto
		*
		*/

        iterator(){}

        /**
         * @brief Operador de incremento
         *
         * @return Devuelve una referencia a si mismo
         */


        iterator & operator ++(){
            ++p;
            return * this;
        }

        /**
	    * @brief Operador de decremento
		*
		* @return Devuelve una referencia a si mismo
		*/

        iterator & operator --(){
            --p;
            return * this;
        }

        /**
		* @brief Operador de asignación
		*
		* @param it iterator del que asignar
		* @return Devuelve una referencia a si mismo
		*/
        iterator & operator=(const iterator & it) {
            p = it.p;
            return *this;
        }

        /**
		* @brief Operador de igualdad
		*
		* @param it iterator con el que comparar
		* @return true si tienen el mismo valor
		* @return false si no tienen el mismo valor
		*/
        bool operator ==(const iterator  & it){
            return it.p ==p;
        }

        /**
         * @brief Operador de desigualdad
         *
         * @param it iterator con el que comparar
         * @return true si no tienen el mismo valor
         * @return false si tienen el mismo valor
         */
        bool operator !=(const iterator  & it){
            return it.p !=p;
        }

        /**
         * @brief Operador de acceso
         *
         * @return Devuelve una referencia al elemento de la clase Pais sobre el que itera
         */


        const Punto & operator*()const{
            return *p;
        }


        friend class Ruta;
        friend class const_iterator;
    };
    class const_iterator{
    private:
        list<Punto>::const_iterator p;
    public:
        /**
		* @brief Constructor por defecto
		*
		*/
        const_iterator(){}

        /**
         * @brief Constructor a partir de un elemento iterator
         *
         * @param it iterator desde el que construir el nuevo const_iterator
         */
        const_iterator(const iterator & it){
            p=it.p;
        }

        /**
         * @brief Operador de asignación
         *
         * @param it iterator del que asignar
         * @return Devuelve una referencia a si mismo
         */
        const_iterator & operator=(const iterator & it){
            p=it.p;
            return *this;
        }

        /**
         * @brief Operador de incremento
         *
         * @return Devuelve una referencia a si mismo
         */
        const_iterator & operator ++(){
            ++p;
            return * this;
        }

        /**
         * @brief Operador de decremento
         *
         * @return Devuelve una referencia a si mismo
         */
        const_iterator & operator --(){
            --p;
            return * this;
        }

        /**
         * @brief Operador de igualdad
         *
         * @param it const_iterator con el que comparar
         * @return true si tienen el mismo valor
         * @return false si no tienen el mismo valor
         */
        bool operator ==(const const_iterator  & it){
            return it.p ==p;
        }

        /**
         * @brief Operador de desigualdad
         *
         * @param it const_iterator con el que comparar
         * @return true si no tienen el mismo valor
         * @return false si tienen el mismo valor
         */
        bool operator !=(const const_iterator  & it){
            return it.p !=p;
        }

        /**
         * @brief Operador de acceso
         *
         * @return Devuelve una referencia de solo lectura al elemento de la clase Pais sobre el que itera
         */
        const Punto &operator*()const {
            return *p;
        }
        friend class Ruta;

    };



    /**
     * @brief Obtiene un iterador que apunta al inicio de la lista de puntos de la ruta.
     * @return Un iterador al inicio de la lista de puntos.
     */


    iterator begin();

    /**
     * @brief Obtiene un iterador constante que apunta al inicio de la lista de puntos de la ruta.
     * @return Un iterador constante al inicio de la lista de puntos.
     */


    const_iterator begin() const;


    /**
     * @brief Obtiene un iterador que apunta al final de la lista de puntos de la ruta.
     * @return Un iterador al final de la lista de puntos.
     */


    iterator end();

    /**
     * @brief Obtiene un iterador constante que apunta al final de la lista de puntos de la ruta.
     * @return Un iterador constante al final de la lista de puntos.
     */


    const_iterator end() const;

    /**
     * @brief Busca un punto específico en la lista de puntos de la ruta.
     * @param p Punto a buscar.
     * @return Un iterador que apunta al punto encontrado en la lista o al final si no se encuentra.
     */


    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de extracción para leer una instancia de la clase Ruta desde un flujo de entrada.
     *
     * @param is Flujo de entrada desde donde se leerá la ruta.
     * @param R Referencia a un objeto Ruta donde se almacenarán los datos leídos.
     * @post La instancia de la clase Ruta se actualiza con los datos leídos desde el flujo de entrada.
     * @return Una referencia al flujo de entrada actualizado.
     */


    friend istream &operator>>(istream &is, Ruta &R);

    /**
     * @brief Sobrecarga del operador de inserción para imprimir una instancia de la clase Ruta en un flujo de salida.
     * @param os Flujo de salida donde se imprimirá la ruta.
     * @param R Referencia a un objeto Ruta que se imprimirá en el flujo de salida.
     * @return Una referencia al flujo de salida actualizado.
     */


    friend ostream &operator<<(ostream &os, const Ruta &R);


};

#endif //PRACTICAFINAL_RUTA_H