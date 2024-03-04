/**
  * @file rutas_aereas.cpp
  * @brief Fichero con el programa principal y 2 funciones auxiliares
  *
  * Realiza la rotación de las imágenes y la superposición de aviones en el mapa
  *
  * @see Imagen
  * @see Paises
  * @see Almacen_Rutas
  *
  */

#include "imagen.h"
#include "Almacen_Rutas.h"
#include "Paises.h"
#include "Ruta.h"
#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;


/**
 * @brief Función para rotar imágenes
 *
 * @param Io Imagen a rotar
 * @param angulo Ángulo de rotación que se le quiere dar
 * @return Devuelve la imagen rotada un total de angulo ángulos
 */
Imagen Rota(const Imagen & Io,double angulo){
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {

        inter=rcorners[count]*coseno+ccorners[count]*seno;
        if(inter<new_row_min)
            new_row_min=inter;
        if(inter>new_row_max)
            new_row_max=inter;
        inter1=-rcorners[count]*seno+ccorners[count]*coseno;
        if(inter1<new_col_min)
            new_col_min=inter1;
        if(inter1>new_col_max)
            new_col_max=inter1;
    }




    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);

    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++)
    {
        for(int cols=0;cols<newimgcols;cols++)
        {
            float oldrowcos=((float)rows+new_row_min)*cos(-rads);
            float oldrowsin=((float)rows+new_row_min)*sin(-rads);
            float oldcolcos=((float)cols+new_col_min)*cos(-rads);
            float oldcolsin=((float)cols+new_col_min)*sin(-rads);
            float old_row=oldrowcos+oldcolsin;
            float old_col=-oldrowsin+oldcolcos;
            old_row=ceil((double)old_row);
            old_col=ceil((double)old_col);
            if((old_row>=0)&&(old_row<Io.num_filas())&&
               (old_col>=0)&&(old_col<Io.num_cols()))
            {
                Iout(rows,cols)=Io(old_row,old_col);

            }
            else{
                Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
                Iout(rows,cols).transp=0;
            }
        }
    }
    return Iout;

}

/**
 * @brief Pinta un avión en una imágen
 *
 * @param f1 Fila en la que empezar a pintar
 * @param f2 Fila en la que se acaba de pintar
 * @param c1 Columna en la que se empieza a pintar
 * @param c2 Columna en la que se acaba de pintar
 * @param I Imagen que se desea pintar
 * @param avion Imagen del avión a pintar
 * @param mindisf Numero de filas minimo que puede tener el avion a pintar
 * @param mindisc Numero de columnas minimo que puede tener el avion a pintar
 *
 * @pre El parámetro avion tiene que haber pasado por la máscara previamente
 */
void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){

    int fila,col;
    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){

        if (c1!=c2){
            double a,b;
            a= double(f2-f1)/double(c2-c1);
            b= f1-a*c1;
            col = (int)(c1+c2)/2;
            fila = (int)rint(a*col+b);
        }
        else{
            col = c1;
            fila = (f1+f2)/2;
        }


        double angulo = atan2((f2-f1),(c2-c1));
        Imagen Irota=Rota(avion,angulo);

        I.PutImagen(fila,col,Irota);

        angulo = atan2((f2-fila),(c2-col));
        Irota=Rota(avion,angulo);

        I.PutImagen(f2,c2,Irota);
        angulo = atan2((fila-f1),(col-c1));
        Irota=Rota(avion,angulo);

        I.PutImagen(f1,c1,Irota);


    }

}


int main(int argc, char * argv[]) {
    if (argc != 7) {
        cout << "Los parametros son:" << endl;
        cout << "1.-Fichero con la informacion de los paises" << endl;
        cout << "2.-Nombre de la imagen con el mapa del mundo" << endl;
        cout << "3.-Directorio con las banderas" << endl;
        cout << "4.-Fichero con el almacen de rutas" << endl;
        cout << "5.- Nombre de la imagen con el avion" << endl;
        cout << "6.- Nombre de la imagen de la mascara del avion" << endl;

        return 0;
    }




    Almacen_Rutas almacen;
    string code_ruta;
    Imagen mapa;
    Paises paises_map;

    ifstream rutas(argv[4]);
    rutas >> almacen;
    cout << almacen;



    cout << "Introduce uno de los códigos de ruta que aparecen por pantalla" << endl;
    cin >> code_ruta;
    Ruta cogida = almacen.GetRuta(code_ruta);
    cout << cogida << endl;


    mapa.LeerImagen(argv[2]);


    ifstream paises(argv[1]);


    cout << paises_map ;

    string directorioBanderas = argv[3];
    Imagen imagenAvion;
    imagenAvion.LeerImagen(argv[5], argv[6]);

    int numFilas, numColumnas;
    numFilas = mapa.num_filas();
    numColumnas = mapa.num_cols();

    Ruta::iterator iteradorRuta = cogida.begin();
    while (iteradorRuta != --(cogida.end())) {
        Punto punto1, punto2;
        punto1 = *iteradorRuta;
        ++iteradorRuta;
        punto2 = *iteradorRuta;

        string banderaPunto1 = (*(paises_map.find(punto1))).GetBandera();
        string banderaPunto2 = (*(paises_map.find(punto2))).GetBandera();

        Imagen imagenBanderaPunto1;
        Imagen imagenBanderaPunto2;

        string pathImagenBanderaPunto1 = directorioBanderas + '/' + banderaPunto1;
        string pathImagenBanderaPunto2 = directorioBanderas + '/' + banderaPunto2;

        const char *pathp1 = pathImagenBanderaPunto1.c_str();
        const char *pathp2 = pathImagenBanderaPunto2.c_str();

        imagenBanderaPunto1.LeerImagen(pathp1);
        imagenBanderaPunto2.LeerImagen(pathp2);

        double col1, col2, fil1, fil2;


        col1 = (numColumnas / 360.0) * (180 + punto1.GetLongitud());
        col2 = (numColumnas / 360.0) * (180 + punto2.GetLongitud());
        fil1 = (numFilas / 180.0) * (90 - punto1.GetLatitud());
        fil2 = (numFilas / 180.0) * (90 - punto2.GetLatitud());

        double anguloRotar = atan2(fil2 - fil1, col2 - col1) + M_PI;

        Imagen avionRotado = Rota(imagenAvion, anguloRotar);

        mapa.PutImagen(fil1, col1, imagenBanderaPunto1, BLENDING);
        mapa.PutImagen(fil2, col2, imagenBanderaPunto2, BLENDING);
        mapa.PutImagen(fil1, col1, avionRotado, BLENDING);
        mapa.PutImagen(fil2, col2, avionRotado, BLENDING);
        mapa.PutImagen((fil2 + fil1) / 2, (col2 + col1) / 2, avionRotado);
    }

    mapa.EscribirImagen("maparuta1-2.ppm");

    return 0;

}