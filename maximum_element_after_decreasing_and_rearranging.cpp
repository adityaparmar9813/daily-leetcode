class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        int ans = 1;
        for (auto num: arr) ans = min(ans + 1, num);

        return ans;
    }
};

// Time Complwxity : O(nlogn)
// Space Complexity : O(1)