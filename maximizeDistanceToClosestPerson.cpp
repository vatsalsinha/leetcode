class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //O(n) tc ; o(1) sc
        int n = seats.size();
        int i = -1, j = 0; // i -> prev filled seat to the left of index k ; j -> next filled seat to the right of index k 
        int ans = 0;
        for(int k = 0; k < n; k++){
            if(seats[k] == 1)
                i = k;
            else{
                while(j < n && seats[j] == 0 || j < k)
                    j++;
                int left = i == -1 ? n : k-i;
                int right = j == n ? n : j-k;
                ans = max(ans, min(left, right));
            }
        }
        return ans;
        // O(N) TC
        // O(n) SC
       /* int n = seats.size();
        vector<int> left(n, n), right(n, n);
        for(int i = 0; i < n; i++){
            if(seats[i] == 1)
                left[i] = 0;
            else if(i > 0)
                left[i] = left[i-1] + 1;
        }
        for(int i = n-1; i >= 0; i--){
            if(seats[i] == 1)
                right[i] = 0;
            else if(i < n-1)
                right[i] = right[i+1] + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(seats[i] == 0)
                ans = max(ans, min(left[i], right[i]));
        }
        return ans;
        */
    }
};
