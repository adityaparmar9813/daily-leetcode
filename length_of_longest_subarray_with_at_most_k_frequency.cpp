class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 0, i = 0;
        unordered_map<int, int> freq;
        int ans = 0;
        
        for(int j=0; j < nums.size(); j++){
            freq[nums[j]]++;
            maxi = max(freq[nums[j]], maxi);
            
            if(maxi > k) {
                while(nums[i] != nums[j]) {
                    freq[nums[i++]]--;
                }
                freq[nums[i++]]--;
                maxi = k;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
