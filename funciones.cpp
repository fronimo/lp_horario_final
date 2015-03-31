#include "funciones.h"

Funciones::Funciones()
{
    //ctor
}

Horas Funciones::str2objHoras(char* str_i_h){
    Horas h;
    char* chr = new char[2];

    //hora inicio:
    chr[0] = str_i_h[0];
    chr[1] = str_i_h[1];
    int h_i = atoi(chr);
    h.h_ini = h_i;

    //minuto inicio:
    chr[0] = str_i_h[3];
    chr[1] = str_i_h[4];
    int m_i = atoi(chr);
    h.m_ini = m_i;

    //hora fin:
    chr[0] = str_i_h[6];
    chr[1] = str_i_h[7];
    int h_f = atoi(chr);
    h.h_fin = h_f;

    //minuto fin:
    chr[0] = str_i_h[9];
    chr[1] = str_i_h[10];
    int m_f = atoi(chr);
    h.m_fin = m_f;

    return h;
}

int* Funciones::ToHour(char* h){
    int* hour = new int[2];
    int h1, h2, m1, m2, ht, mt;
    h1=int(h[0]) - 48;
    h2=int(h[1]) - 48;
    m1=int(h[3]) - 48;
    m2=int(h[4]) - 48;
    ht=h1 * 10 + h2;
    mt=m1 * 10 + m2;
    //cout<<h1<<" "<<h2<<" "<<m1<<" "<<m2<<endl;
    hour[0] = ht;
    hour[1] = mt;
    //hour.push_back(ht);
    //hour.push_back(mt);
    return hour;
}

int* Funciones::Deduct(int* a, int* b){
	int* total = new int [2];
	total[0] = b[0] - a[0];
    int tmp;
	tmp = b[1] - a[1];
	if(tmp < 0){
		total[1] = 60 - tmp;
		total[0] = total[0] - 1;
		return total;

	}

	total[1] = tmp;
	return total;
}

int* Funciones::DeductInt(int h1, int m1, int h2, int m2) {     //obtiene la diferencia de 2 horas
    int* total = new int[2];
    int tmp;
    total[0] = h2 - h1;      // resta horas


    tmp = m2 - m1;
    if(tmp<0){
        total[1] = 60 + tmp;
        total[0] = total[0] - 1;
        //cout<<"horas "<<total[0]<<endl;
        //cout<<"minutos "<<total[1];
        return total;
    }

    total[1]=tmp;

    //cout<<"horas "<<total[0]<<endl;
    //cout<<"minutos "<<total[1];

    return total;
}

int* Funciones:: intersecar(Horas x, Horas y){

    int h1,m1,h2,m2;
    int* tt = new int[2];
    int* res = new int [5];

    if((x.h_ini == y.h_ini) && (x.m_ini == y.m_ini)){
        h1 = x.h_ini;
        m1 = x.m_ini;
    }
    else{
        if(x.h_ini == y.h_ini){
            h1 = x.h_ini;
            if(x.m_ini > y.m_ini){
                m1 = x.m_ini;
            }
            else{
                m1 = y.m_ini;
            }
        }
        else{
            if(x.h_ini > y.h_ini){
                h1 = x.h_ini;
                m1 = x.m_ini;
            }
            else{
                h1 = y.h_ini;
                m1 = y.m_ini;
            }
        }
    }

    if((x.h_fin == y.h_fin) && (x.m_fin == y.m_fin)){
        h2 = x.h_fin;
        m2 = x.m_fin;
    }
    else{
        if(x.h_fin == y.h_fin){
            h2 = x.h_fin;
            if(x.m_fin > y.m_fin){
                m2 = y.m_fin;
            }
            else{
                m2 = x.m_fin;
            }
        }
        else{
            if(x.h_fin < y.h_fin){
                h2 = x.h_fin;
                m2 = x.m_fin;
            }
            else{
                h2 = y.h_fin;
                m2 = y.m_fin;
            }
        }
    }

    //cout<<h1<<" "<<m1<<"-"<<h2<<" "<<m2<<endl;

    tt=DeductInt(h1,m1,h2,m2);
   // cout<<*tt<<":"<<*(tt+1)<<endl;

    if((*tt < 0) || (*(tt+1) < 0)){
        res[0] = 0;
    }
    else{
         res[0] = 1;
    }

    res[1] = h1;
    res[2] = m1;
    res[3] = h2;
    res[4] = m2;

    return res;
}

vector<Horas> Funciones::comparar_dia(vector<Horas>* x, vector<Horas>* y){
    vector<Horas> alm_h;
    vector<Horas>* v_hf;
    v_hf= new vector<Horas>;

    //cout<<"tam x "<<(*x).size()<<endl;
    for(int i = 0; i < (*x).size(); i++){
            //cout<<"entro!!!";
        for(int j = 0; j < (*y).size(); j++){
            int* tmp;
            tmp = new int[5];
            tmp = intersecar((*x)[i],(*y)[j]);
            if(tmp[0]){
                Horas hh(tmp[1],tmp[2],tmp[3],tmp[4]);
                alm_h.push_back(hh);
            }
        }
    }

/*
    for(int i = 0; i < alm_h.size(); i++){
            if(alm_h[i].m_ini == 0)
        cout<<alm_h[i].h_ini<<":"<<alm_h[i].m_ini<<"-"<<alm_h[i].h_fin<<":"<<alm_h[i].m_fin<<endl;
    }
*/
    //v_hf=&(alm_h);
    //eturn v_hf;

    return alm_h;
}





/*
list<Intervalo> Funciones::func(char* dia, Horario h1, Horario h2)
{
    list<Intervalo> res;
    //comprar los dias (mon, tue)
    cout<<"h1.dia: "<<h1.dia<<endl;
    cout<<"h2.dia: "<<h2.dia<<endl;

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
    //hacer lo mismo, la hora que sea mas temprano a evaluar(el ke sea mas temprano)
    //con el intervalo armado, comprobar que la hora de inicio sea menor a la hora de fin
    //se restan estas horas, si sale menor, desech el rengo armado y verifica con ottro, caso contrario, continua con dicho inter. armado
    //
}
*/

/*
void Funciones::obtener_horasrio_disp(Schedule a, Schedule b)
{
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

Funciones::~Funciones()
{
    //dtor
}
