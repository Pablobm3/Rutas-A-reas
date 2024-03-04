
#ifndef PRACTICAFINAL_IMAGEN_H
#define PRACTICAFINAL_IMAGEN_H
#include "imagenES.h"
#include <iostream>


enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;

struct Pixel{
    unsigned char r,g,b;
    unsigned char transp; //0 no 255 si
};

/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes de intensidades.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <Imagen.h>

**/

class Imagen{
private:
    /**
      @brief Puntero a la imagen almacenada data apunta a un array-2D dinámico de pixels que contiene la imagen en sí.

    **/

    Pixel ** data;

    /**

     @brief nc es el numero de columnas de la imagen y nf, el numero de filas de la imagen

     */

    int nf,nc;

    /**
      * @brief Borra una imagen
      *
      * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
      * Si la imagen estaba vacía no hace nada .
      */

    void Borrar();


    /**
      @brief Copy una imagen .
      @param I Referencia a la imagen original que vamos a copiar
      @pre Asume que no hay memoria reservada o se ha llamado antes a Borrar()
      @pre Asume this != &orig
    **/

    void Copiar(const Imagen &I);

public:

    /**
     * @brief Constructor por defecto .
     * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
     * @return Imagen, el objeto imagen creado.
     */

    Imagen();

    /**
      * @brief Constructor con parámetros.
      * @param f Número de filas de la imagen.
      * @param c Número de columnas de la imagen.
      * @pre n fils > O Y n_cols > O
      * @post La imagen creada es de n_fils y n_cols columnas. Estará inicializada con un color blanco.
      * @return Imagen, el objeto imagen creado.
      */

    Imagen(int f,int c);


    /**
      * @brief Constructor de copias.
      * @param I Referencia a la imagen original que se quiere copiar.
      * @return Imagen, el objeto imagen creado.
      */


    Imagen(const Imagen & I);


    /**
      * @brief Operador de asignación .
      * @param I Referencia a la imagen original que desea copiarse.
      * @return Una referencia al objeto imagen modificado.
      * @post Borra cualquier información que contuviera previamente la imagen que llama al operador de asignación.
      */

    Imagen & operator=(const Imagen & I);


    /**
      * @brief Operador de tipo destructor.
      * @return void
      * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
      */

    ~Imagen();


    /**
     * @brief Accede al píxel en la posición especificada.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia al píxel en la posición (i, j).
     */

    Pixel & operator ()(int i,int j);

    /**
     * @brief Accede al píxel en la posición especificada de forma constante.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia al píxel en la posición (i, j).
     */

    const Pixel & operator ()(int i,int j)const;

    /**
 * @brief Escribe la imagen en archivos PPM y PGM.
 *
 * Este método toma la información de la imagen y la escribe en dos archivos diferentes:
 * - Un archivo PPM que contiene los componentes RGB de la imagen.
 * - Un archivo PGM que contiene la información de transparencia (si existe).
 *
 * @param nombre Nombre del archivo PPM.
 */

    void EscribirImagen(const char * nombre);


    /**
 * @brief Lee una imagen desde archivos PPM y PGM.
 *
 * Este método lee dos archivos diferentes:
 * - Un archivo PPM que contiene los componentes RGB de la imagen.
 * - Un archivo PGM que contiene la información de transparencia (si existe).
 *
 * @param nombre Nombre del archivo PPM.
 * @param nombremascara Nombre del archivo PGM (máscara).
 */

    void LeerImagen (const char *nombre,const string &nombremascara="");


  /**
 * @brief Limpia la transparencia de todos los píxeles en la imagen actual.
 *
 * @post Este método establece la transparencia de todos los píxeles en la imagen actual a cero.
 */

    void LimpiarTransp();


    /**
      * @brief Filas de la imagen .
      * @return El número de filas de la i magen.
      * @post la imagen no se modifica.
      */

    int num_filas()const{return nf;}



    /**
      * @brief Columnas de la imagen.
      * @return El número de columnas de la imagen.
      * @post la imagen no se modifica.
      */

    int num_cols()const{return nc;}




    /**
 * @brief Pega una imagen sobre la imagen actual en la posición especificada.
 Este método pega la imagen 'I' sobre la imagen actual ('*this') comenzando desde la posición (posi, posj).
 La forma en que se realiza el pegado depende del tipo de pegado especificado.

 * @param posi Fila de inicio en la imagen actual.
 * @param posj Columna de inicio en la imagen actual.
 * @param I Imagen a pegar sobre la imagen actual.
 * @param tippegado Tipo de pegado (OPACO o TRANSLUCIDO).
 */


    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

/**
    * @brief Genera una imagen a partir de otra
    * @param posi fila superior izquierda de la imagen
    * @param posj columna superior izquierda de la imagen
    * @param dimi altura de la nueva imagen
    * @param dimj anchura de la nueva imagen
    * @pre La suma de las fila dada y la altura no puede superar las filas de la imagen inicial
    * @pre La suma de la columna dada y la anchura no puede superar el las columnas de la imagen inicial
    * @return la subimagen
    * @post Se creara una nueva imagen a partir de la anterior
    */

    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};










#endif //PRACTICAFINAL_IMAGEN_H
