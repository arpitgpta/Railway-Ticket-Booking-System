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

int main(){

    DataCenter *dc = new DataCenter(); 
    cout << "hello" << endl;
    vector<station*> Stations = dc->Stations;
    cout << "Stations:" << endl << "Station code    Station name" << endl;     
    for(int i = 0; i < 16; i++){
        cout << Stations[i]->st_no << ".\t\t" << Stations[i]->st_name << endl;
    }
    int DtoP_trains = dc->delhi_patna_trains.end() - dc->delhi_patna_trains.begin();
    int PtoD_trains = dc->patna_delhi_trains.end() - dc->patna_delhi_trains.begin();
    while(1){

        int from, to;
        string jdate;
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
        else if(from > to){
            // upgoing delhi to patna
            cout << "train list for delhi to patna" << endl;
            for(int i = 0; i < DtoP_trains; i++){
                if(jdate == dc->delhi_patna_trains[i].first){
                    cout << dc->delhi_patna_trains[i].second->train_number << "\t" << dc->delhi_patna_trains[i].second->train_name << " ";
                    cout << "avilable seats: " <<   dc->delhi_patna_trains[i].second->avilable_seats(from, to) << endl;
                }
            } 
        }
        else{
            // downgoing patna to delhi
            cout << "train list for patna to delhi" << endl;
            for(int i = 0; i < PtoD_trains; i++){
                if(jdate == dc->patna_delhi_trains[i].first){
                    cout << dc->patna_delhi_trains[i].second->train_number << "\t" << dc->patna_delhi_trains[i].second->train_name << " ";
                    cout << "avilable seats: " <<   dc->patna_delhi_trains[i].second->avilable_seats(from, to) << endl;
                }
            } 
        }
    }
}