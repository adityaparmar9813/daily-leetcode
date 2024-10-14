class Solution {
  public:
	long long maxKelements(std::vector<int> &nums, int k) {
		priority_queue<int> pq;

		for (int x : nums) {
			pq.push(x);
		}

		long long score = 0;

		while (!pq.empty() && k > 0) {
			int x = pq.top();
			pq.pop();
			score += x;

			int newElement = ceil(x / 3.0);
			pq.push(newElement);

			k--;
		}

		return score;
	}
};

// Time Complexity : O(k * log(n))
// Space Complexity : O(n)