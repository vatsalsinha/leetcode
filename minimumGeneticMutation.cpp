class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> visited;
        vector<char> t = {'A', 'C', 'G', 'T'};
        unordered_set<string> words(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({start, 0});
        while(!q.empty()){
            auto x = q.front();
            string tmp = x.first;
            q.pop();
            for(int i = 0; i < tmp.size(); i++){
                char ch = tmp[i];
                for(int j = 0; j < t.size(); j++){
                    tmp[i] = t[j];
                    if(words.find(tmp) != words.end() && !visited[tmp]){
                        visited[tmp] = 1;
                        q.push({tmp, x.second+1});
                    }
                }
                tmp[i] = ch;
            }
            if(tmp == end){
                return x.second;
            }
        }
        return -1;
    }
};
