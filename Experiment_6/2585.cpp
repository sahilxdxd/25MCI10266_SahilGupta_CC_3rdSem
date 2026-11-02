class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (auto &t : types) {
            int count = t[0];
            int marks = t[1];

            vector<int> ndp(target + 1, 0);

            for (int score = 0; score <= target; score++) {
                if (dp[score] == 0) continue;

                for (int k = 0; k <= count; k++) {
                    int newScore = score + k * marks;

                    if (newScore > target) break;

                    ndp[newScore] =
                        (ndp[newScore] + dp[score]) % MOD;
                }
            }

            dp = move(ndp);
        }

        return dp[target];
    }
};
