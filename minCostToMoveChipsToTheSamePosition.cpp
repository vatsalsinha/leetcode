class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0, oddCount = 0; // the idea is to simply check the count of coins at even and odd position
        // odd pos coins can be moved to another odd pos at cost = 0; same for even pos
        
        for(int n : position){ 
            if(n % 2)
                oddCount++;
            else
                evenCount++;
        }
        return min(evenCount, oddCount);
    }
};
