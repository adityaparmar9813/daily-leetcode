class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> mono;

        for(int i=0; i < temperatures.size(); i++) {
            while(!mono.empty() && temperatures[mono.top()] < temperatures[i]) {
                ans[mono.top()] = i-mono.top();
                mono.pop();
            }
            mono.push(i);
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
