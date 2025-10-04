#include <iostream>
#include <vector>
using namespace std;

int gasStation(vector<int> &gas, vector<int> &cost)
{
    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        total_tank += gas[i] - cost[i];
        curr_tank += gas[i] - cost[i];
        if (curr_tank < 0)
        {
            starting_station = i + 1;
            curr_tank = 0;
        }
    }
    return total_tank >= 0 ? starting_station : -1;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int ans = gasStation(gas, cost);
    cout << ans << endl;
    return 0;
}