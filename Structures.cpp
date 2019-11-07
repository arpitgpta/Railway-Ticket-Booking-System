
#include <bits/stdc++.h>
using namespace std;


struct station{

    int st_no;
    string st_name;
    int km;
    station(int no, string name, int dis){
        st_name = name;
        st_no = no;
        km = dis;
    }
};


struct seat{

    public:
        seat(){
            // cout << "seat called" << endl;
            lch = rch = NULL;
            avilable = true;
        }

        seat(seat *l, seat *r){
            // cout << "seat2 called" << endl;
            lch = l;
            rch = r;
        }

        bool avilable;
        int from;
        int to;
        seat *lch;
        seat *rch;

};

struct psgr{

    psgr(string n, int a, char g){
        name = n;
        age = a;
        gender = g;
    }

    string name;
    int age;
    char gender;

};

struct ticket{

    int pnr;
    int ammount;
    
    string train_name;
    string jdate;

    int psgrs;
    vector<psgr*> psgr_list;
    
    vector<int> seats;

};

vector<ticket*> booked_tickets;
