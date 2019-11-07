// g++ test.cpp -o test && ./test
#include "FileManager.cpp"

/*

    our final user experiance will be:

        1. we will display station code with station name

        2. user will give starting and ending journey stations
        3. user will give journy date(one of next five days)
        
        4. we will display trains no + train name + avalibility

        5. user will give train number
        6. user will give no of passenger
            6.1 user will give one by one detail(name+age+gender) of every passenger

        7. user will enter transition id

        8. we will give alloted seat numbers
        

*/

void cancel_ticket(int pnr){
    
    for(auto itr = booked_tickets.begin(); itr < booked_tickets.end(); itr++){
        if((*itr)->pnr == pnr){
            // cancel here


            
        }
        break;
    }

}

int main(){

    DataCenter *dc = new DataCenter(); 
    vector<station*> Stations = dc->Stations;
    
    int from, to;
    string jdate;
    int selected_train, passengers;

    cout << "Welcome to Railway Ticket Booking System" << endl;
    
    cout << "Stations:" << endl << "Station code    Station name" << endl;     
    for(int i = 0; i < 16; i++){
        cout << Stations[i]->st_no << ".\t\t" << Stations[i]->st_name << endl;
    }
    
    int DtoP_trains = dc->delhi_patna_trains.end() - dc->delhi_patna_trains.begin();
    int PtoD_trains = dc->patna_delhi_trains.end() - dc->patna_delhi_trains.begin();


    while(1){

        cout << "Press 1 for Reservation and 2 for cancilation" << endl;
        int RorC;
        cin >> RorC;
        if(RorC == 1){
                    
            dc->reload();

            cout << "Enter journy starting station code" << endl;
            cin >> from;
            
            cout << "Enter end station code" << endl;
            cin >> to;
            
            cout << "Enter journy date(in dd/mm/yyyy format)    " << endl;
            cin >> jdate;
            
            if(from == to){
                cout << "starting and end station cann't be same" << endl;
                continue;
            }

            else if(from < to){
            
                // upgoing delhi to patna
            
                bool isAny = false;
            
                cout << "train list for delhi to patna" << endl;
            
                for(int i = 0; i < DtoP_trains; i++){
                    if(jdate == dc->delhi_patna_trains[i]->jdate){
                        cout << dc->delhi_patna_trains[i]->train_number << "\t" << dc->delhi_patna_trains[i]->train_name << " ";
                        int temp = dc->delhi_patna_trains[i]->available_seats(from, to);
                        if(temp > 0){ 
                            cout << "available seats: " <<  temp  << endl;
                            isAny = true;
                        }
                        else{
                            cout << "NO SEAT AVAILABLE" << endl;
                        } 
                    }
                } 
                
                    if(isAny){
                    
                        cout << "Enter train number" << endl;
                        cin >> selected_train;
                    
                        cout << "Enter no. of passengers" << endl;
                        cin >> passengers;
                        vector<psgr*> psgr_list;
                    
                        cout << "Enter detail of passenger (name, age, gender[M/F])" << endl;
                        for(int i = 0; i < passengers; i++){
                            string name;
                            int age;
                            char gender;
                            cin >> name >> age >> gender;
                            psgr_list.push_back(new psgr(name, age, gender));
                            if(i + 1 != passengers) cout << "enter next passenger's detail" << endl;
                        }
                        
                        ticket* booking_info; 

                        for(int i = 0; i < DtoP_trains; i++){
                            if(dc->delhi_patna_trains[i]->train_number == selected_train && dc->delhi_patna_trains[i]->jdate == jdate){
                                booking_info = dc->delhi_patna_trains[i]->book(passengers, psgr_list);
                                break;
                            }
                        }

                        string transation_id;
                        cout << "total ammount: " << booking_info->ammount;
                        cout << "Enter trangection id" << endl;
                        cin >> transation_id;
                        if(transation_id == "12345"){
                            
                            cout << "Reservation Succesfull" << endl;
                            cout << "PNR number : " << booking_info->pnr;
                            cout << "alloted seats: \n";
                            for(int i = 0; i < passengers; i++) cout << booking_info->psgr_list[i]->name << "\t" << booking_info->seats[i] << " ";    cout << endl;
                            
                        }
                        else{

                            // cancel this ticket
                            cancel_ticket(booking_info->pnr);

                        }
                    }
                    else{
                        cout << "No seat available on " << jdate << " please try on another date" << endl;
                    }
                }
            else{
                    // downgoing patna to delhi
                cout << "train list for patna to delhi" << endl;
                bool isAny = false;
                for(int i = 0; i < PtoD_trains; i++){
                    if(jdate == dc->patna_delhi_trains[i]->jdate){
                        cout << dc->patna_delhi_trains[i]->train_number << "\t" << dc->patna_delhi_trains[i]->train_name << " ";
                        int temp = dc->patna_delhi_trains[i]->available_seats(from, to);
                        if(temp > 0){ 
                            cout << "available seats: " <<  temp  << endl;
                            isAny = true;
                        }
                        else{
                            cout << "NO SEAT AVAILABLE" << endl;
                        } 
                    }
                } 
                if(isAny){
                
                    cout << "Enter train number" << endl;
                    cin >> selected_train;
                
                    cout << "Enter no. of passengers" << endl;
                    cin >> passengers;
                    vector<psgr*> psgr_list;
                
                    cout << "Enter detail of passenger (name, age, gender[M/F])" << endl;
                    for(int i = 0; i < passengers; i++){
                        string name;
                        int age;
                        char gender;
                        cin >> name >> age >> gender;
                        psgr_list.push_back(new psgr(name, age, gender));
                        if(i + 1 != passengers) cout << "enter next passenger's detail" << endl;
                    }
                    
                    ticket* booking_info; // pnr  ammount  alloted seat list

                    for(int i = 0; i < DtoP_trains; i++){
                        if(dc->delhi_patna_trains[i]->train_number == selected_train && dc->delhi_patna_trains[i]->jdate == jdate){
                            booking_info = dc->delhi_patna_trains[i]->book(passengers, psgr_list);
                            break;
                        }
                    }

                    string transation_id;
                    cout << "total ammount: " << booking_info->ammount;
                    cout << "Enter trangection id" << endl;
                    cin >> transation_id;
                    if(transation_id == "12345"){
                        
                        cout << "Reservation Succesfull" << endl;
                        cout << "PNR number : " << booking_info->pnr;
                        cout << "alloted seats: \n";
                        for(int i = 0; i < passengers; i++) cout << booking_info->psgr_list[i]->name << "\t" << booking_info->seats[i] << " ";    cout << endl;
                        
                    }
                    else{
                        
                        // cancel this ticket
                        cancel_ticket(booking_info->pnr);

                    }
                }
                else{
                    cout << "No seat available on " << jdate << " please try on another date" << endl;
                }

                }

            dc->rewrite();
        }
        else if(RorC == 2){
            int pnr;
            cout << "Enter pnr no of ticket to cancel" << endl;
            cin >> pnr;
            cancel_ticket(pnr);
        }
    }
}
