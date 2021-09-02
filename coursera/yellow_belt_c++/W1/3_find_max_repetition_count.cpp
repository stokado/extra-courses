#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

bool operator<(const Region& lhs, const Region& rhs){
    return make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
        make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    map<Region, int> counter;
    if (regions.size()){
        for (const auto& item : regions){
            counter[item]++;
        }
        int max = 0;
        for (const auto& item : counter){
            if (max < item.second){
                max = item.second;
            }
        }
        return max;
    }
    return 0;
};
