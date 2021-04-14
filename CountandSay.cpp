class Solution {
public:
    string solve(int n){
        if(n == 1){
            return "1";
        }
        else{
            string tmp = solve(n-1)+" ";
            string res = "";
            int count = 1;
            for(int i = 1; i < tmp.size(); i++){
                if(tmp[i-1] == tmp[i]){
                    count++;
                }
                else{
                    res += to_string(count);
                    res += tmp[i-1];
                    count = 1;
                }
            }
            return res;
        }
    }
    string countAndSay(int n) {
        return solve(n);
    }
};
