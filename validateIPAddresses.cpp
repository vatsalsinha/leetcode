class Solution {
public:
    string validIPAddress(string IP) {
        int countIP4 = count(IP.begin(), IP.end(), '.');
        int countIP6 = count(IP.begin(), IP.end(), ':');
        if(countIP4 && countIP6)
            return "Neither";
        vector<string> vec;
        if(countIP4 == 3){
            string tmp;
            for(auto ch : IP){
                if(ch == '.'){
                    vec.push_back(tmp);
                    tmp = "";
                }
                else
                    tmp += ch;
            }
            vec.push_back(tmp);
            if(vec.size() != 4)
                return "Neither";
            int flag = 1;
            for(auto s : vec){
                if(s[0] == '0' && s.size() > 1)
                    return "Neither";
                else{
                    for(auto ch : s){
                        if(!(ch >= '0' && ch <= '9'))
                            return "Neither";
                    }
                    if(s.size() > 3)
                        return "Neither";
                    int n = s != ""  ? stoi(s) : -2;
                    if(0 <= n && n <= 255)
                        flag = 1;
                    else
                        return "Neither";
                }
            }
            return flag ? "IPv4" : "Neither";
        }
        if(countIP6 == 7){
            unordered_set<char> st = {'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
            string tmp;
            for(auto ch : IP){
                if(ch == ':'){
                    vec.push_back(tmp);
                    tmp = "";
                }
                else
                    tmp += ch;
            }
            vec.push_back(tmp);
            cout<<vec.size();
            if(vec.size() != 8)
                return "Neither";
            int flag = 0;
            for(auto s : vec){
                if(s.size() > 4 || s == "")
                    return "Neither";
                for(auto ch : s){
                    if(isalpha(ch) && st.count(ch) == 0)
                        return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};
