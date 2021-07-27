class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for(int i = 1; i < folder.size(); i++){
            string result = res[res.size()-1]+"/";
            string before = folder[i].substr(0, result.size());
            if(before != result)
                res.push_back(folder[i]);
        }
        return res;
    }
};
