class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long ans = 0;

        for(int i = 0; i < n && k > 0; i++, k--) {
            ans += max(happiness[n-i-1] - i, 0);
        }
        return ans;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)
