//Time Complexity: O(N)
//Space Complexity: O(N)
//there are always (m-1) steps to move down and (n-1) steps to move right
//we know that nCr = n!/(n-r)!r!. substitute (m-1) and (n-1) in r we get (m+n-2)!/(m-1)!(n-1)!

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};