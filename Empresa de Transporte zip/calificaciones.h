#pragma once
#include <string>

class Calificaciones{

  public:

    //CONSTRUCTORES
    Calificaciones();
    Calificaciones(std::string id, std::string idViaje, int puntaje, std::string comentario);

    //GETTERS
    const char* getId() const;
    const char* getIdViaje() const;
    int getPuntaje() const;
    const char* getComentario() const;
    bool getEliminado() const;
    bool getValido() const;

    //SETTERS
    bool setId(std::string id);
    bool setIdViaje(std::string idViaje);
    bool setPuntaje(int puntaje);
    bool setComentario(std::string comentario);

    void eliminar();
    bool cargar();
    void mostrar();

  private:

    char _id[6];
    char _idViaje[6];
    int _puntaje;
    char _comentario[120];
    bool _eliminado;
    bool _valido;

};
