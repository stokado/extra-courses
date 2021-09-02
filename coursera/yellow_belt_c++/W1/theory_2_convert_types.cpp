    // Правила выведения общего типа
    // Перед сравнениями и арифмитическими операциями числа приводятся к общему типу
    // Все типы размера меньше int приводятся к int     int8_t + uint8_t -> int
    // Из двух типов выбирается больший по размеру      int32_t + int8_t -> int32_t
    // Если размер одинаковый, выбирается беззнаковый   int + size_t -> size_t ; int32_t + uint_32t -> uint32_t

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void PrintAvg(){
    vector<int> t = {-8, -7, 3};
    int sum = 0;
    for (int x : t){
        sum += x;
    }
    int avg = sum / static_cast<int>(t.size());
    cout << avg << endl;
}

int main(){
    // cout << numeric_limits<int>::max() + 1 << ' ' << numeric_limits<int>::min() - 1 << endl;
    int x = 2'000'000'000;
    int y = 1'000'000'000;
    cout << (x + y) / 2 << endl;
    unsigned int z = x;
    x *= -1;
    z = x;
    cout << x << ' ' << z << endl;

    vector<int> t = {-8, -7, 3};
    int sum = 0;
    for (int x : t){
        sum += x;
    }
    int avg = sum / t.size();
    cout << avg << endl;

    cout << (-1 < 1u) << endl;
    vector<int> v = {4, 5};
    for (int i = 0; i < static_cast<int>(v.size()); ++i){
        cout << i << ' ' << v[i] << endl;
    }
    // or
    for (size_t i = 0; i < v.size(); ++i){
        cout << i << ' ' << v[i] << endl;
    }
    avg = sum / static_cast<int>(t.size());
    cout << avg << endl;

    vector<int> vv = {1, 4, 6};
    for (size_t i = 0;
        i < vv.size() - 1;      // нужно делать очень осторожно!!! может быть vv.size() = 0,
        ++i){ 
        cout << vv[i] << endl;
    }
    for (size_t i = 0;
         i + 1 < vv.size();      // Так лучше!
         ++i){
        cout << vv[i] << endl;
    }
    // в обратном порядке
    for (size_t i = vv.size() - 1;
         i >= 0;                // Выполняется всегда, т.к. size_t беззнаковый тип, так делать не стоит
         --i){
        cout << vv[i] << endl;
    }

   for (size_t k = vv.size();
         k > 0;                // Уже лучше
         --k){
        size_t i = k - 1;
        cout << vv[i] << endl;
    }

    

    return 0;
    
}