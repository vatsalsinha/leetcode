class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int size = digits.size();
        digits[size-1]++;
        for (int i = size-1; i > 0; i--)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                digits[i-1]++;
            }
        }
        if (digits[0] == 10)
        {
            digits.push_back(0);
            digits[0] = 0;
            for (int i = size; i > 0; i--)
                {
                    digits[i] = digits[i-1];
                }
            digits[0] = 1;
        }
        return digits;
    }
};
