class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;
        for(int i : target){
            sum += i;
            pq.push(i);
        }
        
        while(pq.top() != 1){
            sum -= pq.top();
            if(sum == 0 || sum >= pq.top()) //  not possible to simulate
                return false;
            int t = pq.top()%sum;// If the sum replace operation was done at a single position multiple times then in that case the sum of remaining numbers were added multiple times to thae number. So to get back the old number we have to substract the remaining sum from the same top element over and over again untill the element becomes less than the remaining sum and any ither element becomes the top value. So the ultimate old value which will not be the top is the remainder i.e. pq.top() % sum. In this way we can save pq.top() / sum iterations in each step.
            if(sum != 1 && t == 0) //All the old numbers should be 1 or greater than 1 for the ans to be true. So if old == 0 then false. But in case the sum becomes 1 (which is actually only possible if there are only 2 elements in array one is top and another is 1 as there are no element less than 1 and top > 1) then the case is true (imagine [1, any int > 1] is always true). So we are skipping that condition by sum != 1
                return false;
            pq.pop();
            pq.push(t);
            sum += t;
        }
        return true;
    }
};
/* 
reverse the simulation ie try making the target array = array of 1s
*/

