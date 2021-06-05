class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size()+1);
        res[0] = first;
        for(int i = 1; i <= encoded.size(); i++){
            res[i] = encoded[i-1]^res[i-1]; // inverse of XOR is XOR itself, Lol!
        }
        return res;
    }
};
