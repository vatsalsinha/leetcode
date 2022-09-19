class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < paths.size(); i++){
            stringstream ss(paths[i]);
            string dir, file;
            getline(ss, dir, ' '); // gets directory
            while(getline(ss, file, ' ')){
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(')-1); // get content
                string loc = dir + '/' + file.substr(0, file.find('(')); // get file name
                mp[content].push_back(loc);
            }
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            if(it.second.size() > 1)
                ans.push_back(it.second);
        }
        return ans;
    }
};
