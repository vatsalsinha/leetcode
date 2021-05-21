class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        vector<int> ans;
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(sum == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
            }
            if(sum > target)
                end--;
            else
                start++;
        }
        return ans;
    }
};
