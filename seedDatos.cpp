#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "clientes.h"
#include "clientesArchivo.h"
#include "choferes.h"
#include "choferesArchivo.h"
#include "remises.h"
#include "remisesArchivo.h"
#include "viajes.h"
#include "viajesArchivo.h"
#include "pagos.h"
#include "pagosArchivo.h"
#include "calificaciones.h"
#include "calificacionesArchivo.h"
using namespace std;

static void borrarArchivo(const char* nombre){
    remove(nombre);
}

static string id5(char prefijo, int n){
    char buf[6];
    sprintf(buf, "%c%04d", prefijo, n);
    return string(buf);
}

int main(){

    borrarArchivo("clientes.dat");
    borrarArchivo("choferes.dat");
    borrarArchivo("remises.dat");
    borrarArchivo("viajes.dat");
    borrarArchivo("pagos.dat");
    borrarArchivo("calificaciones.dat");

    ClientesArchivo repoClientes;
    ChoferesArchivo repoChoferes;
    RemisesArchivo repoRemises;
    ViajesArchivo repoViajes;
    PagosArchivo repoPagos;
    CalificacionesArchivo repoCalificaciones;

    const char* nombres[] = {
        "Lucia","Mateo","Sofia","Tomas","Valentina","Bruno","Camila","Diego",
        "Elena","Facundo","Gina","Hugo","Irene","Julian","Karina","Lucas",
        "Marina","Nicolas","Olivia","Pablo"
    };
    const char* apellidos[] = {
        "Gomez","Lopez","Fernandez","Rodriguez","Martinez","Perez","Sanchez","Romero",
        "Diaz","Torres","Ruiz","Alvarez","Ramirez","Flores","Acosta","Molina",
        "Castro","Suarez","Rojas","Vega"
    };
    const char* calles[] = {
        "Av Rivadavia 1200","Calle Mitre 450","Av Corrientes 230","Calle Belgrano 88",
        "Av San Martin 910","Calle Lavalle 77","Av Independencia 55","Calle Sarmiento 301",
        "Av Callao 640","Calle Moreno 212"
    };

    string dniClientes[20];
    string dniChoferes[10];

    cout << "Generando clientes..." << endl;
    for(int i = 0; i < 20; i++){
        char dni[9];
        sprintf(dni, "%d", 40000001 + i);
        dniClientes[i] = dni;

        char telefono[12];
        sprintf(telefono, "11400%05d", i + 1);

        char email[50];
        sprintf(email, "cliente%d@mail.com", i + 1);

        Fecha nac(10 + (i % 18), 1 + (i % 12), 1985 + (i % 15));
        Clientes c(dni, nombres[i], apellidos[i], telefono, email, calles[i % 10], nac);

        if(!c.getValido() || !repoClientes.guardar(c)){
            cout << "Error creando cliente " << (i + 1) << endl;
            return 1;
        }
    }

    cout << "Generando choferes..." << endl;
    for(int i = 0; i < 10; i++){
        char dni[9];
        sprintf(dni, "%d", 30000001 + i);
        dniChoferes[i] = dni;

        char telefono[12];
        sprintf(telefono, "11500%05d", i + 1);

        char email[50];
        sprintf(email, "chofer%d@mail.com", i + 1);

        Fecha nac(5 + (i % 20), 1 + (i % 12), 1980 + (i % 12));
        Choferes ch(dni, nombres[i], apellidos[i + 10], telefono, email, calles[i], nac);

        if(!ch.getValido() || !repoChoferes.guardar(ch)){
            cout << "Error creando chofer " << (i + 1) << endl;
            return 1;
        }
    }

    const char* marcas[] = {"Toyota","Ford","Chevrolet","Volkswagen","Renault","Peugeot","Fiat","Nissan","Honda","Hyundai"};
    const char* modelos[] = {"Corolla","Focus","Onix","Gol","Logan","208","Cronos","Versa","Civic","HB20"};

    cout << "Generando remises..." << endl;
    for(int i = 0; i < 10; i++){
        char patente[8];
        sprintf(patente, "ABC%03d", 100 + i);

        Fecha lanz(1 + (i % 28), 1 + (i % 12), 2016 + (i % 8));
        Remises r(patente, marcas[i], modelos[i], dniChoferes[i], lanz, 3 + (i % 4));

        if(!r.getValido() || !repoRemises.guardar(r)){
            cout << "Error creando remis " << (i + 1) << endl;
            return 1;
        }
    }

    cout << "Generando viajes, pagos y calificaciones..." << endl;
    const char* comentarios[] = {
        "Muy buen viaje",
        "Chofer amable",
        "Llego a tiempo",
        "Auto comodo",
        "Servicio correcto",
        "Excelente atencion",
        "Todo perfecto",
        "Buen recorrido",
        "Recomendable",
        "Viaje agradable"
    };

    for(int i = 0; i < 80; i++){
        string idViaje = id5('V', i + 1);
        string dniCliente = dniClientes[i % 20];
        string dniChofer = dniChoferes[i % 10];

        int dia = 1 + (i % 28);
        int mes = 1 + (i % 12);
        int anio = 2020 + (i % 6);
        Fecha fechaViaje(dia, mes, anio);

        Viajes v(idViaje, dniCliente, dniChofer, fechaViaje);
        if(!v.getValido() || !repoViajes.guardar(v)){
            cout << "Error creando viaje " << (i + 1) << endl;
            return 1;
        }

        string idPago = id5('P', i + 1);
        int metodo = 1 + (i % 3);
        float monto = 1500.0f + (i * 75.5f);
        Fecha fechaPago(dia, mes, anio);

        Pagos p(idPago, idViaje, metodo, monto, fechaPago);
        if(!p.getValido() || !repoPagos.guardar(p)){
            cout << "Error creando pago " << (i + 1) << endl;
            return 1;
        }

        string idCalif = id5('C', i + 1);
        int puntaje = 1 + (i % 5);
        Calificaciones c(idCalif, idViaje, puntaje, comentarios[i % 10]);
        if(!c.getValido() || !repoCalificaciones.guardar(c)){
            cout << "Error creando calificacion " << (i + 1) << endl;
            return 1;
        }
    }

    cout << "Listo." << endl;
    cout << "Clientes: " << repoClientes.contarRegistros() << endl;
    cout << "Choferes: " << repoChoferes.contarRegistros() << endl;
    cout << "Remises: " << repoRemises.contarRegistros() << endl;
    cout << "Viajes: " << repoViajes.contarRegistros() << endl;
    cout << "Pagos: " << repoPagos.contarRegistros() << endl;
    cout << "Calificaciones: " << repoCalificaciones.contarRegistros() << endl;

    return 0;
}
