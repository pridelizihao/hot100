# include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int size1 = matrix.size();
        int size2 = matrix[0].size();
        if (size1 == 0 or size2 == 0)
            return 0;

        int rows = matrix.size();
        int columns = matrix[0].size();
        int maxside = 0;

        vector<vector<int>> dp(rows, vector<int>(columns));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(matrix[i][j] == '1'){
                    if (i == 0 or j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    maxside = max(maxside, dp[i][j]);
                } 
            }
        }

        int maxsquare = maxside * maxside;
        return maxsquare;
    }
};

// 使用动态规划，dp[i][j]表示以(i, j)为右下角的最大正方形的边长。对于每个位置，如果matrix[i][j] == '1'，则dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1，否则dp[i][j] = 0。最后返回maxside * maxside即可。