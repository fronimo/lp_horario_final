#ifndef INIT_H
#define INIT_H

//#include <list>
//#include <string.h>

#include "horario_archivo.h"
#include "funciones.h"
//#include "schedule.h"
//#include <fstream>


class Init
{
public:
    char duracion[10]; // = {"00:45 a e"};
    char a1[7]; //contendra el nombre del 1er archivo
    char a2[7]; //contendra el nombre del 2do archivo
    Funciones* f;

    void compara_sch(Horario_archivo a, Horario_archivo b);

    Init();


    void execute(); //aca se incializa todo lo necesario que el programa vaya a ejecutar..

    ~Init();
};

#endif // INIT_H
