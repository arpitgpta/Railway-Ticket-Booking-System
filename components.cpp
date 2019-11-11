
#include <bits/stdc++.h>
using namespace std;
#include <fstream>

ofstream fout;
ifstream fin;

struct station{

    char st_name[25];
    int st_no;
    int km;

};

struct all_stations{
    station Stations[100];
};

all_stations STATIONS;




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

all_trains TRAINS;


struct psgr{

    char name[30];
    int age;
    char gender;
    int seat;

};

struct ticket{

    int from, to;
    int psgr_count;
    psgr psgrs[15];
    int pnr;

    char jdate[15];
    char tr_start_DorP;
    int train_no;

    int amount;

};

struct all_ticket{
    ticket tickets[500];
    int ticket_counter;
};

all_ticket TICKETS;


// functions

void cancel_ticket(int pnr){
            
    // 137
    
}

bool is_available(int from, int to, char start_st, int trno_inlist, int seat_no, int ctr_in){

    // 140
    
    return true;
}

int available_seats(int from, int to, char start_st, int trno_inlist){

    // 140
    
}

int book_ticket(){

    // 141, 137
    
    return 0;
}


void re_read(){

    // 136

}



void re_write(){

     // 136
    
}

void load_data(){
    
    // 136
    
}
