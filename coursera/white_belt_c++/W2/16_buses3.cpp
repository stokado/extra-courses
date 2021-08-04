#include <set>
#include <iostream>
#include <string>
#include <map>


using namespace std;

int main()
{
    int q;
    cin >> q;

    map <set<string>, int> routes;

    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;

        set<string> newRoute;
        for (int j = 0; j < n; j++)
        {
            string stop;
            cin >> stop;
            newRoute.insert(stop);
        }
        if (routes.find(newRoute) != routes.end())
        {
            cout << "Already exists for " << routes[newRoute] << endl;
        }
        else
        {
            routes[newRoute];
            int num = routes.size();
            routes[newRoute] = num;
            cout << "New bus " << num << endl;
        }
    }
    return 0;
}
