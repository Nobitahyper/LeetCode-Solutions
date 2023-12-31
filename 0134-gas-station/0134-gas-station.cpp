class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0, totalcost = 0, tank = 0, start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            totalgas += gas[i];
            totalcost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return totalgas < totalcost ? -1 : start;
    }
};