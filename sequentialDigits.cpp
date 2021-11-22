class Solution {
public:
    vector<int> ans;
    void recurse(int low, int high, int number){
        if(number >= low && number <= high)
            ans.push_back(number);
        if(number > high)
            return;
        if((number%10) < 9)
            recurse(low, high, number*10 + (number%10) + 1);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i < 10; i++)
            recurse(low, high, i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
