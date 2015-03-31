#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <vector>

#include "Horas.h"

using namespace std;

class Schedule
{
    public:
    Schedule();
    Schedule(string, vector<Horas>* );
    string nom_dia;
    vector<Horas> v_horas;
    vector<Horas>* p_horas;

    Schedule* p_sch;
    vector<Schedule> v_sch;
    void agregar();
    void mostrar();

        virtual ~Schedule();
    protected:
    private:
};

#endif // SCHEDULE_H
