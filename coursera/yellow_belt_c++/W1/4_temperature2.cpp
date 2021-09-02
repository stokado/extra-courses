// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
// Гарантируется, что среднее арифметическое значений температуры является целым числом.

// Формат ввода
// Вводится число N, затем N целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
// Гарантируется, что N не превышает миллиона (10^6), а значения температуры, измеряющиеся в миллионных долях градусов по Цельсию,
// лежат в диапазоне от −10^8 до 10^8. 
// Проверять соблюдение этих ограничений не нужно:
// вы можете ориентироваться на них при выборе наиболее подходящих типов для переменных.

// Формат вывода
// Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
// Затем K целых чисел — номера этих дней.  

#include <iostream>
#include <vector>

using namespace std;

void CountAboveAvg(const vector<int>& v){
    if (v.size() == 0){
        cout << 0 << endl;
        return;
    }
    int64_t sum = 0;
    for (const int& x : v){
        sum += x;
    }
    int64_t avg = sum / static_cast<int> (v.size());
    unsigned counter = 0;
    vector<unsigned> number;
    for (size_t i = 0; i < v.size(); ++i){
        if (v[i] > avg){
            counter++;
            number.push_back(i);
        }
    }
    cout << counter << endl;
    for (const unsigned& i : number){
        cout << i << ' ';
    }
}

int main(){
    vector<int> v;
    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    CountAboveAvg(v);
    return 0;
}