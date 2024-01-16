class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> v;
    int size;
    
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            mp[val] = size++;
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            int last = v[--size];
            v.pop_back();

            v[mp[val]] = last;
            mp[last] = mp[val];
            
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random = rand();
        int randIndex = random % size;
        return v[randIndex];
    }
};

// Time Complexity : O(1)
// Space Complexity : O(n)
