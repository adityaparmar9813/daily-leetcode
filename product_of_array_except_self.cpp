class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 0);

        int product = 1;
        for(int i=0; i < nums.size(); i++) {
            leftProduct[i] = product;
            product *= nums[i];
        }
        
        product = 1;
        for(int i=nums.size()-1; i >= 0; i--) {
            leftProduct[i] *= product;
            product *= nums[i];
        }
        return leftProduct;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)