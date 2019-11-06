
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
