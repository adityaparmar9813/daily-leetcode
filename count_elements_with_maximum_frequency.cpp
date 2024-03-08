class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for(auto num: nums) frequency[num]++;

        int freq = 0, ans = 0;
        for(auto [num, count]: frequency) {
            if(count == freq) ans += freq;
            else if(count < freq) continue;
            else ans = freq = count;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)