#include "imagenES.h"
#include <iostream>
#include "Punto.h"
#include "string"
#include "list"
#include "Ruta.h"
#include <limits>

using namespace std;

Ruta::Ruta() {

    code="";

}


void Ruta::Insertar(const Punto & n){

    puntos.push_front(n);

}
void Ruta::Borrar(const Punto & n){

    Ruta::iterator it;
    it= find(n);

    if(it != end())
        puntos.erase(it.p);

}


string Ruta::getCode()const{

    return code;

}

void Ruta::SetCode(const string & code){

    this->code=code;
}

bool Ruta::operator==(const Ruta & R)const{

    if(code != R.getCode())
        return false;

    bool soniguales= equal(puntos.begin(),puntos.end(),R.puntos.begin(),R.puntos.end());

    if(!soniguales)
        return false;

    return true;
}


Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.begin();
    return it;
}
Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}
Ruta::const_iterator Ruta::end()const{
    const_iterator it;
    it.p = puntos.end();
    return it;
}


Ruta::iterator Ruta::find(const Punto &p){
    iterator it;
    list<Punto>::iterator i;
    for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

istream & operator>>(istream & is, Ruta & R){

    int size=0;
    Punto p;
    string cod;

    char letra;
    int numero;

    is >> letra;
    is >> numero;

    cod = letra + to_string(numero);

    R.SetCode(cod);

    is >> size ;

    for(int i =0 ; i < size ; i++){

        is >> p;
        R.Insertar(p);

    }

    is.ignore(numeric_limits<streamsize>::max(), '\n');

    return is;
}



ostream & operator<<(ostream & os, const Ruta & r){

    os << r.code << "\t";

    list<Punto>::const_iterator it;

    for (it = r.puntos.cbegin(); it != r.puntos.cend(); ++it)
        os << *it;

    return os;
}



