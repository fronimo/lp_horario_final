#include "init.h"

Init::Init(){};

void Init::execute() //aca se incializa todo lo necesario que el programa vaya a ejecutar..
{
    cout<<"\t\t\t PLANIFICADOR DE REUNIONES"<<endl;
    cout<<"Ingrese Duracion y Nombres de Archivos"<<endl;
    cin>>duracion;
    cin>>a1;
    cin>>a2;

    cout<<duracion<<"-";
    cout<<a1<<"-";
    cout<<a2<<endl;

    Horario_archivo h_a1(a1);
    h_a1.leer_arch();

    Horario_archivo h_a2(a2);
    h_a2.leer_arch();

    compara_sch(h_a1, h_a2);




}

void Init::compara_sch(Horario_archivo a, Horario_archivo b){
    //list<Intervalo> res;
    //comprar los dias (mon, tue)
    // cout<<"h1.dia: "<<h1.dia<<endl;
    //cout<<"h2.dia: "<<h2.dia<<endl;
    list<Schedule*> l1, l2;
    l1=a.l_sch;
    l2=b.l_sch;

    list<Schedule*>::iterator it_shc;
    vector<Horas> tmp;
    list<Schedule*> res;
    //cout<<"tam a "<<a.l_sch.size()<<endl;
    for(it_shc = a.l_sch.begin(); it_shc != a.l_sch.end(); ++it_shc){
        //----
        list<Schedule*>::iterator it_shc2;

        for(it_shc2 = b.l_sch.begin(); it_shc2 != b.l_sch.end(); ++it_shc2){
            if((*it_shc)->nom_dia == (*it_shc2)->nom_dia){

                //cout<<"dias "<<(*it_shc)->nom_dia<<" "<<(*it_shc2)->nom_dia<<endl;

                tmp=f->comparar_dia((*(*it_shc)).p_horas,(*it_shc2)->p_horas);
                //cout<<"aca? ";
                //cout<<tmp.size()<<endl;
                //cout<<((*tmp)[0]).h_ini;
                vector<Horas> pp;

                for(int i = 0; i< tmp.size(); i++){
                    int* rest = new int[2];
                    rest=f->DeductInt(tmp[i].h_ini,tmp[i].m_ini,tmp[i].h_fin,tmp[i].m_fin);
                    Horas h;
                    char* tr= "-99:99";
                    strcat(duracion,tr);
                    h = f->str2objHoras(duracion);
                    //cout<<"h "<<h.h_ini<<" "<<h.m_ini<<endl;
                    //cout<<"r "<<rest[0]<<" "<<rest[1]<<endl;
                    if(rest[0] >= h.h_ini || rest[1] >= h.m_ini){
                            //cout<<" inserto "<<endl;
                        pp.push_back(tmp[i]);
                    }
                }
                vector<Horas>::iterator it_vec;

                tmp=pp;
                for(int i = 0;i < tmp.size(); i++){
                    cout<<tmp[i].h_ini<<":"<<tmp[i].m_ini<<"-"<<tmp[i].h_fin<<":"<<tmp[i].m_fin<<endl;
                }
                Schedule* sch_tmp= new Schedule((*it_shc)->nom_dia,&tmp);
                res.push_back(sch_tmp);

            }
        }

    }




    /*
    if(strcmp(h1.dia, h2.dia) == 0){
        //tomar la hora de inicio del intervalo del 1er archivo con el inter. del 2do archivo(el ke sea mas tarde)
        //h1.h_ini.
        cout<<"\nentro\n";
        list<Intervalo>::iterator it;
        for (it = h1.h_ini.begin(); it != h1.h_ini.end(); ++it){
            cout << ' ' << ((*it).time_ini)[0] <<":"<<((*it).time_ini)[1]<<endl;

            list<Intervalo>::iterator it2;
            for (it2 = h2.h_fin.begin(); it2 != h2.h_fin.end(); ++it){
                cout << ' ' << ((*it2).time_fin)[0] <<":"<<((*it2).time_fin)[1]<<endl;
                Intervalo * tmp;
                if( ((*it).time_ini)[0] < ((*it2).time_fin)[0] ) {
                    tmp = new Intervalo( (*it).time_ini, (*it2).time_fin );
                    int* r = Deduct(tmp->time_ini, tmp->time_fin);
                    if(r[1] >= atoi(h1.dur)) {
                        res.push_back(*tmp);
                    }

                }

            }
        }
    }
    */

}

Init::~Init(){}
