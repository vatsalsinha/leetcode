class Solution {
public:
    string getSmallestString(int n, int k) {
        string str(n , 'a');
        k -= n;
        int i = n-1;
        while(k > 0){
            str[i--] += min(k, 25); // most you can add at ith pos is 25;
            k -= min(k, 25); // subtract from sum
        }
        return str;
    }
};