class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> preXor(arr.size()+1, 0), res;
        for(int i = 1; i < arr.size()+1; i++){
            preXor[i] = preXor[i-1] ^ arr[i-1];
        }
        for(auto q : queries){
            int start = q[0];
            int end = q[1];
            res.push_back(preXor[end+1] ^ preXor[start]); //for eg. 3^4 = (1^3^4)^1
        }
        return res;
    }
};
