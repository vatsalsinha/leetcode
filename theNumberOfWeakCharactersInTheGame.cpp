class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int mn = INT_MIN;
        int ans = 0;
        for(int i = properties.size()-1; i >= 0; i--){
            if(properties[i][1] < mn)
                ans++;
            mn = max(mn, properties[i][1]);
        }
        return ans;
    }
};
// sort the array on the basis of attack. And then traverse a/c to defense
