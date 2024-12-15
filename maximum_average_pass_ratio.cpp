class Solution {
  public:
	double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
		priority_queue<pair<double, int>> pq;
		vector<vector<int>> temp = classes;
		double ans = 0.0;

		for (int i = 0; i < classes.size(); i++) {
			double ratio1 = (double)classes[i][0] / classes[i][1];
			double ratio2 = (double)(classes[i][0] + 1) / (classes[i][1] + 1);

			pq.push({ratio2 - ratio1, i});
		}

		while (extraStudents--) {
			int idx = pq.top().second;
			pq.pop();

			temp[idx][0]++;
			temp[idx][1]++;

			double newchange1 = (double)temp[idx][0] / temp[idx][1];
			double newchange2 = (double)(temp[idx][0] + 1) / (temp[idx][1] + 1);

			pq.push({newchange2 - newchange1, idx});
		}

		double total = 0.0;

		for (auto it : temp) {
			total += (double)it[0] / it[1];
		}

		return total / temp.size();
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)