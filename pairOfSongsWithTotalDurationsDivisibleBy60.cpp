class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int hashMap[60];
        for(int i = 0; i < time.size(); i++){
            time[i] %= 60;
        }
        int count = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < time.size(); i++){
            if(time[i] == 0)
                count += mp[0];
            else 
                count += mp[60-time[i]];
            mp[time[i]]++;
        }
        return count;
    }
};
