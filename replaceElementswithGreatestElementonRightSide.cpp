auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
//     int getMaxRight(vector<int> &v, int start, int end){
//         vector<int> vec(v.begin()+start, v.begin()+end);
//         int high = INT_MIN;
//         for(int i = 0; i < vec.size(); i++){
//             if(high < vec[i])
//                 high = vec[i];
//         }
//         return high;
        
//     }
    vector<int> replaceElements(vector<int>& arr) {
        // for(int i = 0; i < arr.size()-1; i++){
        //     arr[i] = getMaxRight(arr, i+1, arr.size());
        // }
        // arr[arr.size()-1] = -1;
        // return arr;
        int tmp = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        for(int i = arr.size()-2; i > -1; i--){
            int curr = arr[i];
            arr[i] = max(tmp, arr[i+1]);
            tmp = curr;
        }
        return arr;
    }
};
