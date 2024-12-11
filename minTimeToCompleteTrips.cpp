class Solution {
public:
    bool possible(long long m, vector<int>& time, int t){
        long long int sum = 0;
        for(int i : time){
            sum += m/i;
        }
        return sum >= t;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1, high = 1e14; 
        /* 

### **Constraints:**
1 <= time.length <= 105
1 <= time[i] <= 107
1 <= totalTrips <= 107
Max time=totalTrips×max(time[i])=10^7 * 10^7 = 10^14
        */
        while(low <= high){
            long long int mid = low + (high-low)/2;
            if(possible(mid, time, totalTrips)){
                if(possible(mid-1, time, totalTrips)){
                    high = mid-1;
                }
                else{
                    return mid;
                }
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};
