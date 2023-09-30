class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        vector<int> left(nums.size());
        left[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            left[i] = min(left[i - 1], nums[i]);
        }

        stack<int> st;
        for (int j = nums.size() - 1; j >= 0; --j) {
            if (nums[j] > left[j]) {
                while (!st.empty() && st.top() <= left[j]) st.pop();
                if (!st.empty() && st.top() < nums[j]) return true;

                st.push(nums[j]);
            }
        }

        return false;
    }
};