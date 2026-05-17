from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        maxside = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    maxside = max(maxside, 1)
                    currentside = min((len(matrix) - i), (len(matrix[0]) - j))
                    for k in range(1, currentside):
                        flag = True
                        if matrix[i+k][j+k] == '0':
                            break
                        for m in range(k):
                            if matrix[i+k][j+m] == '0' or matrix[i+m][j+k] == '0':
                                flag = False
                                break
                        if flag:
                            maxside = max(maxside, k+1)
                        else:
                            break
        
        return maxside * maxside