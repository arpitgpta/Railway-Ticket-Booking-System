
#include "Classes.cpp" 

class DataCenter{

    public:

        DataCenter(){
            Stations.push_back(new station(1, "Delhi", 0));
            Stations.push_back(new station(2, "Ghaziabad", 24));
            Stations.push_back(new station(3, "Moradabad", 165));
            Stations.push_back(new station(4, "Bareilly", 255));
            Stations.push_back(new station(5, "Shahjahanpur", 326));
            Stations.push_back(new station(6, "Lucknow", 491));
            Stations.push_back(new station(7, "Nihalgarh", 580));
            Stations.push_back(new station(8, "Musafir Khana", 599));
            Stations.push_back(new station(9, "Sultanpur", 630));
            Stations.push_back(new station(10, "Jaunpur", 716));
            Stations.push_back(new station(11, "Varanshi", 773));
            Stations.push_back(new station(12, "Mugalsaray", 792));
            Stations.push_back(new station(13, "Dildarnagar", 849));
            Stations.push_back(new station(14, "Buxar", 865));
            Stations.push_back(new station(15, "Ara", 954));
            Stations.push_back(new station(16, "Patna", 1003));



            
            delhi_patna_trains.push_back(new Train("14/11/2019", 20802, "Magadh Express"));
            delhi_patna_trains.push_back(new Train("15/11/2019", 20802, "Magadh Express"));
            delhi_patna_trains.push_back(new Train("16/11/2019", 20802, "Magadh Express"));
            delhi_patna_trains.push_back(new Train("17/11/2019", 20802, "Magadh Express"));
            delhi_patna_trains.push_back(new Train("18/11/2019", 20802, "Magadh Express"));

            delhi_patna_trains.push_back(new Train("14/11/2019", 12274, "Howrah Duronto Express"));
            delhi_patna_trains.push_back(new Train("15/11/2019", 12274, "Howrah Duronto Express"));
            delhi_patna_trains.push_back(new Train("16/11/2019", 12274, "Howrah Duronto Express"));
            delhi_patna_trains.push_back(new Train("17/11/2019", 12274, "Howrah Duronto Express"));
            delhi_patna_trains.push_back(new Train("18/11/2019", 12274, "Howrah Duronto Express"));

            delhi_patna_trains.push_back(new Train("14/11/2019", 12392, "Shramjeevi SF Express"));
            delhi_patna_trains.push_back(new Train("15/11/2019", 12392, "Shramjeevi SF Express"));
            delhi_patna_trains.push_back(new Train("16/11/2019", 12392, "Shramjeevi SF Express"));
            delhi_patna_trains.push_back(new Train("17/11/2019", 12392, "Shramjeevi SF Express"));
            delhi_patna_trains.push_back(new Train("18/11/2019", 12392, "Shramjeevi SF Express"));

            delhi_patna_trains.push_back(new Train("14/11/2019", 13484, "Farakka Express"));
            delhi_patna_trains.push_back(new Train("15/11/2019", 13484, "Farakka Express"));
            delhi_patna_trains.push_back(new Train("16/11/2019", 13484, "Farakka Express"));
            delhi_patna_trains.push_back(new Train("17/11/2019", 13484, "Farakka Express"));
            delhi_patna_trains.push_back(new Train("18/11/2019", 13484, "Farakka Express"));

            delhi_patna_trains.push_back(new Train("14/11/2019", 12468, "Vikramshila Express"));
            delhi_patna_trains.push_back(new Train("15/11/2019", 12468, "Vikramshila Express"));
            delhi_patna_trains.push_back(new Train("16/11/2019", 12468, "Vikramshila Express"));
            delhi_patna_trains.push_back(new Train("17/11/2019", 12468, "Vikramshila Express"));
            delhi_patna_trains.push_back(new Train("18/11/2019", 12468, "Vikramshila Express"));





            patna_delhi_trains.push_back(new Train("14/11/2019", 20801, "Magadh Express"));
            patna_delhi_trains.push_back(new Train("15/11/2019", 20801, "Magadh Express"));
            patna_delhi_trains.push_back(new Train("16/11/2019", 20801, "Magadh Express"));
            patna_delhi_trains.push_back(new Train("17/11/2019", 20801, "Magadh Express"));
            patna_delhi_trains.push_back(new Train("18/11/2019", 20801, "Magadh Express"));

            patna_delhi_trains.push_back(new Train("14/11/2019", 12275, "Howrah Duronto Express"));
            patna_delhi_trains.push_back(new Train("15/11/2019", 12275, "Howrah Duronto Express"));
            patna_delhi_trains.push_back(new Train("16/11/2019", 12275, "Howrah Duronto Express"));
            patna_delhi_trains.push_back(new Train("17/11/2019", 12275, "Howrah Duronto Express"));
            patna_delhi_trains.push_back(new Train("18/11/2019", 12275, "Howrah Duronto Express"));

            patna_delhi_trains.push_back(new Train("14/11/2019", 12391, "Shramjeevi SF Express"));
            patna_delhi_trains.push_back(new Train("15/11/2019", 12391, "Shramjeevi SF Express"));
            patna_delhi_trains.push_back(new Train("16/11/2019", 12391, "Shramjeevi SF Express"));
            patna_delhi_trains.push_back(new Train("17/11/2019", 12391, "Shramjeevi SF Express"));
            patna_delhi_trains.push_back(new Train("18/11/2019", 12391, "Shramjeevi SF Express"));

            patna_delhi_trains.push_back(new Train("14/11/2019", 13483, "Farakka Express"));
            patna_delhi_trains.push_back(new Train("15/11/2019", 13483, "Farakka Express"));
            patna_delhi_trains.push_back(new Train("16/11/2019", 13483, "Farakka Express"));
            patna_delhi_trains.push_back(new Train("17/11/2019", 13483, "Farakka Express"));
            patna_delhi_trains.push_back(new Train("18/11/2019", 13483, "Farakka Express"));

            patna_delhi_trains.push_back(new Train("14/11/2019", 12467, "Vikramshila Express"));
            patna_delhi_trains.push_back(new Train("15/11/2019", 12467, "Vikramshila Express"));
            patna_delhi_trains.push_back(new Train("16/11/2019", 12467, "Vikramshila Express"));
            patna_delhi_trains.push_back(new Train("17/11/2019", 12467, "Vikramshila Express"));
            patna_delhi_trains.push_back(new Train("18/11/2019", 12467, "Vikramshila Express"));

        }

        void reload(){
            // function to load data from file
        }

        void rewrite(){
            // function to rewrite in file
        }

        vector<station*> Stations;

        vector<Train*> delhi_patna_trains;
        vector<Train*> patna_delhi_trains;

       // vector<ticket*> booked_tickets; 
       // fetch data here

};
