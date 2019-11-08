// g++ get_train.cpp -o get_train && ./get_train
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

int main(){

    all_trains trains;

    ofstream fout;
    ifstream fin;

    fin.open("Trains.dat");
    fin.read((char*)&trains, sizeof(trains));

    for(int i = 0; i < 10; i++) cout << trains.DtoP[i].train_number << " " << trains.DtoP[i].train_name << " " << trains.DtoP[i].jdate << endl; cout << endl;
    for(int i = 0; i < 10; i++) cout << trains.PtoD[i].train_number << " " << trains.PtoD[i].train_name << " " << trains.PtoD[i].jdate << endl; cout << endl;
    // for(int i = 0; i < 10; i++) cout << trains.PtoD[i].train_number << " "; cout << endl;

    fin.close();

}