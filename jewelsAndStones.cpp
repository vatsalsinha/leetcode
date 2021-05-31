class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // int count = 0;
        // for(auto s : jewels){
        //     for(auto x : stones){
        //         if(s == x)
        //             count++;
        //     }
        // }
        // return count;
        unordered_set<char> j(jewels.begin(), jewels.end());
        int count = 0;
        for(auto s : stones){
            if(j.find(s) != j.end())
                count++;
        }
        return count;
    }
};
