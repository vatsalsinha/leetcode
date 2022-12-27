class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cmax = 0, count = 0;
        for(int i = 0; i < arr.size(); i++){ // if pmax[i] == i, split must be made;
            cmax = max(cmax, arr[i]);
            if(cmax == i)
                count++;
        }
        return count;
    }
};