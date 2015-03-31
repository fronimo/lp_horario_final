#include "horario_archivo.h"

Horario_archivo::Horario_archivo(char* file)
{
    strcpy(this->file, file);
    //f = new Funciones;
}

void Horario_archivo::leer_arch()
{
    char dia[5]; //mon, tue..
    char f_int_line[150]; //el buffer que captura en una linea los intervalos, del archivo


    strcat(file, ".txt");
    cout<<"file: "<<file<<endl;
    char c; //para iterar el buffer
    char str_interval[20]; //contendra un intervalo
    ifstream f1(file);

    while(!f1.eof() ){
        vector<Horas>* v_h; //puntero de vector de horas, luego se separa memoria para el objeto v_h
        Schedule* sch; //puntero a Schedule, luego se separa memoria para el objeto sch
        f1.getline(dia, 5, ' ');
        f1.getline(f_int_line, 150, '\n');
        //cout<<str_intervalos_horas<<", "<<f_int_line<<"\n";
        v_h = new vector<Horas>;

        for(int i = 0, j = 0; f_int_line[i] != '\0' ; i++, j++){
            if(f_int_line[i] != ' ' && f_int_line[i+1] != '\0')
                str_interval[j] = f_int_line[i];
            else{
                if(f_int_line[i+1] == '\0'){
                    str_interval[j] = f_int_line[i];
                    str_interval[j+1] = '\0';
                }
                else
                    str_interval[j] = '\0';
                j = -1;

                Horas h = fun->str2objHoras(str_interval);
                v_h->push_back(h); //inserta un objeto de horas en el vector de horas;

                str_interval[0] = '\0';
            }

        }
        string s(dia);

        sch = new Schedule(s, v_h); //crea espacio en memoria a sch, conteniendo el strins s y el puntero a vecotr de Horas..
        //sch->agregar2map(s, v_h); //en la nueva clase shcedule no se ha considerado esta funcion ..
        //cambiar por una instruccion situada aqui que añada  la lista de objetos Schedule
        l_sch.push_back(sch); //inserta en la lista de Schedule

        //para comprobar ke ha insertado los intervalos de horas sin problemas:
/*
        list<Schedule*>::iterator it;
        for (it = l_sch.begin(); it != l_sch.end(); ++it){
            cout<< (*it)->nom_dia <<' ';


            vector<Horas>* v_h_tmp = (*it)->p_horas;//comentar con /-

            for (int i = 0;i < (signed)(*it)->p_horas->size(); ++it){
                cout<< (*it) <<' ';
            }
            //comentar con -/
            cout<<endl;
        }
        */


    }

    //list<char*>::iterator it;
    //for (it = interv.begin(); it != interv.end(); ++it){
    //    cout << '; ' << (*it) <<endl;
    //}
}

Horario_archivo::~Horario_archivo()
{
    //dtor
}
