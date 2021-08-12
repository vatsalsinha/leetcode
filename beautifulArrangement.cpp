class Solution {
public:
    void backtrack(vector<int>& vec, int& ans, int index){
        if(index == vec.size()){
            ans++;
            return;
        }
        for(int i = index; i < vec.size(); i++){
            if(vec[i]%(index+1) == 0 || (index+1)%vec[i] == 0){
                swap(vec[i], vec[index]);
                backtrack(vec, ans, index+1);
                swap(vec[i], vec[index]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vec;
        for(int i = 0; i < n; i++)
            vec.push_back(i+1);
        int ans = 0;
        backtrack(vec, ans, 0);
        return ans;
    }
};

// 1 2 3 8 10 36 41
// 1 2 3 4 5  6  7
