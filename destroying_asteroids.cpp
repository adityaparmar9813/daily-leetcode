class Solution {
   public:
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		long long newMass = mass;
		sort(asteroids.begin(), asteroids.end());

		for (const int& asteroid : asteroids) {
			if (asteroid > newMass) {
				return false;
			}
			newMass += asteroid;
		}

		return true;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)