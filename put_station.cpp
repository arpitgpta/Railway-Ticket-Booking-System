// g++ put_station.cpp -o put_station && ./put_station
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct station{

    char st_name[25];
    int st_no;

};

struct all_stations{

    station Stations[100];

};

int main(){

    ofstream fout;
    ifstream fin;

    all_stations st;


    // fin.open("Stations.dat");
    // fin.read((char*)&st, sizeof(st));

    // for(int i = 0; i < 16; i++){
        
    //     cout << st.Stations[i].st_no;
    //     cout << " " <<  st.Stations[i].st_name << endl;
    // }


    // fin.close();




    // cout << st.Stations[10].st_no << " ___ " << st.Stations[10].st_name << endl;

    // st.Stations[10].st_no = 11;

    fout.open("Stations.dat");

    for(int i = 0; i < 16; i++){
        st.Stations[i].st_no = i+1;
        gets(st.Stations[i].st_name);
    }

    fout.write((char*)&st, sizeof(st));
    fout.close();


    // fin.open("Stations.dat");
    // fin.read((char*)&st, sizeof(st));

    // for(int i = 0; i < 16; i++){
        
    //     st.Stations[i].st_no = i+1;
    //     cout << st.Stations[i].st_no;
    //     cout << " " <<  st.Stations[i].st_name << endl;
    // }


    // fin.close();

}