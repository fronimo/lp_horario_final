#ifndef FUNCIONES_H
#define FUNCIONES_H

//#include "schedule.h"

#include <stdlib.h>


#include <vector>
#include <iostream>
#include <string>
#include "horas.h"

using namespace std;
//class Horario_archivo;
class Funciones
{
    public:

    //void obtener_horasrio_disp(Schedule a, Schedule b);
    //list<Intervalo> func(char* dia, Horario h1, Horario h2)
    int* Deduct(int* a, int* b);
    int* ToHour(char* h);
    Horas str2objHoras(char* str_i_h);
    int* DeductInt(int h1, int m1, int h2, int m2);
    int* intersecar(Horas x, Horas y);
    vector<Horas> comparar_dia(vector<Horas>* x, vector<Horas>* y);

    Funciones();
    ~Funciones();

    protected:
    private:
};

#endif // FUNCIONES_H
