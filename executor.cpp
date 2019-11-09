// g++ executor.cpp -o executor && ./executor
#include "components.cpp"

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



int main(){

    
    int from, to;
    char jdate[15];
    int selected_train, passengers;

    cout << "Welcome to Railway Ticket Booking System" << endl;
    load_data();
    cout << "Stations:" << endl << "Station code    Station name" << endl;     
    for(int i = 0; i < 16; i++){
        cout << STATIONS.Stations[i].st_no << ".\t\t" << STATIONS.Stations[i].st_name << endl;
    }
    
    

    while(1){

        re_read();
        
        cout << "Press 1 for Reservation and 2 for cancilation" << endl;
        int RorC;
        cin >> RorC;
        if(RorC == 1){
                    


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
            
                for(int i = 0; i < 10; i++){
                    if(strcmp(TRAINS.DtoP[i].jdate, jdate)){
                        cout << TRAINS.DtoP[i].train_number << "\t" << TRAINS.DtoP[i].train_name << endl;
                        // int temp = available_seats(from, to, 'd', i);
                        // if(temp > 0){ 
                        //     cout << "available seats: " <<  temp  << endl;
                        //     isAny = true;
                        // }
                        // else{
                        //     cout << "NO SEAT AVAILABLE" << endl;
                        // } 
                    }
                } 
                
                    // if(isAny){
                    
                    //     cout << "Enter train number" << endl;
                    //     cin >> selected_train;
                    
                    //     cout << "Enter no. of passengers" << endl;
                    //     cin >> passengers;

                    //     TICKETS.tickets[TICKETS.ticket_counter].from = from;
                    //     TICKETS.tickets[TICKETS.ticket_counter].to = to;
                    //     strcpy(TICKETS.tickets[TICKETS.ticket_counter].jdate, jdate);
                    //     TICKETS.tickets[TICKETS.ticket_counter].tr_start_DorP = 'd';
                    //     TICKETS.tickets[TICKETS.ticket_counter].psgr_count = passengers;
                    //     TICKETS.tickets[TICKETS.ticket_counter].train_no = selected_train;

                    
                    //     cout << "Enter detail of passenger (name, age, gender[M/F])" << endl;
                    //     for(int i = 0; i < passengers; i++){

                    //         gets(TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].name);
                    //         cin >> TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].age;
                    //         cin >> TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].gender;
                    //         if(i + 1 != passengers) cout << "enter next passenger's detail" << endl;

                    //     }
                        
                    //     int tcno = book_ticket();

                    //     string transation_id;
                    //     cout << "total ammount: " << TICKETS.tickets[tcno].amount;
                    //     cout << "Enter trangection id" << endl;
                    //     cin >> transation_id;
                    //     if(transation_id == "12345"){
                            
                    //         cout << "Reservation Succesfull" << endl;
                    //         cout << "PNR number : " << TICKETS.tickets[tcno].pnr;
                    //         cout << "alloted seats: \n";
                    //         for(int i = 0; i < passengers; i++) cout << TICKETS.tickets[tcno].psgrs[i].name << "\t" << TICKETS.tickets[tcno].psgrs[i].seat << " ";    cout << endl;
                            
                    //     }
                    //     else{

                    //         // cancel this ticket
                    //         cancel_ticket(TICKETS.tickets[tcno].pnr);

                    //     }
                    // }
                    // else{
                    //     cout << "No seat available on " << jdate << " please try on another date" << endl;
                    // }
                }
            else{
            
                // upgoing patna to delhi
            
                bool isAny = false;
            
                cout << "train list for patna to delhi" << endl;
            
                for(int i = 0; i < 10; i++){
                    if(jdate == TRAINS.PtoD[i].jdate){
                        cout << TRAINS.PtoD[i].train_number << "\t" << TRAINS.PtoD[i].train_name << " ";
                        // int temp = available_seats(from, to, 'p', i);
                        // if(temp > 0){ 
                        //     cout << "available seats: " <<  temp  << endl;
                        //     isAny = true;
                        // }
                        // else{
                        //     cout << "NO SEAT AVAILABLE" << endl;
                        // } 
                    }
                } 
                
                    // if(isAny){
                    
                    //     cout << "Enter train number" << endl;
                    //     cin >> selected_train;
                    
                    //     cout << "Enter no. of passengers" << endl;
                    //     cin >> passengers;

                    //     TICKETS.tickets[TICKETS.ticket_counter].from = from;
                    //     TICKETS.tickets[TICKETS.ticket_counter].to = to;
                    //     strcpy(TICKETS.tickets[TICKETS.ticket_counter].jdate, jdate);
                    //     TICKETS.tickets[TICKETS.ticket_counter].tr_start_DorP = 'p';
                    //     TICKETS.tickets[TICKETS.ticket_counter].psgr_count = passengers;
                    //     TICKETS.tickets[TICKETS.ticket_counter].train_no = selected_train;

                    
                    //     cout << "Enter detail of passenger (name, age, gender[M/F])" << endl;
                    //     for(int i = 0; i < passengers; i++){

                    //         gets(TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].name);
                    //         cin >> TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].age;
                    //         cin >> TICKETS.tickets[TICKETS.ticket_counter].psgrs[i].gender;
                    //         if(i + 1 != passengers) cout << "enter next passenger's detail" << endl;

                    //     }
                        
                    //     int tcno = book_ticket();

                    //     string transation_id;
                    //     cout << "total ammount: " << TICKETS.tickets[tcno].amount;
                    //     cout << "Enter trangection id" << endl;
                    //     cin >> transation_id;
                    //     if(transation_id == "12345"){
                            
                    //         cout << "Reservation Succesfull" << endl;
                    //         cout << "PNR number : " << TICKETS.tickets[tcno].pnr;
                    //         cout << "alloted seats: \n";
                    //         for(int i = 0; i < passengers; i++) cout << TICKETS.tickets[tcno].psgrs[i].name << "\t" << TICKETS.tickets[tcno].psgrs[i].seat << " ";    cout << endl;
                            
                    //     }
                    //     else{

                    //         // cancel this ticket
                    //         cancel_ticket(TICKETS.tickets[tcno].pnr);

                    //     }
                    // }
                    // else{
                    //     cout << "No seat available on " << jdate << " please try on another date" << endl;
                    // }
                }

        }
        else if(RorC == 2){
            int pnr;
            cout << "Enter pnr no of ticket to cancel" << endl;
            cin >> pnr;
            cancel_ticket(pnr);
        }

       // re_write();
    }
}
