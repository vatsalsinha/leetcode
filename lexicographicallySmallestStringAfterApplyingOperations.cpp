class Solution {
public:
    string add(string curr, int a){
        for(int i = 0; i < curr.size(); i++){
            if(i % 2){
                int num  = curr[i]-'0';
                num = (num+a)%10;
                curr[i]= num+'0';
            }
        }
        return curr;
    }
    string rotate(string curr, int b){
        b = b % curr.size();
        reverse(curr.begin(),curr.end());
        reverse(curr.begin(),curr.begin()+b);
        reverse(curr.begin()+b,curr.end());
        return curr;
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> res;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            res.push_back(curr);
            string A = add(curr, a);
            if(visited.find(A) == visited.end()){
                q.push(A);
                visited.insert(A);
            }
            string B = rotate(curr, b);
            if(visited.find(B) == visited.end()){
                q.push(B);
                visited.insert(B);
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};
