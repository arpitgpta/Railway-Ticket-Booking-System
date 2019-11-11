
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

    // 136, 137

    // remove from ticket list
    // unmark in train seat segment tree


}

int is_available(ticket tkt, int trno_inlist, int seat_no, int ctr_index){
    
    // done -- 140

    if(tkt.tr_start_DorP == 'd'){
        if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] == TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1]){
            return TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(tkt.to >= TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] && tkt.from <= TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0]){
            return TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] > tkt.to || TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] < tkt.from) return 1;
        else if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] <= tkt.from || TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] >= tkt.to){
            int a = is_available(tkt, trno_inlist, seat_no, ctr_index*2);
            int b = is_available(tkt, trno_inlist, seat_no, ctr_index*2+1);
            return a&&b;
        }
    }
    else{
        if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] == TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1]){
            return TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(tkt.to >= TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] && tkt.from <= TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0]){
            return TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] > tkt.to || TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] < tkt.from) return 1;
        else if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] <= tkt.from || TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] >= tkt.to){
            int a = is_available(tkt, trno_inlist, seat_no, ctr_index*2);
            int b = is_available(tkt, trno_inlist, seat_no, ctr_index*2+1);
            return a&&b;
        }
    }    
    return 1;
}

pair<deque<int>, int> available_seats(ticket tkt, int trno_inlist){

    // done-- 140

    deque<int> avl_seats;
    int total = 0;
    for(int i = 0; i < 40; i++) if(is_available(tkt, trno_inlist, i, 1)){
        if(i%7 == 0 || i%7 == 3 || i%7 == 7) avl_seats.push_front(i);
        total++;
    } 
    return make_pair(avl_seats, total);
}

int book_ticket(deque<int> avl_seats, int trno_inseq){

    // 138, 141

    // mark in train
    // allot seat
    // generate pnr
    // calculate amount

    return 0;
}


void re_read(){

    fin.open("Trains.dat");
    fin.read((char*)&TRAINS, sizeof(TRAINS));
    fin.close();

    fin.open("tickets.dat");
    fin.read((char*)&TICKETS, sizeof(TICKETS));
    fin.close();    

}



void re_write(){

    fout.open("Trains.dat");
    fout.write((char*)&TRAINS, sizeof(TRAINS));
    fout.close();

    fout.open("tickets.dat");
    fout.write((char*)&TICKETS, sizeof(TICKETS));
    fout.close();

}

void load_data(){

    fin.open("Stations.dat");
    fin.read((char*)&STATIONS, sizeof(STATIONS));
    fin.close();
    
    fin.open("Trains.dat");
    fin.read((char*)&TRAINS, sizeof(TRAINS));
    fin.close();

    fin.open("tickets.dat");
    fin.read((char*)&TICKETS, sizeof(TICKETS));
    fin.close();

}
