#include "Schedule.h"

Schedule::Schedule()
{
    //ctor
}


Schedule::Schedule(string _nom_dia, vector<Horas>* _p_horas){
    nom_dia=_nom_dia;
    p_horas = new vector<Horas>;
    p_horas=_p_horas;
    //cout<<((*p_horas)[0]).h_ini;

    //no estoy seguro si igualar el vector o hacerle pushback

}

void Schedule::agregar(){

}

void Schedule::mostrar(){
    cout<<this->nom_dia<<" ";

    for(int i = 0; i < (*p_horas).size(); i++){
        cout<<((*p_horas)[i]).h_ini<<":"<<((*p_horas)[i]).m_ini<<"-"<<((*p_horas)[i]).h_fin<<":"<<((*p_horas)[i]).m_fin<<endl;
    }

    //cout<<(*this->p_horas).size();
}

Schedule::~Schedule()
{
    //dtor
}
