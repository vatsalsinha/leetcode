class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> st(target.begin(), target.end());
        vector<string> ans;
        for(int i = 1; i < target[target.size()-1]+1; i++){
            if(st.count(i) > 0)
                ans.push_back("Push");
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
