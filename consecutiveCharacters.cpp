class Solution {
public:
    int maxPower(string s) {
        if(s.size() <= 1)
            return 1;
        s += " ";
        vector<int> power(s.size(), 0);
        int count = 0;
        for(int i = 0, j = 1; i < s.size() && j < s.size(); i++, j++){
            if(s[i] == s[j])
                count++;
            else{
                power[i] = ++count;
                count = 0;
            }
        }
        return *max_element(power.begin(), power.end());
    }
};
