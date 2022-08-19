class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> available, vacant; // vacant : {vacant ke last pushed element + 1 : freq}
        for(int i : nums)
            available[i]++;
        for(auto i : nums){
            if(available[i] == 0)
                continue;
            available[i]--; //using this element to create group
            if(vacant[i-1] > 0){ // checking if new element can be pushed or not
                vacant[i-1]--;
                vacant[i]++;
            }
            else if(available[i+1] != 0 && available[i+2] != 0){ // maintaining size >= 3 and pushing vacant[i+2] freq
                available[i+1]--;
                available[i+2]--;
                vacant[i+2]++;
            }
            else
                return 0;
        }
        return 1;
    }
};
