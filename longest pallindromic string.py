class Solution:
    def isPalindrome(self, s):
        if(s == s[::-1]):
            return 1
        return 0
    def findMax(self, a, n, m):
        high = 0
        pos = []
        for i in range(0, n):
            for j in range(0, m):
                if(high < a[i][j]):
                    high = a[i][j];
                    pos.insert(0, i)
                    pos.insert(1, j)
        return pos;
    def longestPalindrome(self, s: str) -> str:
        N =len(s)
        M = len(s)
        lp = [[0 for x in range(N)] for y in range(M)]  
        for i in range(0, len(s)):
            res = ""
            for j in range(i, len(s)):
                res = res + s[j]
                if(i<j):
                    lp[i][j] = 0
                if(i == j):
                    lp[i][j] = 1
                else:
                    if(self.isPalindrome(res)):
                        lp[i][j] = len(res)
                    else:
                        lp[i][j] = 0
        arr = self.findMax(lp, N, M)
        i = arr[0]
        j = arr[1]
        return s[i:j+1]