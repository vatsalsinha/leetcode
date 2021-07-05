class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> umap;
        for(auto k : knowledge)
            umap[k[0]] = k[1];
        string res;
        //string tmp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                string key;
                while(++i && i < s.size() && s[i] != ')')
                    key += s[i];
                res += (umap.count(key)) ? umap[key] : "?";
                
            }
            else{
                res += s[i];
            }
        }
        return res;
        /*
        string res;
        unordered_map<string, string> umap;
        for(auto k : knowledge)
            umap[k[0]] = k[1];
        string tmp;
        bool toPut = false; //for keys
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                toPut = true;
            }
            if(toPut){
                tmp += s[i];
            }
            if(s[i] == ')'){
                toPut = false;
                tmp = tmp.substr(1,tmp.size()-2);
                if(!umap.count(tmp))
                    res += '?';
                else
                    res += umap[tmp];
                tmp = "";
            }
            if(toPut == false)
                if(s[i] != ')')
                    res += s[i];
        }
        //res.erase(remove(res.begin(), res.end(), ')'), res.end());
        return res;
        */
    }
};
