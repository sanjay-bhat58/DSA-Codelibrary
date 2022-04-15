class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        ans.append([1])
        if numRows == 1:
            return ans
        ans.append([1,1])
        if numRows == 2:
            return ans
        for i in range(2,numRows):
            row = [1]*(i+1)
            for j in range(1,i):
                row[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(row)
        return ans