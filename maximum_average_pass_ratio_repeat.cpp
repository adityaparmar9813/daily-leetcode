struct Compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return (double)(a.first + 1) / (a.second + 1) -
		           (double)a.first / a.second <
		       (double)(b.first + 1) / (b.second + 1) -
		           (double)b.first / b.second;
	}
};

class Solution {
   public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

		for (auto& c : classes) {
			pq.push({c[0], c[1]});
		}

		while (extraStudents--) {
			auto [pass, total] = pq.top();
			pq.pop();
			pq.push({pass + 1, total + 1});
		}

		double sum = 0.0;
		while (!pq.empty()) {
			auto [pass, total] = pq.top();
			pq.pop();
			sum += (double)pass / total;
		}

		return sum / classes.size();
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)