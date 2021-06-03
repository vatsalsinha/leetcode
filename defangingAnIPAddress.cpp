class Solution {
public:
    string defangIPaddr(string address) {
        // string s;
        // for(auto c : address){
        //     if(c == '.'){
        //         string tmp = "[";
        //         tmp += c;
        //         tmp += "]";
        //         s += tmp;
        //     }
        //     else
        //         s += c;
        // }
        // return s;
        string res = "";
        int l = address.size();
        for(int i = l-1; i > -1; i--){
            if(address[i] == '.'){
                address = address.substr(0, i) + "[.]" + address.substr(i+1);
            }
        }
        return address;
    }
};
