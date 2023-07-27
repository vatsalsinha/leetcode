class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        //if we have n trains suppose 10 ok then we can catch each of them in 1 hour gap right? so even if we travel at max speed then also we have to wait a minimum of 9 hours for catching all the trains
        if(hour <= n-1)
            return -1;
        int low = 1, high = 1e7;
        while(low < high){
            double time = 0;
            int mid = low + (high-low)/2;
            for(int i = 0; i < n-1; i++)
                time += ceil((double)dist[i]/mid);
            time += (double)dist[n-1]/mid;
            if(time <= hour)
                high = mid;
            else
                low = mid+1;
        }    
        return low;
    }
};
