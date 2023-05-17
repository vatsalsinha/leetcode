class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        return (double)accumulate(next(salary.begin(),1), next(salary.begin(),salary.size()-1), 0) / (salary.size()-2);
    }
};
