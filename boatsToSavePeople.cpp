class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        if(accumulate(people.begin(), people.end(), 0) <= limit)
            return 1;
        int count = 0, i = 0, j = people.size()-1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            count++;
            j--;
        }
        return count;
    }
};

