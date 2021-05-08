class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // vector<int> even, odd;
        // for(int i = 0; i < A.size(); i++){
        //     if(A[i] % 2 == 0)
        //         even.emplace_back(A[i]);
        //     else
        //         odd.emplace_back(A[i]);
        // }
        // for(auto i : odd){
        //     even.push_back(i);
        // }
        // return even;
        int even = 0;
        int odd = A.size()-1;
        vector<int> res(A.size());
        for(int i = 0; i < A.size(); i++){
            if(A[i] % 2 == 0){
                res[even++] = A[i];
            }
            else{
                res[odd--] = A[i];
            }
        }
        return res;
    }
};
