class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int forward = accumulate(nums.begin(), nums.end(), 0), fcount = nums.size()-1;
        int backward = 0, bcount=0;

        vector<int> ans(nums.size());

        for(int i=0;i<nums.size();i++){
            forward -= nums[i];
            int curr = abs(backward - (bcount*nums[i])) + (forward -(nums[i]*fcount));
            
            ans[i] = curr;
            backward += nums[i];
            fcount--;
            bcount++;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)