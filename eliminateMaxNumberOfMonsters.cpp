class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        for(int i = 0; i < dist.size(); i++){
            time.push_back((float)dist[i]/speed[i]);
        }
        sort(time.begin(), time.end());
        int ans = 0;
        int i = 0;
        while(i < time.size()){
            if(time[i] <= i)
                break;
            else
                ans++;
            i++;
        }
        return ans;
    }
};
