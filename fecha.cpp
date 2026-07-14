#include <iostream>
#include "Fecha.h"
#include <ctime>
using namespace std;

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 1;
}

Fecha::Fecha(int d, int m, int a) {
    if(esFechaValida(d, m, a)){
        dia = d;
        mes = m;
        anio = a;
    } else {
        dia = 1;
        mes = 1;
        anio = 1;
    }
}

int Fecha::getDia()const{
    return dia;
}

int Fecha::getMes()const{
    return mes;
}

int Fecha::getAnio()const{
    return anio;
}

void Fecha::setFecha(int d, int m, int a){
    if(esFechaValida(d, m, a)){
        dia=d;
        mes=m;
        anio=a;
    } else{
        dia = 1;
        mes = 1;
        anio = 1;
    }
}

bool Fecha::esBisiesto(int anio)const{
    return (anio%4==0 && anio%100!=0) || (anio%400==0);
}

int Fecha::diasEnMes(int mes, int anio)const{
    switch(mes){
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return esBisiesto(anio) ? 29 : 28;
        default:
            return 0;
    }
}

bool Fecha::esFechaValida(int d, int m, int a)const{
    if(a < 1 || m < 1 || m > 12) {
            return false;
    }
    if(d < 1 || d > diasEnMes(m, a)) {
            return false;
    }
    return true;
}

void Fecha::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::sumarDias(int dias){
    dia+=dias;

    while(dia>diasEnMes(mes, anio)){
        dia-=diasEnMes(mes, anio);
        mes++;

        if(mes>12){
            mes=1;
            anio++;
        }
    }
}
void Fecha::ponerFechaActual(){

    time_t t = time(nullptr);
    tm* hoy = localtime(&t);

    dia = hoy->tm_mday;
    mes = hoy->tm_mon + 1;
    anio = hoy->tm_year + 1900;
}
