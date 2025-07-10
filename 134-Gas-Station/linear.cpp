// Basically just Kadane's
// if tank < 0, then [start, i] could not be the start, so try start = i + 1
// there is a solution iff sum(gas - cost) >= 0

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            const int diff = gas[i] - cost[i];
            tank += diff;
            sum += diff;
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return sum >= 0 ? start : -1;
    }
};
