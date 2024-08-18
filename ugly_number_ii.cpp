class Solution {
  public:
	int nthUglyNumber(int n) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		unordered_map<long long, bool> mp;
		vector<int> primes = {2, 3, 5};
		pq.push(1);

		while (--n) {
			long long num = pq.top();
			pq.pop();

			for (int prime : primes) {
				long long newUglyNumber = num * prime;

				if (mp.find(newUglyNumber) == mp.end()) {
					mp[newUglyNumber] = true;
					pq.push(newUglyNumber);
				}
			}
		}
		return (int)pq.top();
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)