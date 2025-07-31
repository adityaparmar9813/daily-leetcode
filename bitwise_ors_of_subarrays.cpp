class Solution {
   public:
	int subarrayBitwiseORs(vector<int>& arr) {
		unordered_set<int> result;
		unordered_set<int> current;

		for (int num : arr) {
			unordered_set<int> next;

			next.insert(num);

			for (int prev : current) {
				next.insert(prev | num);
			}

			for (int val : next) {
				result.insert(val);
			}

			current = next;
		}

		return result.size();
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(m)