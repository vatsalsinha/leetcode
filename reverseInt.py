class Solution:
    def reverse(self, x: int) -> int:
        if(x <-2**31 and x >= 2**31):
            return 0
        if(x == 0):
            return 0
        count = 0
        temp = abs(x)
        while(temp != 0):
            temp2 = temp%10
            temp = temp//10
            count += 1
        temp  = abs(x)
        res = 0
        count = count - 1
        while(temp != 0):
            temp1 = temp%10 
            temp = temp // 10 
            res += temp1*(10**count)
            count = count - 1
        if(not (res >= -2**31 and res < 2**31)):
            return 0
        if(x < 0):
            return -res
        if(x>0):
            return res
