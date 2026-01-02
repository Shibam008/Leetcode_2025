class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        int start = 0;
        int cumulativeGas = 0;

        for(int i=0; i<gas.size(); i++) {
            cumulativeGas += gas[i] - cost[i];
            if(cumulativeGas < 0) {
                start = i + 1;
                cumulativeGas = 0;
            }
        }
        return start;
    }
};