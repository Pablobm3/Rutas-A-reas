//
// Created by pablo on 12/12/23.
//

#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H



#include <iostream>

using namespace std;

class Punto{
    private:

        double latitud;

        double longitud;

        char separador;

    public:

        double GetLatitud()const{
            return latitud;
        }

        double GetLongitud()const{
            return longitud;
        }

        Punto(){}

        Punto(double lat,double lon,char sep){
            latitud = lat;
            longitud = lon;
            separador = sep;
        }

        Punto(const Punto &p){
            latitud=p.latitud;
            longitud=p.longitud;
            separador=p.separador;
        }


        bool operator==(const Punto & p) const {
            return (latitud == p.latitud && longitud == p.longitud && separador == p.separador);
        }

        bool operator<(const Punto &p)const{
            return (latitud < p.latitud);
        }

        bool operator>(const Punto &p)const{
            return (latitud > p.latitud);
        }

        friend ostream & operator<<(ostream &os,const Punto &p){
            os << "( " << p.latitud << " , " << p.longitud << " ) " << p.separador;
            return os;
        }

        friend istream & operator>>(istream &is,Punto &p){

            is.ignore(1000 , '(');
            is >> p.latitud;
            is.ignore(1000 , ',');
            is >> p.longitud;
            is.ignore(1000 , ')');
            p.separador = ' ';
            return is;

        }



};

#endif //PRACTICAFINAL_PUNTO_H