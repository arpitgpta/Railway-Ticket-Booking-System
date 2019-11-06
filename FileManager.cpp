
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



            delhi_patna_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Magadh Express", "14/11/2019", 20802)));
            delhi_patna_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Magadh Express", "15/11/2019", 20802)));
            delhi_patna_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Magadh Express", "16/11/2019", 20802)));
            delhi_patna_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Magadh Express", "17/11/2019", 20802)));
            delhi_patna_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Magadh Express", "18/11/2019", 20802)));

            delhi_patna_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Howrah Duronto Express", "14/11/2019", 12274)));
            delhi_patna_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Howrah Duronto Express", "15/11/2019", 12274)));
            delhi_patna_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Howrah Duronto Express", "16/11/2019", 12274)));
            delhi_patna_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Howrah Duronto Express", "17/11/2019", 12274)));
            delhi_patna_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Howrah Duronto Express", "18/11/2019", 12274)));

            delhi_patna_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Shramjeevi SF Express", "14/11/2019", 12392)));
            delhi_patna_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Shramjeevi SF Express", "15/11/2019", 12392)));
            delhi_patna_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Shramjeevi SF Express", "16/11/2019", 12392)));
            delhi_patna_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Shramjeevi SF Express", "17/11/2019", 12392)));
            delhi_patna_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Shramjeevi SF Express", "18/11/2019", 12392)));

            delhi_patna_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Farakka Express", "14/11/2019", 13484)));
            delhi_patna_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Farakka Express", "15/11/2019", 13484)));
            delhi_patna_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Farakka Express", "16/11/2019", 13484)));
            delhi_patna_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Farakka Express", "17/11/2019", 13484)));
            delhi_patna_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Farakka Express", "18/11/2019", 13484)));

            delhi_patna_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Vikramshila Express", "14/11/2019", 12468)));
            delhi_patna_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Vikramshila Express", "15/11/2019", 12468)));
            delhi_patna_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Vikramshila Express", "16/11/2019", 12468)));
            delhi_patna_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Vikramshila Express", "17/11/2019", 12468)));
            delhi_patna_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Vikramshila Express", "18/11/2019", 12468)));





            patna_delhi_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Magadh Express", "14/11/2019", 20801)));
            patna_delhi_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Magadh Express", "15/11/2019", 20801)));
            patna_delhi_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Magadh Express", "16/11/2019", 20801)));
            patna_delhi_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Magadh Express", "17/11/2019", 20801)));
            patna_delhi_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Magadh Express", "18/11/2019", 20801)));

            patna_delhi_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Howrah Duronto Express", "14/11/2019", 12275)));
            patna_delhi_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Howrah Duronto Express", "15/11/2019", 12275)));
            patna_delhi_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Howrah Duronto Express", "16/11/2019", 12275)));
            patna_delhi_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Howrah Duronto Express", "17/11/2019", 12275)));
            patna_delhi_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Howrah Duronto Express", "18/11/2019", 12275)));

            patna_delhi_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Shramjeevi SF Express", "14/11/2019", 12391)));
            patna_delhi_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Shramjeevi SF Express", "15/11/2019", 12391)));
            patna_delhi_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Shramjeevi SF Express", "16/11/2019", 12391)));
            patna_delhi_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Shramjeevi SF Express", "17/11/2019", 12391)));
            patna_delhi_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Shramjeevi SF Express", "18/11/2019", 12391)));

            patna_delhi_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Farakka Express", "14/11/2019", 13483)));
            patna_delhi_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Farakka Express", "15/11/2019", 13483)));
            patna_delhi_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Farakka Express", "16/11/2019", 13483)));
            patna_delhi_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Farakka Express", "17/11/2019", 13483)));
            patna_delhi_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Farakka Express", "18/11/2019", 13483)));

            patna_delhi_trains.push_back(pair<string, Train*>("14/11/2019", new Train("Vikramshila Express", "14/11/2019", 12467)));
            patna_delhi_trains.push_back(pair<string, Train*>("15/11/2019", new Train("Vikramshila Express", "15/11/2019", 12467)));
            patna_delhi_trains.push_back(pair<string, Train*>("16/11/2019", new Train("Vikramshila Express", "16/11/2019", 12467)));
            patna_delhi_trains.push_back(pair<string, Train*>("17/11/2019", new Train("Vikramshila Express", "17/11/2019", 12467)));
            patna_delhi_trains.push_back(pair<string, Train*>("18/11/2019", new Train("Vikramshila Express", "18/11/2019", 12467)));

        }

        vector<station*> Stations;
        vector<pair<string, Train*>> delhi_patna_trains;
        vector<pair<string, Train*>> patna_delhi_trains;

};