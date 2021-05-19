// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        //vector<int> s;
        while(start <= end){
            int mid = start + (end - start)/2;
            //if(isBadVersion(mid))
                //s.push_back(mid);
            if(isBadVersion(mid) == false)
                start = mid + 1;
            else 
                end = mid-1;
        }
        return start;
    }
};
