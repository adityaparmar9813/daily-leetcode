class Solution {
   public:
	int minOperations(vector<int>& nums, int k) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		int ans = 0;

		for (long long num : nums) {
			pq.push(num);
		}

		while (pq.size() >= 2 && pq.top() < k) {
			long long num1 = pq.top();
			pq.pop();
			long long num2 = pq.top();
			pq.pop();

			pq.push(num1 * 2 + num2);
			ans++;
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)