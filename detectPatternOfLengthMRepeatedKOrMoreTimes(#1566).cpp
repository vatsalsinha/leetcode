class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for(int i = 0; i < arr.size() && i+m < arr.size(); i++){
            if(arr[i] == arr[i+m]) // arr[i] == arr[i+m] => pattern is getting satisfied
                count++;
            else//(arr[i] == arr[i+m])
                count = 0;
            if(count >= m*(k-1))
                return true;
        }
        return false;
    }
};
