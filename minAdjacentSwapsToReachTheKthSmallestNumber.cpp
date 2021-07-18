class Solution {
public:
    /* 
    The first thing which we need to do is to find the correct position of the element. For example, 142 and 421. In this 1 needs to be in the last position.
Next we swap the elements until 1 comes to its correct position.
We continue the above 2 steps for all the elements.
    */
    int countSwaps(string t, string num){
        int i = 0, j = 0, count = 0;
        while(i < t.size()){
            j = i;
            while(t[j] != num[i]) j++;
            while(i < j){
                swap(t[j], t[j-1]);
                j--;
                count++;
            }
            i++;
        }
        return count;
    }
    int getMinSwaps(string num, int k) {
        int i = 0;
        string t = num;
        do{
            i++;
        }while(next_permutation(num.begin(), num.end()) && i < k);
        return countSwaps(t, num);
    }
};
