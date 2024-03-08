class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101, 0);
        for(int i : nums){
            v[i]++;
        }
        int m = *max_element(v.begin(), v.end());
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == m)
                sum += v[i];
        }
        return sum;
    }
};
