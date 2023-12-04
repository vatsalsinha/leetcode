class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_set<string> st = {"000", "111", "222", "333", "444", "555", "666", "777", "888", "999"};
        string ans = "";
        for(int i = 0; i < num.size(); i++){
            string tmp = "";
            for(int j = 0; j < 3 && i+j < num.size(); j++){
                tmp += num[i+j];
            }
            if(st.count(tmp)){
                if(ans == "" || tmp[0] > ans[0])
                    ans = tmp;
            }
        }
        return ans;
    }
};
