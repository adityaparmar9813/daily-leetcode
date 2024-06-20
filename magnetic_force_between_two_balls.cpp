class Solution {
public:
    bool check(const vector<int>& position, int m, int minDist) {
        int count = 1, l = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - l >= minDist) {
                count++;
                l = position[i];

                if (count >= m) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int left = 1, right = position.back() - position.front();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(position, m, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)
