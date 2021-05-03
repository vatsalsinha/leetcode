class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rt;
        
        backtracking(rt, s, 0, 1);
        return rt;
    }
    
    // level indicates how many '.'s inserted
    void backtracking(vector<string> &rt, string& s, int index, int level){
        if(level == 4){
            if(s.size()-index <= 3 && s.size()-index > 0 && check(s))
                rt.push_back(s);
            return;
        }
        
        for(int i=index+1; i<=index+3 && i<s.size(); i++){
            s.insert(i, ".");
            backtracking(rt, s, i+1, level+1);
            s.erase(i, 1);
        }
    }
    
    bool check(string s){       // check if the string is valid or not
        int left = 0, right = 0;
        while(right < s.size()){
            left = right; right++;
            while(right < s.size() && s[right++] !='.')

            if(right - left == 2 && s[left] == '0') return false;
            else if(right - left == 3){
                if(s[left] == '0') return false;
                if(s[left] > '2') return false;
                if(s[left] == '2' && s[left+1] > '5') return false;
                if(s[left] == '2' && s[left+1] == '5' && s[right-1] > '5') return false;
            }
        }
        return true; 
        
        
        
   /* Approach 2 
   bool isValid(string s){
        if(s.size() > 1 && s[0] == '0')
            return false;
        int num = stoi(s);
        return num >=0 && num <= 255;
    }
    void backtrack(vector<string> &ans, string san, string s, int count){
        if(count > 4)
            return;
        if(count ==4 && s.size()==0){
            san.pop_back();
            ans.push_back(san);
            return;
        }
        else if(count == 4 || s.size() == 0)
            return;
        for(int i = 1; i < 4 && i < s.size()+1; i++){
            string sub = s.substr(0,i);
            if(isValid(sub))
                backtrack(ans, san+sub+'.', s.substr(i), count+1);
            else
                continue;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string san = "";
        backtrack(ans, san, s, 0);
        return ans;
    */
    }
};