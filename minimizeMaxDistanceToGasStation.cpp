class Solution {
public:
    bool possible (double mid, vector<int> stations, int k){
        int used = 0;
        for(int i = 0; i < stations.size() - 1; i++){
            used += (int) ((stations[i+1] - stations[i]) / mid);
        }
        return used <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double start = 0;
        double end = stations[stations.size() - 1] - stations[0];
        while(start < end){
            double mid = (start + end) / 2.0;
            if(possible(mid, stations, k))
                end = mid - 1e-6;
            else 
                start = mid + 1e-6;
        }
        return start;
    }
};


