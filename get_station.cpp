// g++ get_station.cpp -o get_station && ./get_station
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct station{

    char st_name[25];
    int st_no;

};

struct all_stations{

    station Stations[16];

};

int main(){

    ofstream fout;
    ifstream fin;

    all_stations st;

    fin.open("Stations.dat");
    fin.read((char*)&st, sizeof(st));

    for(int i = 0; i < 16; i++){
        
        cout << st.Stations[i].st_no;
        cout << " " <<  st.Stations[i].st_name << endl;
    }


    fin.close();

}