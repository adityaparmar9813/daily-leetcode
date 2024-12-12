class Solution {
  public:
	long long pickGifts(vector<int> &gifts, int k) {
		priority_queue<int> pq;

		for (int gift : gifts) {
			pq.push(gift);
		}

		while (k--) {
			pq.push(sqrt(pq.top()));
			pq.pop();
		}

		long long ans = 0;

		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}

		return ans;
	}
};

// Time Complexity: O(k * log(n))
// Space Complexity: O(n)