class Solution {
public:
    int bin2gray(int i){
        return i ^ (i >> 1);
    }
    vector<int> grayCode(int n) {
        vector<int> res(pow(2,n));
        for(int i = 0; i < pow(2,n); i++){
            res[i] = bin2gray(i);
        }
        return res;
    }
};
