class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto email : emails){
            string tmp;
            for(auto c : email){
                if(c == '+' || c == '@')
                    break;
                if(c == '.')
                    continue;
                tmp += c;
            }
            tmp += email.substr(email.find('@'));
            s.insert(tmp);
        }
        return s.size();
    }
};
