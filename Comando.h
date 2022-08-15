#ifndef COMANDO_H
#define COMANDO_H

#include <fstream>
#include <cstdio>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

typedef struct{
    string Comando = " ";
    string Direccion = " ";
}Parametros;

typedef struct{
    string time = " ";
    string Tamano = " ";
    int id = 0;
}MBR;



class Comando{
    public:
        Parametros param;
        void identificacionCMD(Parametros p);
        void crearArchivo();
        void vertodo();
        void exec(string Direccion);
        void mostrar_struct(MBR ejm);
};

#endif // COMANDO_H