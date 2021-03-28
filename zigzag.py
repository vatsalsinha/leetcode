class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s
        res = ""
        delta = -1
        j = 0
        res = [[] for i in range(numRows)]
        for c in s:
            res[j].append(c)
            if(j == 0 or j == numRows-1):
               delta *= -1
            j += delta
        outstr = ""
        for row in res:
            outstr += ''.join(row)
        return outstr
