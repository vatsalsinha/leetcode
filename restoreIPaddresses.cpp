class Solution {
public:
//recursion
    void restore(string ip, string s, vector<string>& ans, int index, int level){
        //cout<<ip<<"\n";
        if(level == 4){
            if(index == s.length())
                ans.push_back(ip.substr(0, ip.size()-1));
            return;
        }
        int num = 0;
        for(int i = index; i < index+3 && i <= s.length(); i++){
            //string tp = s.substr(index, i);
            num = num*10 + (s[i]-'0');
          //  if(stoi(s.substr(index, i)) <= 255)
            if(num > 255)
                return;
            restore(ip + to_string(num) + ".",s,ans, i+1,level+1);
            if(s[index] == '0') // since there can be no leading zeros
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        restore("", s, ans, 0, 0);
        return ans;
    }
};

/* Alternative solutions using backtracking
class Solution {
public:
    bool check(string s){
        int left = 0, right = 0;
        while(right < s.length()){
            left = right;
            right++;
            while(right < s.length() && s[right++] != '.')
                if(right - left == 2 && s[left] == '0')
                    return false;
                else if(right - left == 3){
                    if(s[left] == '0')
                        return false;
                    if(s[left] > '2')
                        return false;
                    if(s[left] == '2' && s[left+1] > '5')
                        return false;
                    if(s[left] == '2' && s[left+1] == '5' && s[right-1] > '5')
                        return false;
                }
        }
        return true;
    }
    void backtrack(vector<string> &ans, string &s, int index, int level){
        if(level == 4){
            if(s.length()-index <=3 && s.length()-index > 0 && check(s)){
                ans.push_back(s);
            }
            return;
        }
        for(int i = index+1; i <= index + 3 && i < s.length(); i++){
            s.insert(i, ".");
            backtrack(ans, s, i+1, level+1);
            s.erase(i,1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(ans, s, 0, 1);
        return ans;
    }
};
*/