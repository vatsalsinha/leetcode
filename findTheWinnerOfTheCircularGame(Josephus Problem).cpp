class Solution {
public:
    int findTheWinner(int n, int k) {
        int win = 0;
        //int sum = n*(n+1)/2;
        for(int i = 1; i < n+1; i++){
            win = (win+k)%i;
            //sum -= win;
        }
        return win+1;
        
        //appraoch 2
        // vector<int> temp;
        // for(int i = 1;i<=n;i++)
        //     temp.push_back(i);
        // int j = 0;
        // while(temp.size()>1)
        // {   int len = temp.size();
        //     j= (j+k-1)%len;
        //     temp.erase(temp.begin()+j);
        //     j--;
        //     j = (j+1)%temp.size();
        // }
        // return temp[0];
        //approach 3
        // queue<int> q;
        // for(int i = 1; i < n+1; i++)
        //     q.push(i);
        // while(q.size() != 1){
        //     int x = k;
        //     while(x>1){
        //         int temp = q.front();
        //         q.pop();
        //         q.push(temp);
        //         x--;
        //     }
        //     q.pop();
        // }
        // return q.front();
    }
};