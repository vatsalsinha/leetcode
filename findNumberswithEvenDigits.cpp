class Solution {
public:
    int countDigits(int n){
        int count = 0;
        while(n > 0){
            count++;
            n /= 10;   
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto i : nums){
            if(countDigits(i) % 2 ==0)
                count++;
        }
        return count;
    }
};
