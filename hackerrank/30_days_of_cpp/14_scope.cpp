/* Complete The Difference class by writing the following:
    A class constructor that takes an array of integers as a parameter and saves it to the __elements instance variable;
    A computeDifference method that finds the maximum absolute difference between any 2 numbers in __elements and stores it in the maximumDifference instance variable.
*/

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

    Difference(const vector<int>& v){
        this->elements = v;
    }

    void computeDifference(){
        if (elements.size() == 1){
            maximumDifference = 0;
        }
        sort(begin(elements), end(elements));
        maximumDifference = abs(elements.back() - elements.front());
    }
    
};