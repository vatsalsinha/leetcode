class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // for(int i = 0; i < arr.size(); i++){
        //     if(arr[i] == 0){
        //         int c = arr.size()-1;
        //         while(c > i){
        //             arr[c] = arr[c-1];
        //             c--;
        //         }
        //         i++;
        //     }
        // }
        vector<int> result;
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(count + i >= arr.size()){
                break;
            }
            result.push_back(arr[i]);
            if(arr[i] == 0){
                if(count + i >= arr.size()-1){
                    break;
                }
                result.push_back(0);
                count++;
            }
        }
        arr = result;
    }
};
