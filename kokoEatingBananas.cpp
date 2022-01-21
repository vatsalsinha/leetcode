class Solution {
public:
    bool isPossible(vector<int>& piles, int h, long mid){
        long count = 0;
        for(int pile : piles){
            count += pile/mid;
            if(pile%mid)
                count++;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long low = 1;
        long high = *max_element(piles.begin(), piles.end());
        while(low < high){
            long mid = low + (high-low)/2;
            if(isPossible(piles, h, mid)){
                high = mid;
            }
            else
                low = mid+1;
        }
        return (int)low;
    }
};
