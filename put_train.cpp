// g++ put_train.cpp -o put_train && ./put_train
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct train{

    char jdate[15];
    char train_name[35];
    int train_number;

    int seat[40][32][3];    

};

struct all_trains{


    train DtoP[60];
    train PtoD[60];

};

all_trains trains;
// complete it
void set_train(char start_st, int trno_in_list, int no, char name[], char date[]){

    ofstream fout;
    ifstream fin;

    fin.open("Trains.dat");
    fin.read((char*)&trains, sizeof(trains));

    if(start_st == 'd' || start_st == 'D'){

        strcpy(trains.DtoP[trno_in_list].jdate,date);

    }
    else{

    }



    fout.open("Trains.dat");
    fout.write((char*)&trains, sizeof(trains));
    fout.close();


}


int main(){


    ofstream fout;
    ifstream fin;

    fin.open("Trains.dat");
    fin.read((char*)&trains, sizeof(trains));

    for(int i = 0; i < 10; i++){
        cout << i << endl;
        gets(trains.DtoP[i].jdate);
    }

    cout << endl << endl;
    
    // for(int i = 0; i < 10; i++){
    //     cout << i << endl;
    //     gets(trains.PtoD[i].jdate);
    // }



    fout.open("Trains.dat");
    fout.write((char*)&trains, sizeof(trains));
    fout.close();



}