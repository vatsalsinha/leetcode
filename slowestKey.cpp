class Solution {
public:
    // bool static cmp(pair<char, int> a, pair<char, int> b){
    //     return a.second == b.second ?  a.first > b.first :  a.second > b.second;
    // }
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        // int n = releaseTimes.size();
        // vector<pair<char, int>> vec(n);
        // int prev = 0;
        // for(int i = 0; i < n; i++){
        //     vec[i] = {keysPressed[i], releaseTimes[i]-prev};
        //     prev = releaseTimes[i];
        // }
        // sort(vec.begin(), vec.end(), cmp);
        // for(int i = 0; i < n; i++)
        //     cout<<vec[i].first<<":"<<vec[i].second<<" ";
        // return vec[0].first;
        
        int n = releaseTimes.size();
        int prev = 0;
        int maxDifference = INT_MIN;
        char ans = keysPressed[0];
        for(int i = 0; i < n; i++){
            int difference = releaseTimes[i] - prev;
            if(maxDifference < difference || maxDifference == difference && ans < keysPressed[i]){
                maxDifference = difference;
                ans = keysPressed[i];
            }
            prev = releaseTimes[i];
        }
        return ans;
    }
};
