class Solution {
   public:
	int maxCandies(vector<int>& status, vector<int>& candies,
	               vector<vector<int>>& keys,
	               vector<vector<int>>& containedBoxes,
	               vector<int>& initialBoxes) {
		vector<bool> v(status.size(), false);
		vector<bool> boxava(status.size(), false);
		int sum = 0;
		queue<int> q;

		for (int i : initialBoxes) {
			boxava[i] = true;
			if (status[i]) q.push(i);
		}

		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			if (v[temp]) continue;
			sum += candies[temp];
			v[temp] = true;

			for (int i : keys[temp]) {
				status[i] = 1;
				if (boxava[i] && !v[i]) q.push(i);
			}

			for (int i : containedBoxes[temp]) {
				boxava[i] = true;
				if (status[i] && !v[i]) q.push(i);
			}
		}

		return sum;
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)