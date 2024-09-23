//Time Complexity: O(N)
//Space Complexity: O(N)

//Top-Down Approach (Memoization)
class Solution {
public:

    int climbStairs(int n, unordered_map<int, int>& mp) {
        if(n == 0 || n == 1)
            return 1;

        if(mp.find(n) == mp.end()) 
            mp[n] = climbStairs(n - 1, mp) + climbStairs(n - 2, mp);

        return mp[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return climbStairs(n, mp);
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)

//Bottom-up Approach (Tabulation)

class Solution {
public:
    int climbStairs(int n) {
        if( n == 0 || n == 1) 
            return 1;

        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};