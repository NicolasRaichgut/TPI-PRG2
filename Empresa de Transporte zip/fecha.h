#pragma once

class Fecha {
private:
    int dia;
    int mes;
    int anio;
    bool esBisiesto(int anio)const;
    int diasEnMes(int mes, int anio)const;
    bool esFechaValida(int d, int m, int a)const;

public:
    Fecha();
    Fecha(int d, int m, int a);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void setFecha(int d, int m, int a);
    void mostrar();
    void sumarDias(int dias);
    void ponerFechaActual();
};

