class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /* Solution 1
        queue<int> pos, neg;
        for(auto i : nums){
            if(i > 0)
                pos.push(i);
            else
                neg.push(i);
        }
        vector<int> res;
        res.push_back(pos.front());
        pos.pop();
        for(int i = 1; i < nums.size(); i++){
            if(i % 2){
                res.push_back(neg.front());
                neg.pop();
            }
            else{
                res.push_back(pos.front());
                pos.pop();
            }
        }
        return res;
        */
        vector<int> res(nums.size());
        int pos = 0, neg = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                res[pos] = nums[i];
                pos += 2;
            }
            else{
                res[neg] = nums[i];
                neg += 2;
            }
        }
        return res;
    }
};
