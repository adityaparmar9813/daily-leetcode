class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
		int n=nums.size();
		vector<bool>ans(m, true);

		for(int i=0; i < m; i++) {
			vector<int>temp;
			for(int j=l[i]; j <= r[i]; j++) temp.push_back(nums[j]);
			sort(temp.begin(), temp.end());
            
			if(temp.size() > 1) {
				for(int k=0; k < temp.size()-1; k++) {
					if(temp[k+1]-temp[k] != temp[1]-temp[0]) ans[i] = false;
				}
			} 
		}
		return ans;
    }
};

// Time Complexity : O(n^2*log(n))
// Space Complexity : O(n)