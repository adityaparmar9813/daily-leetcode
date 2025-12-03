int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

class ParallelogramsCounter {
   public:
	void add(int pos) {
		++counts_[pos];
		++total_;
	}

	int total() const {
		int result = 0;
		for (auto [_, count] : counts_) {
			result += (total_ - count) * count;
		}
		return result / 2;
	}

   private:
	int total_ = 0;
	std::unordered_map<int, int> counts_;
};

class Solution {
	int countTrapezoidsImpl(const vector<vector<int>>& points, bool normalize) {
		std::unordered_map<int, ParallelogramsCounter> counters;

		for (int point = 1; point != points.size(); ++point) {
			for (int prev = 0; prev != point; ++prev) {
				int dx = points[prev][0] - points[point][0];
				int dy = points[prev][1] - points[point][1];

				if (normalize) {
					int d = gcd(dx, dy);
					dx /= d;
					dy /= d;
				}

				if (dx < 0 || (dx == 0 && dy < 0)) {
					dx = -dx;
					dy = -dy;
				}

				int key = 10000 * dx + dy;
				int height = dy * points[prev][0] - dx * points[prev][1];

				counters[key].add(height);
			}
		}

		int result = 0;
		for (const auto& [key, counter] : counters) {
			result += counter.total();
		}

		if (!normalize) {
			result >>= 1;
		}

		return result;
	}

   public:
	int countTrapezoids(vector<vector<int>>& points) {
		int trapezoids = countTrapezoidsImpl(points, true);
		int parallelograms = countTrapezoidsImpl(points, false);
		return trapezoids - parallelograms;
	}
};

// Time Comoplexity: O(n^2)
// Space Complexity: O(n^2)