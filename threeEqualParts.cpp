class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int count = 0;
        for(auto n : arr)
            if(n == 1)
                count++;
        if(count == 0)
            return {0, (int)arr.size()-1};
        if(count % 3 != 0)
            return {-1, -1};
        int k = count/3;
        int i;
        for(i = 0; i < arr.size(); i++)
            if(arr[i] == 1)
                break;
        int start = i;
        int count1 = 0;
        for(i = 0; i < arr.size(); i++){
            if(arr[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }
        int mid = i;
        count1 = 0;
        for(i = 0; i < arr.size(); i++){
            if(arr[i] == 1)
                count1++;
            if(count1 == 2*k + 1)
                break;
        }
        int end = i;
        while(end < arr.size() && arr[start] == arr[mid] && arr[mid] == arr[end]){
            start++; mid++; end++;
        }
        if(end == arr.size())
            return {start-1, mid};
        return {-1, -1};
    }
};
