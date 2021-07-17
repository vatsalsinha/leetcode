class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        // int count = 0;
        // for(auto n : arr)
        //     if(n == 1)
        //         count++;
        // if(count == 0)
        //     return {0, (int)arr.size()-1};
        // if(count % 3 != 0)
        //     return {-1, -1};
        // int k = count/3;
        // int i;
        // for(i = 0; i < arr.size(); i++)
        //     if(arr[i] == 1)
        //         break;
        // int start = i;
        // int count1 = 0;
        // for(i = 0; i < arr.size(); i++){
        //     if(arr[i] == 1)
        //         count1++;
        //     if(count1 == k + 1)
        //         break;
        // }
        // int mid = i;
        // count1 = 0;
        // for(i = 0; i < arr.size(); i++){
        //     if(arr[i] == 1)
        //         count1++;
        //     if(count1 == 2*k + 1)
        //         break;
        // }
        // int end = i;
        // while(end < arr.size() && arr[start] == arr[mid] && arr[mid] == arr[end]){
        //     start++; mid++; end++;
        // }
        // if(end == arr.size())
        //     return {start-1, mid};
        // return {-1, -1};
        
        int n = arr.size();
        vector<int> one;
        for(int i = 0; i < n; i++)
            if(arr[i] == 1)
                one.push_back(i);
        int cnt = one.size();
        if(cnt == 0)
            return {0, n-1};
        if(cnt % 3 != 0)
            return {-1, -1};
        int s = one[0], t = one[cnt/3], u = one[(cnt/3)*2];
        while(u < n && arr[s] == arr[t] && arr[s] == arr[u]){
            s++;
            u++;
            t++;
        }
        if(u == n)
            return {s-1, t};
        return {-1, -1};
                
    }
};