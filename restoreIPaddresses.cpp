class Solution {
public:
    
    bool isValid(string s){
        if(s[0]=='0' && s.size()>1) return false;
        int num=stoi(s);
        return num>=0 && num<=255;
    }
    
    void backtrack(vector<string> &ans, string sans,int count,string s){
        if(count>4) return;
        if(count==4 && s.size()==0){
            sans.pop_back();
            ans.push_back(sans);
            return;
        }
        else if(count==4 || s.size()==0) return;
        
        for(int i=1;i < 4 && i <= s.size();i++){
            string sub=s.substr(0,i);
            if(isValid(sub)){
                backtrack(ans, sans+sub+".",count+1,s.substr(i));
            }
            else{
                continue;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string san="";
        backtrack(ans, san,0,s);
        return ans;
    }
};
