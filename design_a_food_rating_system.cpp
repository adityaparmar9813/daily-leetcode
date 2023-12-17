struct comp {
    bool operator() (pair<int,string> &a, pair<int, string> &b){
        if(a.first == b.first) return a.second>b.second;
        return a.first < b.first;
    }
};

class FoodRatings {
public:
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>> mp;
    unordered_map<string,string> cuisineFood;
    unordered_map<string,int> foodRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++) {
            mp[cuisines[i]].push({ratings[i],foods[i]});
            cuisineFood[foods[i]]=cuisines[i];
            foodRating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        mp[cuisineFood[food]].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        string x = mp[cuisine].top().second;
        int y = mp[cuisine].top().first;

        while(foodRating[x] != y) {
            mp[cuisine].pop();
            x = mp[cuisine].top().second;
            y = mp[cuisine].top().first;
        }
        return mp[cuisine].top().second;
    }
};

// Time Complexity: O(n*log(n))
// Space Complexity: O(n) 