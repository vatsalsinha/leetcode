class Solution {
public:
    void rev(vector<char>& s, int i, int j){
        if(i>=j)
            return;
        swap(s[i], s[j]);
        rev(s, i+1, j-1);
    }
    void reverseString(vector<char>& s) {
        rev(s, 0, s.size()-1);
    } 
};
