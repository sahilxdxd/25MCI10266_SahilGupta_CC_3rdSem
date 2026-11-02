class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            vector<long long> ndp(target + 1, 0);

            for (int sum = 0; sum <= target; sum++) {
                if (dp[sum] == 0) continue;

                for (int face = 1; face <= k; face++) {
                    if (sum + face <= target) {
                        ndp[sum + face] =
                            (ndp[sum + face] + dp[sum]) % MOD;
                    }
                }
            }

            dp = move(ndp);
        }

        return dp[target];
    }
};
