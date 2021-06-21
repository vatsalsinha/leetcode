class Solution {
public:
    int countTriplets(vector<int>& A) {
        /*  
            a == b, thus
            a ^ a = b ^ a, thus
            0 = b ^ a, thus
            arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
            prefix[k+1] = prefix[i]
        */
        // int xors[arr.size()+1];
        // xors[0] = 0;
        // int ans = 0;
        // for(int i = 0; i < arr.size(); i++){
        //     xors[i+1] = xors[i]^arr[i];
        // }
        // for(int i = 0; i < arr.size(); i++){
        //     for(int k = i+1; j < arr.size(); j++){
        //         if(xors[i] == xors[k+1]) 
        //             ans += k-i;
        //     }
        // }
        // return ans;
        
        /* 
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];
        unordered_map<int, int> count, total;
        for (int i = 0; i < n; ++i) {
            res += count[A[i]]++ * (i - 1) - total[A[i]];
            total[A[i]] += i;
        }
        return res;
        */
        int n = A.size(), res = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];
            res += count[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return res;
    }
};