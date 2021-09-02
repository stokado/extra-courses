// You can return mulptiple values from functions with tuple

#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <utility>

using namespace std;

class Cities {
    public:
    tuple<bool, string> FindCountry(const string& city) const{
        if (city_to_country.count(city) == 1){
            return {true, city_to_country.at(city)};
        } else if (ambigious_cities.count(city) == 1) { 
            return {false, "Ambigious"};
        } else {
            return {false, "Not exist"};
        }
    };
    private:
    map<string, string> city_to_country;
    set<string> ambigious_cities;
};

int main(){
    Cities cities;
    // bool success;
    // string message;
    // tie(success, message) = cities.FindCountry("Moscow");
    auto [success, message] = cities.FindCountry("Moscow"); // SINCE C++17 Structure binding
    cout << success << ' ' << message << endl;
    return 0;
}