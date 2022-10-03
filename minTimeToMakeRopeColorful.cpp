class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int i = 0, j = 0;
        while(i < colors.size() && j < colors.size()){
            int curMax = 0, curTotal = 0;
            while(j < colors.size() && colors[i] == colors[j]){
                curTotal += neededTime[j];
                curMax = max(curMax, neededTime[j]);
                j++;
            }
            time += curTotal - curMax; // we are only keeping one balloon from each color. Thus, keeping the one which needs most time to remove;
            i = j;
        }
        return time;
    }
};
