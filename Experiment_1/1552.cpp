class Solution {
public:

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position[position.size() - 1] - position[0];
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceBalls(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

private:

    bool canPlaceBalls(vector<int>& position, int m, int dist) {
        int count = 1;
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {

            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];

                if (count == m) {
                    return true;
                }
            }
        }

        return false;
    }
};
