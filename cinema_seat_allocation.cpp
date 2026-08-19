class Solution {
   public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		unordered_map<int, unordered_set<int>> seats;

		for (auto& r : reservedSeats) {
			int row = r[0];
			int seat = r[1];

			if (seat >= 2 && seat <= 5) {
				seats[row].insert(0);
			}

			if (seat >= 4 && seat <= 7) {
				seats[row].insert(1);
			}

			if (seat >= 6 && seat <= 9) {
				seats[row].insert(2);
			}
		}

		int total = 2 * n;

		for (auto& [row, groups] : seats) {
			if (groups.size() == 3) {
				total -= 2;
			} else {
				total -= 1;
			}
		}

		return total;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)