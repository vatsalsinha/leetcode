class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // vector<int> l(letters.size());
        // int a;
        // for(int i = 0; i < letters.size(); i++){
        //     l[i] = (int)letters[i];
        // }
        // int t = (int)target;
        // if(t > l[l.size()-1])
        //     return letters[0];
        // for(int i = 0; i < letters.size(); i++){
        //     if(l[i] > t){
        //         return (char)l[i];
        //     }
        // }
        // return letters[0];
        int start = 0, end = letters.size()-1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(letters[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return target >= letters[letters.size()-1] ? letters[0] : letters[start];
    }
};
