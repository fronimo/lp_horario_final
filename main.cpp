#include <iostream>


#include <list>
#include <vector>

#include "horas.h"
#include "schedule.h"
#include "funciones.h"
#include "init.h"
using namespace std;
/*
class Intervalo
{
public:
    int* time_ini; //12:45 ->time_ini[0]=12 y time_ini[1]=45
    int* time_fin;

    Intervalo();
    Intervalo(int* t_ini, int* t_fin)
    {
        time_ini = new int[2];
        time_fin = new int[2];

        time_ini[0] = t_ini[0];
        time_ini[1] = t_ini[1];
        time_fin[0] = t_fin[0];
        time_fin[1] = t_fin[1];

        cout<<"constr time_ini: "<<time_ini[0]<<":"<<time_ini[1]<<endl;
        cout<<"constr time_fin: "<<time_fin[0]<<":"<<time_fin[1]<<endl;
    }

};
*/

int main()
{
    Init o;
    o.execute();

    //int* th = new int[2];
    //th = ToHour("11:46");
    //cout<<th[0]<<":"<<th[1]<<endl;

    //Horario h1(duracion, a1);
    //strcpy_s(h1.dia, "mon");

    //cout<<"h1.dia: "<<h1.dia<<endl;
    //list<Intervalo> e1;
    //e1.push_back(Intervalo(ToHour("11:35"), ToHour("11:47")) );
    //e1.push_back(Intervalo(ToHour("12:15"), ToHour("14:23")) );
    //list<Intervalo> e2;

    //h1.h_ini = e1;

    //list<Intervalo> e2;
    //e2.push_back(new Intervalo(ToHour("11:35"), ToHour("11:47")) );
    //e2.push_back(new Intervalo(ToHour("12:15"), ToHour("14:23")) );

    //Datos_prueba d;

    //list<Intervalo> res = d.func("mon", h1, h1);

    /*
    list<Intervalo>::iterator it;

    for (it = res.begin(); it != res.end(); ++it){
        cout << ' ' << ((*it).time_fin)[0] <<":"<<((*it).time_fin)[1]<<endl;
    }
    cout<<endl;
    */

    //h1.leer();

    //Horario h2(duracion, a2);
    //h2.leer();

    //cout << "Hello world!" << endl;

    return 0;
}
