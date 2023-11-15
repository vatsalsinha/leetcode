class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        //For an array of length n, the biggest value we could have is n. This scenario would be when the array is [1, 2, 3, ..., n].
        sort(arr.begin(), arr.end());
        int pos = 1; //by the rules of the problem, the first element must be equal to 1
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] >= pos+1){
                pos++;
            }
        }
        cout<<pos;
        return pos;
    }
};
