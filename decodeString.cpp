class Solution {
public:
    string decodeString(string s) {
        stack<int> stCount;
        stack<string> st;
        string res = "";
        int i = 0;
       while(i < s.length()){
            if(isdigit(s[i])){
                int n = 0;
                while(isdigit(s[i])){
                    n = 10*n + (s[i]-'0');
                    i++;
                }
                stCount.push(n);
            } 
            else if(s[i] == '['){
                st.push(res);
                res = "";
                i++;
            }
            else if(s[i] == ']'){
                string tmp = st.top();
                st.pop();
                int c = stCount.top();
                stCount.pop();
                for(int i = 0; i < c; i++){
                    tmp += res;
                }
                res = tmp;
                i++;
            }
           else{
               res += s[i];
               i++;
           }
        }
        return res;
    }
};
