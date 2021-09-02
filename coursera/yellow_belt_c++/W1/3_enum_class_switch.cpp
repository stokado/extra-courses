#include <set>
#include <iostream>

using namespace std;

enum class RequestType{
    ADD,
    REMOVE,
    NEGATE
};



void ProcessRequest(set<int>& numbers, RequestType request_type, int request_data){
    switch (request_type) {
    case RequestType::ADD:
        numbers.insert(request_data);
        break;
    case RequestType::REMOVE:
        numbers.erase(request_data);
        break;
    case RequestType::NEGATE:
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
        break;
    // Если нужно объявить переменную в ветке, заключаем ветку в скобки
    // case RequestType::NEGATE: {  // фигурные скобки обязательны
    //     bool contains = numbers.count(request_data) == 1;
    //     if (contains) {
    //         numbers.erase(request_data);
    //         numbers.insert(-request_data);
    //     }
    // }
    break;
    default:
        cout << "Unknown request" << endl;
    }
}   



int main(){
    set<int> numbers;
    ProcessRequest(numbers, RequestType::ADD, 8);
    ProcessRequest(numbers, RequestType::NEGATE, 8);
    ProcessRequest(numbers, RequestType::REMOVE, -8);
}