class Solution {
public:
    bool isMatch(string s, string p) {
         int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Base case: empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns with '*' at the beginning
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' can match empty (dp[i][j-1]) or one/more characters (dp[i-1][j])
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
        
    }
};