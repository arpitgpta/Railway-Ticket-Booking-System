
#include "Structures.cpp"

class Train {

    private:

        seat* create_seat (int s, int e) {
            seat *st;
            if(s == e)  st = new seat();
            
            else{
                seat* l = create_seat(s, (s+e)/2);
                seat* r = create_seat((s+e)/2+1, e);
                st = new seat(l,r);
            }
            st->from = s;
            st->to = e;
            st->avilable = true;
            return st;
        }

        bool is_available(int from, int to, seat *st, int k){

            
            if(st == NULL )   return true; 

            if(st->from == st->to)    return st->avilable;
            
            else if(to >= st->to && from <= st->from)   return st->avilable;

            else if(st->from > to || st->to < from)    return true;
            
            else if(st->from <= from || st->to >= to){
                bool a = is_available(from, to, st->lch, k+1);
                bool b = is_available(from, to, st->rch, k+1);
                return (a&b);
            }   
            
            return true;
        }

    public:

        Train(){
            
        }

        Train(string date, int no, string name){
            for(int i = 0; i < 40; i++){
                seat *temp = create_seat(1, 16);
                Seats.push_back(temp);
            }
            
            train_name = name;
            train_number = no;
            jdate = date;

        }

        string train_name;
        int train_number;
        string jdate;
        vector<seat*> Seats;

        int available_seats(int from, int to){
            if(from > to) swap(from, to);
            int total_seats = 0;
            deque <int> avl_seat_nos;
            for(int i = 0; i < 40; i++){
                // cout << "calling fun " << endl;
                bool temp = is_available(from, to-1, Seats[i], 0);
                // cout << "temp " << temp << endl;
                if(temp){
                    total_seats++;
                    if((i%8) == 1 || (i%8) == 4 || (i%8) == 7) avl_seat_nos.push_front(i);
                    else avl_seat_nos.push_back(i);
                }
            }
            return total_seats;
        }

        ticket* book(int psngrs, vector<psgr*> psgr_list){
            // this function will book ticket and returns 1.pnr number 2.total ammount 3.list of alloted seats  
            ticket* tkt = new ticket();

            return tkt;
        }

};
