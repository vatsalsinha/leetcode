class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int r = pairs[0][1];
        int count = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(r < pairs[i][0]){
                r = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};
