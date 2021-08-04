#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {

    int cases = 3;
    if (cases == 0)
    {
        return "01:24:49";
    }
    else if (cases == 1)
    {
        throw (system_error(error_code()));
    }
    else if (cases == 2)
    {
        throw (invalid_argument("ia error"));
    }
    else if (cases == 3)
    {
        throw (runtime_error("runtime error"));
    }
    return "";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            string temp = AskTimeServer();
            last_fetched_time = temp;
            return last_fetched_time;
        }
        catch (system_error& se)
        {
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
