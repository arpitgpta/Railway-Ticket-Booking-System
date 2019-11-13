
#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#define deb(x) cout << #x << " " << x << endl;
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



int is_available(ticket tkt, int trno_inlist, int seat_no, int ctr_index){
    
    int ans = 0;
    if(tkt.tr_start_DorP == 'd'){
        
        if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] > tkt.to || TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] < tkt.from) ans =  1;
        else if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] == TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1]){
            ans =  TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(tkt.to >= TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] && tkt.from <= TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0]){
            ans =  TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][0] <= tkt.from || TRAINS.DtoP[trno_inlist].seat[seat_no][ctr_index][1] >= tkt.to){
            int a = is_available(tkt, trno_inlist, seat_no, ctr_index*2);
            int b = is_available(tkt, trno_inlist, seat_no, ctr_index*2+1);
            ans =  a&&b;
        }
    }
    else{
        
        if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] > tkt.to || TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] < tkt.from) ans =  1;
        else if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] == TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1]){
            ans =  TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(tkt.to >= TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] && tkt.from <= TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0]){
            ans =  TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][2];
        }
        else if(TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][0] <= tkt.from || TRAINS.PtoD[trno_inlist].seat[seat_no][ctr_index][1] >= tkt.to){
            int a = is_available(tkt, trno_inlist, seat_no, ctr_index*2);
            int b = is_available(tkt, trno_inlist, seat_no, ctr_index*2+1);
            ans =  a&&b;
        }
    }
    return ans;
}

pair<deque<int>, int> available_seats(ticket tkt, int trno_inlist){

    // done-- 140

    deque<int> avl_seats;
    int total = 0;
    for(int i = 0; i < 40; i++) if(is_available(tkt, trno_inlist, i, 1)){
        if(i%7 == 0 || i%7 == 3 || i%7 == 7) avl_seats.push_front(i);
        else avl_seats.push_back(i);
        total++;
    } 
    return make_pair(avl_seats, total);
}

