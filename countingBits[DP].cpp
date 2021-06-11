class Solution {
public:
    // int countOne(uint32_t n){
    //     int count = 0;
    //     uint32_t mask = 1;
    //     for(int i = 0; i < 32; i++){
    //         if((n & mask) != 0)
    //             count++;
    //         mask = mask << 1;
    //     }
    //     return count;
    // }
    vector<int> countBits(int n) {
        // vector<int> res;
        // for(int i = 0; i < n+1; i++){
        //     int x = countOne((uint32_t )i);
        //     res.push_back(x);
        // }
        // return res;
        vector<int> res(n+1, 0);
        for(int i = 1; i < n+1; i++)
            res[i] = res[i&(i-1)]+1;
        return res;
    }
};
