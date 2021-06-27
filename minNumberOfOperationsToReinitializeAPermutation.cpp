class Solution {
public:
    // void perform(vector<int>& arr, vector<int>& perm, int n){
    //     for(int i = 0; i < n; i++){
    //         if(i%2)
    //             arr[i] = perm[n/2 + (i-1)/2];
    //         else
    //             arr[i] = perm[i/2];
    //     }
    // }
    // bool check(vector<int>& arr, vector<int>& perm, int n){
    //     for(int i = 0; i < n; i++)
    //         if(arr[i] != i)
    //             return false;
    //     return true;
    // }
    int reinitializePermutation(int n) {
        // vector<int> arr(n), perm(n);
        // for(int i = 0; i < n; i++)
        //     perm[i] = i;
        // int steps = 1;
        // while(true){
        //     perform(arr, perm, n);
        //     perm=arr;
        //     if(check(arr,perm,n))
        //         return steps;
        //     steps++;
        // }
        // return steps;
        
        
        //approach 2
        //check of 1st number 
        //if 1 is return to it's orignal position than similar after that no. of operation perform all number set on that starting position
        int pos = n/2;
        int steps = 1;
        while(pos!=1){
            steps++;
            pos = pos % 2 ? n/2 + (pos-1)/2 : pos/2;
        }
        return steps;
    }
};
