class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0))
            return -1;
        int start = 0, remainingGas = 0;
        for(int i = 0; i < gas.size(); i++){
            remainingGas += gas[i] - cost[i];
            if(remainingGas < 0){
                start = i+1;
                remainingGas = 0;
            }
        }
        return start;
    }
};
