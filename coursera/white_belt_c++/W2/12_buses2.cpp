#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map <vector<string>, int> routes;
    
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        vector<string> newRoute;
        for (int j = 0; j < n; j++)
        {
            string temp;
            cin >> temp;
            newRoute.push_back(temp);
        }
        
        if (routes.find(newRoute) != routes.end())
        {
            cout << "Already exists for " << routes[newRoute] << endl;
        }
        else
        {
            routes[newRoute];
            int routeNum = routes.size();
            routes[newRoute] = routeNum;
            cout << "New bus " << routes[newRoute] << endl;
        }
    }
    return 0;
}