int book_ticket(deque<int> avl_seats){
    // train no (1369+i)*13

    /*
    
        first of all you will get all data at TICKETS.tickets[TICKETS.ticket_counter] 
        now calculate index of train
        with help of from and to deside DtoP or PtoD
        
        now 
        for i in psgn_count:
            deside if you have to give him lower birth or upper 
            for lower pop_front and vise_versa
            now put this desided seat in psgns[i].seat
            and mark on seat in the above desided train -- most horrible

        return TICKETS.ticket_counter++;

    
    
    */

   int tic_counter = TICKETS.ticket_counter ;
   char train_DorP = TICKETS.tickets[TICKETS.ticket_counter].tr_start_DorP ;
//    deb(TICKETS.tickets[TICKETS.ticket_counter].tr_start_DorP);
//    deb((TICKETS.tickets[TICKETS.ticket_counter].tr_start_DorP == 'p'));
   int train_num = TICKETS.tickets[TICKETS.ticket_counter].train_no;
   int train_index = train_num / 13 - 1369 ;
//    cout << "tr no " << train_num << endl; 
//    cout << "ind " << train_index << endl;
   int from = TICKETS.tickets[TICKETS.ticket_counter].from+15;
   int to = TICKETS.tickets[TICKETS.ticket_counter].to+15;

    TICKETS.tickets[tic_counter].amount = from > to ? (from-to)*19*TICKETS.tickets[TICKETS.ticket_counter].psgr_count : (to-from)*19*TICKETS.tickets[TICKETS.ticket_counter].psgr_count;
    // deb((train_DorP == 'p'));

    if(train_DorP == 'p')
    {
        int count_passengers  = TICKETS.tickets[TICKETS.ticket_counter].psgr_count ;

        for(int i = 0; i < count_passengers ; i++){

            char pass_gender = TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].gender;
            int pass_age =  TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].age;

            if(pass_age >= 60 || pass_gender == 'F' || pass_gender == 'f')                
            {
                // cout << "came here" << endl;
                int pass_seatno = avl_seats.front() ;
                avl_seats.pop_front() ;
                TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].seat = pass_seatno+1  ;
                
                TICKETS.tickets[TICKETS.ticket_counter].pnr = 7649239 + TICKETS.ticket_counter ;

                for(int i=to;i<from;i++){
                        TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = 0 ;     // Availability 
                        // deb(TRAINS.PtoD[train_index].seat[pass_seatno][i][2]);
                }   
                // deb(TRAINS.PtoD[train_index].seat[pass_seatno][15][30]);
                // deb(TRAINS.PtoD[train_index].seat[pass_seatno][15][31]);

                for(int i=15;i>0;i--){
                
                    int lchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i][2] ;
                    int rchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i+1][2] ;
                    TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = lchild && rchild ;
                    
                }
                
                for(int i = 1; i < 32; i++) cout << TRAINS.PtoD[train_index].seat[pass_seatno][i][2] << " ";
                cout << TRAINS.PtoD[train_index].jdate << endl;
                cout << TRAINS.PtoD[train_index].train_name << endl;
                cout << TRAINS.PtoD[train_index].train_number/13 - 1369 << endl;
                // cout << "done" << endl;
            }
            else
            {
                // cout << "came here1" << endl;
                int pass_seatno = avl_seats.back() ;
                avl_seats.pop_back() ;
                TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].seat = pass_seatno +1 ;
                TICKETS.tickets[TICKETS.ticket_counter].pnr = 7649239 + TICKETS.ticket_counter ;

                    // deb(pass_seatno);
                    // deb(from);
                    // deb(to);
                for(int i=to;i<from;i++){
                    TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = 0 ;     // Availability 
                    // deb(TRAINS.PtoD[train_index].seat[pass_seatno][i][2]);
                }   

                for(int i=16;i>0;i--){
                    int lchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i][2] ;
                    int rchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i+1][2] ;
                    TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = lchild && rchild ;
                }
                // cout << "done" << endl;
            }
        }

    }
   else
   {
       int count_passengers  = TICKETS.tickets[TICKETS.ticket_counter].psgr_count ;
        for(int i = 0; i < count_passengers ; i++){

            char pass_gender = TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].gender;
            int pass_age =  TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].age;

        if(pass_age >=60 || pass_gender == 'F' || pass_gender == 'f')                
        {
            // cout << "came here" << endl;
            int pass_seatno = avl_seats.front() ;
            avl_seats.pop_front() ;
            TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].seat = pass_seatno + 1 ;
            TICKETS.tickets[TICKETS.ticket_counter].pnr = 7649239 + TICKETS.ticket_counter ;

            for(int i=from;i<to;i++){
                // for(int j=0;j<3;j++){
                // }
                    TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = 0 ;     // Availability 

            }   

            for(int i=16;i>0;i--){
                int lchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i][2] ;
                int rchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i+1][2] ;

                TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = lchild && rchild ;
                
            }
            // cout << "done" << endl;

        }
        else
        {
            // cout << "came here" << endl;
            int pass_seatno = avl_seats.back() ;
            avl_seats.pop_back() ;
            TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].seat = pass_seatno +1 ;
            TICKETS.tickets[TICKETS.ticket_counter].pnr = 7649239 + TICKETS.ticket_counter ;

            for(int i=from;i<to;i++){
                // for(int j=0;j<3;j++){
                // }
                    TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = 0 ;     // Availability 

            }   

            for(int i=15;i>0;i--){
                int lchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i][2] ;
                int rchild = TRAINS.PtoD[train_index].seat[pass_seatno][2*i+1][2] ;

                TRAINS.PtoD[train_index].seat[pass_seatno][i][2] = lchild && rchild ;
                
            }
            // cout << "done" << endl;

        }
    }
    return TICKETS.ticket_counter++ ;
   }
    return 0;
}   


void re_read(){

    fin.open("Trains.dat");
    fin.read((char*)&TRAINS, sizeof(TRAINS));
    fin.close();

    fin.open("tickets.dat");
    fin.read((char*)&TICKETS, sizeof(TICKETS));
    fin.close(); 

    fin.open("tc.txt");
    int tc;
    fin.read((char*)&tc, sizeof(tc));
    fin.close();   
    TICKETS.ticket_counter = tc;

}



void re_write(){

    fout.open("Trains.dat");
    fout.write((char*)&TRAINS, sizeof(TRAINS));
    fout.close();

    fout.open("tickets.dat");
    fout.write((char*)&TICKETS, sizeof(TICKETS));
    fout.close();

    int tc = TICKETS.ticket_counter;
    fout.open("tc.txt");
    fout.write((char*)&tc, sizeof(tc));
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

    fin.open("tc.txt");
    int tc;
    fin.read((char*)&tc, sizeof(tc));
    fin.close();   
    TICKETS.ticket_counter = tc;

}
