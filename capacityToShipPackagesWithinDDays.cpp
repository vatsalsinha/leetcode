class Solution {
public:
    // Check whether the packages can be shipped in less than d days with m capacity.
    bool possible(vector<int>& weights, int m, int d){
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > m) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0, maxLoad = 0;
        total = accumulate(weights.begin(), weights.end(), 0);
        maxLoad = *max_element(weights.begin(), weights.end());
        int low = maxLoad, high = total;
        while(low < high){
            int mid = (low + high)/2;
            if(possible(weights, mid, days))
                high = mid;
            else
                low = mid+1;
        } 
        return low;
    }
};
