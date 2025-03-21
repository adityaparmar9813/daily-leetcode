class Solution {
   public:
	vector<string> findAllRecipes(vector<string>& recipes,
	                              vector<vector<string>>& ingredients,
	                              vector<string>& supplies) {
		available_supplies =
		    unordered_set<string>(supplies.begin(), supplies.end());
		for (size_t i = 0; i < recipes.size(); i++) {
			recipe_to_ingredients[recipes[i]] = ingredients[i];
		}
		for (const string& recipe : recipes) {
			can_make(recipe);
		}
		return result;
	}

   private:
	unordered_set<string> available_supplies;
	unordered_map<string, vector<string>> recipe_to_ingredients;
	unordered_map<string, int> visited;
	vector<string> result;

	bool can_make(string recipe) {
		if (visited.count(recipe)) {
			return visited[recipe] == 1;
		}
		if (available_supplies.count(recipe)) {
			return true;
		}
		if (!recipe_to_ingredients.count(recipe)) {
			return false;
		}
		visited[recipe] = 0;
		for (const string& ingredient : recipe_to_ingredients[recipe]) {
			if (!can_make(ingredient)) {
				visited[recipe] = -1;
				return false;
			}
		}
		visited[recipe] = 1;
		result.push_back(recipe);
		return true;
	}
};

// Time Complexity: O(n * m)
// Space Complexity: O(n)