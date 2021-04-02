class Solution {
public:
    int maxArea(vector<int>& height) {
        // o(n^2): 54/60 test cases passed.
        // int max = 0;
        // int temp, l, b;
        // for(int i = 0; i < height.size(); i++){
        //     for(int j = i+1; j < height.size(); j++){
        //         l = height[i] > height[j] ? height[j] : height[i];
        //         temp = l*(j-i);
        //         if(temp > max){
        //             max = temp;
        //         }
        //     }
        // }
        // return max;

        //o(n):
        int max = 0, l = 0, r = height.size()-1;
        int temp, len;
        while(l < r){
            len = height[l] > height[r] ? height[r] : height[l];
            temp = len*(r-l);
            max = max > temp ? max : temp;
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max;
    }
};
