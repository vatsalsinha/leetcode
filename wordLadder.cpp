class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visited;
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            string tmp = x.first;
            for(int i= 0; i < tmp.size(); i++){
                char ch = tmp[i];
                for(int j = 0; j < 26; j++){
                    tmp[i] = j + 'a';
                    if(words.find(tmp) != words.end() && !visited[tmp]){
                        visited[tmp] = 1;
                        q.push({tmp, x.second + 1});
                    }
                }
                tmp[i] = ch;
            }
            if(tmp == endWord){
                return x.second;
            }
        }
        return 0;
    }
};
