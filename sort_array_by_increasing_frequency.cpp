
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> count(201, 0);
        vector<vector<int>> freqStore(101);
        vector<int> ans;

        for (int num: nums) {
            count[num + 100]++;
        }

        for (int i = 100; i >= -100; i--) {
            freqStore[count[i + 100]].push_back(i);
        }

        for (int i = 1; i <= 100; i++) {
            for (int num: freqStore[i]) {
                for (int i = 0; i < count[num + 100]; i++) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
