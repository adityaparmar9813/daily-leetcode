class Solution {
   public:
	vector<int> queryResults(int limit, vector<vector<int>>& queries) {
		unordered_map<int, int> colors;
		unordered_map<int, int> colorCount;
		vector<int> ans;
		int distinctColors = 0;

		for (auto& query : queries) {
			int index = query[0], newColor = query[1];

			if (colors.count(index)) {
				int prevColor = colors[index];

				colorCount[prevColor]--;
				if (colorCount[prevColor] == 0) {
					distinctColors--;
					colorCount.erase(prevColor);
				}
			}

			colors[index] = newColor;

			if (colorCount[newColor] == 0) {
				distinctColors++;
			}
			colorCount[newColor]++;

			ans.push_back(distinctColors);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)