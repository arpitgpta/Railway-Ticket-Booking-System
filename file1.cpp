// g++ file1.cpp -o file1 && ./file1
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct train{

    string jdate;
    string train_name;
    int train_number;

    int seat[40][32][3];    

};

struct all_trains{


    train DtoP[35];
    train PtoD[35];

};

struct station{

    string st_name;
    int st_no;

};

struct all_stations{

    station Stations[16];

};

int main(){


    ofstream fout;
    ifstream fin;
    
    all_trains trains;

    
    for(int i = 0; i < 5; i++){
    
        cout << "i = " << i+1 << endl;

        cin >> trains.DtoP[i].jdate;
        cin >> trains.DtoP[i].train_number;
        getline(cin, trains.DtoP[i].train_name);

        fout.open("train_data.txt", ios::binary);
        fout.write((char*)&trains, sizeof(trains));
        fout.close();

        trains.DtoP[i].jdate = "";
        trains.DtoP[i].train_name = "";
        trains.DtoP[i].train_number = 0;

        fin.open("trian_data.txt", ios::binary);
        fin.read((char*)&trains, sizeof(trains));
        cout << trains.DtoP[i].jdate <<  " ";
        cout << trains.DtoP[i].train_number << " ";
        cout << trains.DtoP[i].train_name << endl;
        fin.close();

    }

    
}