#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int main()
//{
//    int q;
//    cin >> q;
//
//    map <string, vector<string>> buses;
//    buses = { 
//                {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
//                {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
//                {"950", {"Kokoshkino", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Troparyovo"}},
//                {"272", {"Vnukovo", "Moskovsky", "Rumyantsevo", "Troparyovo"}}
//            };
//
//    for (int i = 0; i < q; i++)
//    {
//        string cmd;
//        cin >> cmd;
//        
//        if (cmd == "NEW_BUS")
//        {
//            string newBus;
//            cin >> newBus;
//            int stopCount;
//            cin >> stopCount;
//            for (int i = 0; i < stopCount; ++i)
//            {
//                string newStop;
//                cin >> newStop;
//                buses[newBus].push_back(newStop);
//            }
//        }
//        else if (cmd == "BUSES_FOR_STOP")
//        {
//            string findStop;
//            cin >> findStop;
//            bool found = false;
//            for (const auto& item : buses)
//            {
//                for (const string& stop : item.second)
//                if (stop == findStop)
//                {
//                    found = true;
//                    std::cout << item.first << " ";
//                }
//            }
//            if (!found)
//                std::cout << "No stop\n";
//        }
//        else if (cmd == "STOPS_FOR_BUS")
//        {
//          
//        }
//        else if (cmd == "ALL_BUSES")
//        {
//            if (buses.size())
//            {
//                for (const auto& item : buses)
//                {
//                    std::cout << "Bus " << item.first << ":";
//                    for (const string& stop : buses[item.first])
//                        std::cout << " " << stop;
//                    std::cout << std::endl;
//                }
//            }
//            else
//                std::cout << "No buses\n";
//        }
//        
//    }
//    return 0;
//}

int main()
{
    int q;
    cin >> q;
    map <string, vector <string>> buses_for_stop;
    vector <string> buses_alph;

    for (int i = 0; i < q; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "NEW_BUS")
        {
            string bus;
            cin >> bus;
            int stopCount;
            cin >> stopCount;
            vector <string> route;
            for (int i = 0; i < stopCount; i++)
            {
                string stop;
                cin >> stop;
                route.push_back(stop);
            }
            buses_for_stop[bus] = route;
            buses_alph.push_back(bus);
        }
        else if (cmd == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            bool found = false;
            for (const string& curBus : buses_alph)
            {
                for (const auto& now : buses_for_stop[curBus])
                {
                    if (now == stop)
                    {   
                        found = true;
                        cout << curBus << " ";
                        break;
                    }
                }
            }
            if (!found)
                cout << "No stop\n";
            else
                cout << endl;
        }
        else if(cmd == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;
            if (buses_for_stop.find(bus) != buses_for_stop.end())
            {
                for (const string& stop : buses_for_stop[bus])
                {
                    cout << "Stop " << stop << ":";
                    bool found = false;
                    for (const string& curBus : buses_alph)
                    {
                        for (const auto& now : buses_for_stop[curBus])
                        {
                            if (now == stop && bus != curBus)
                            {   
                                found = true;
                                cout << " " << curBus;
                            }
                        }
                    }
                    if (!found)
                        cout << " no interchange\n";
                    else
                        cout << endl;
                }
            }
            else
                cout << "No bus\n";
        }
        else if (cmd == "ALL_BUSES")
        {
            if (buses_for_stop.size() != 0)
            {
                for (const auto& item : buses_for_stop)
                {
                    cout << "Bus " << item.first << ":";
                    for (const string& item : buses_for_stop[item.first])
                    {
                        cout << " " << item;
                    }
                    cout << endl;
                }
            }
            else
                cout << "No buses\n";
        }
    }
    return 0;
}