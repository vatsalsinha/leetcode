class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() < 3)
            return 0;
        int a = 0, b = 0;
        // if a[i-1] == a[i]  && a[i] == a[i+1]
            // remove the a[i]
        for(int i = 1; i < colors.size() - 1; i++){
            if (colors[i-1] == colors[i]  && colors[i] == colors[i+1])
                if(colors[i] == 'A')
                    a += 1;
                else
                    b += 1;
        }
        return a > b;
    }
};
