class Solution {
public:
    // bool isArithmetic(vector<int> tmp){
    //     sort(tmp.begin(), tmp.end(), greater<int>());
    //     for(int i = 0; i < tmp.size()-1; i++){
    //         if(tmp[i+1] - tmp[i] != tmp[1] - tmp[0])
    //             return false;
    //     }
    //     return true;
    // }
    vector<bool> checkArithmeticSubarrays(vector<int>& n, vector<int>& l, vector<int>& r) {
        // approach 1:
        // vector<bool> ans(l.size(),  false);
        // for(int i = 0; i < l.size(); i++){
        //     vector<int> tmp(begin(nums)+l[i], begin(nums)+r[i]+1);
        //     if(isArithmetic(tmp))
        //         ans[i] = true;
        // }
        // return ans;
        
        vector<bool> res;
    for (auto i = 0; i < l.size(); ++i) {
        int mn_e = INT_MAX, mx_e = INT_MIN, len = r[i] - l[i] + 1, j = l[i];
        for (int j = l[i]; j <= r[i]; ++j) {
            mn_e = min(mn_e, n[j]);
            mx_e = max(mx_e, n[j]);
        }
        if (mx_e == mn_e)
            res.push_back(true);
        else if ((mx_e - mn_e) % (len - 1))
             res.push_back(false);
        else {
            vector<bool> diffs(len);
            int pat = (mx_e - mn_e) / (len - 1);
            for (; j <= r[i]; ++j) {
                if ((n[j] - mn_e) % pat || diffs[(n[j] - mn_e) / pat])
                    break;
                diffs[(n[j] - mn_e) / pat] = true;
            }
            res.push_back(j > r[i]);
        }
    }
    return res;
        
    }
};
