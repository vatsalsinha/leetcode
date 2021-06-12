class Solution {
public:
    int minPartitions(string n) {
        //return *max_element(n.begin(), n.end()) - '0';
        char t = '0';
        for(char c : n){
            if(c > t)
                t = c;
        }
        return t-'0';
    }
};
