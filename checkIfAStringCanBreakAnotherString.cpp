class Solution {
public:
    bool canBreak(string x, string y){
        for(int i = 0; i < x.size(); i++){
            if(!(x[i] >= y[i]))
                return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return canBreak(s1,s2) || canBreak(s2,s1);
    }
};
