class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int bouquets = 0, flowers = 0;

            for (int i = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= mid) {
                    flowers++;

                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n * log(max(bloomday))
// Space Complexity : O(1)
