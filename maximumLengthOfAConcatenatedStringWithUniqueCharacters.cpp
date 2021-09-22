class Solution {
public:
    bool isUnique(string word) {
        unordered_set<char> st;
        for (auto ele : word) {
            if (st.find(ele) != st.end()) return false;
            st.insert(ele);
        }
        return true;
    }
    void backtrack(vector<string> arr, int &ans, int start, string str){
        if(!isUnique(str))
            return;
        if(ans < str.size())
            ans = str.size();
        for(int i = start; i < arr.size(); i++){
            backtrack(arr, ans, i+1, str+arr[i]);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        backtrack(arr, ans, 0, "");
        return ans;
    }
};
