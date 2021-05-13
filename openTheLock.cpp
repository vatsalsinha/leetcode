class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        if(deadend.find("0000") != deadend.end())
            return -1;
        visited.insert("0000");
        q.push("0000");
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return count;
                }
                for(int j = 0; j < 4; j++){
                    char tmp = curr[j];
                    curr[j] = tmp == '9' ? '0' : tmp+1;
                    if(deadend.find(curr) == deadend.end() && visited.find(curr) == visited.end()){
                        q.push(curr);
                        visited.insert(curr);
                    }
                    
                    curr[j] = tmp == '0' ? '9' : tmp-1;
                    if(deadend.find(curr) == deadend.end() && visited.find(curr) == visited.end()){
                        q.push(curr);
                        visited.insert(curr);
                    }
                    curr[j] = tmp;
                }
            }
            count++;
        }
        return -1;
    }
};
