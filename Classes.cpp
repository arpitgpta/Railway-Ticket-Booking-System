
#include "Structures.cpp"


class Train {

    private:

        seat* create_seat (int s, int e) {
            seat *st;
            if(s == e){
                st = new seat();
            }
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

        bool is_avilable(int from, int to, seat *st, int k){

            // for(int i = 0; i < k; i++) cout << "\t";
            // cout << "st->from " << st->from << " st->to " << st->to << " from " << from << " to " << to << endl;
            
            if(st == NULL ){
                // for(int i = 0; i < k; i++) cout << "\t";
                // cout << "st == null, returning true" << endl;
                return true;
            } 
            if(st->from == st->to){
                // for(int i = 0; i < k; i++) cout << "\t";
                // cout << "st->from == st->to returning " << st->avilable << endl;
                return st->avilable;
            } 
            
            else if(to >= st->to && from <= st->from){
                // for(int i = 0; i < k; i++) cout << "\t";
                // cout << "to >= st->to && from <= st->from, returning" << st->avilable << endl;
                return st->avilable;
            } 
            else if(st->from > to || st->to < from){
                // for(int i = 0; i < k; i++) cout << "\t";
                // cout << "out of bound returning true" << endl; 
                return true;
            } 
            else if(st->from <= from || st->to >= to){
                bool a = is_avilable(from, to, st->lch, k+1);
                bool b = is_avilable(from, to, st->rch, k+1);
                // for(int i = 0; i < k; i++) cout << "\t";
                // cout << "recursive case a = " << a << " b= " << b << " returning " << (a&b) << endl;
                return (a&b);
            }   
        }

    public:

        Train(string name, string date, int number){
            for(int i = 0; i < 40; i++){
                seat *temp = create_seat(1, 16);
                Seats.push_back(temp);
            }
            
            train_name = name;
            train_jdate = date;
            train_number = number;

        }

        string train_jdate;
        string train_name;
        int train_number;
        vector<seat*> Seats;

        int avilable_seats(int from, int to){
            if(from > to) swap(from, to);
            int total_seats = 0;
            deque <int> avl_seat_nos;
            for(int i = 0; i < 40; i++){
                // cout << "calling fun " << endl;
                bool temp = is_avilable(from, to-1, Seats[i], 0);
                // cout << "temp " << temp << endl;
                if(temp){
                    total_seats++;
                    if((i%8) == 1 || (i%8) == 4 || (i%8) == 7) avl_seat_nos.push_front(i);
                    else avl_seat_nos.push_back(i);
                }
            }
            return total_seats;
        }
};