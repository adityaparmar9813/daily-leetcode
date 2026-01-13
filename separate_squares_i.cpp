class Solution {
   public:
	double square_area(vector<vector<int>>& squares, const double y) {
		double area = 0;

		for (const auto& s : squares) {
			double L = s[2], y0 = s[1] + L;
			if (y >= y0) {
				continue;
			}

			double h = min(L, y0 - y);
			area += L * h;
		}
		return area;
	}

	double separateSquares(vector<vector<int>>& squares) {
		double A0 = square_area(squares, -1e9);
		double A2 = A0 / 2.0;
		double minY = INT_MAX, maxY = INT_MIN;

		for (const auto& s : squares) {
			double L = s[2], y0 = s[1];
			minY = min(minY, y0);
			maxY = max(maxY, y0 + L);
		}

		double l = minY, r = maxY, m;
		const double epsilon = 1e-5;

		while (r - l > epsilon) {
			m = (l + r) / 2;
			double area = square_area(squares, m);

			if (area > A2) {
				l = m;
			} else {
				r = m;
			}
		}
		return l;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)