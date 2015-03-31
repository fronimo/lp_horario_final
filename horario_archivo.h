#ifndef HORARIO_ARCHIVO_H
#define HORARIO_ARCHIVO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "schedule.h"
using namespace std;

class Horario_archivo
{
public:
    char file[7];

    Funciones* fun;

    list<Schedule*> l_sch; //la lista objetos Schedule

    //list<Intervalo> h_ini; //lista de intervalos ejm: {(11:30-13_20)->(14:00-14:50)->null)}
    //list<Intervalo> h_fin;

    //list<char*> f_interv; //la lista que guardara los intervalos por separado de f_int_ini
    //list<char*> interv;

    Horario_archivo(char* f_1);

    void leer_arch();

    virtual ~Horario_archivo();

protected:
private:
};

#endif // HORARIO_ARCHIVO_H
