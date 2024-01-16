type RandomizedSet struct {
    mp map[int]int
    vec []int
    size int
}


func Constructor() RandomizedSet {
    mp := make(map[int]int)
    vec := make([]int, 0)
    return RandomizedSet{mp, vec, 0}
}


func (this *RandomizedSet) Insert(val int) bool {
    _, ok := this.mp[val];
    if ok {
        return false
    }
    this.mp[val] = this.size
    this.size = this.size+1
    this.vec = append(this.vec, val)
    return true
}


func (this *RandomizedSet) Remove(val int) bool {
    _, ok := this.mp[val]; 
    if !ok {
        return false
    }

    i := this.mp[val]
    this.size = this.size-1
    
    this.vec[i] = this.vec[this.size]
    this.vec[this.size] = this.vec[i]
    this.mp[this.vec[i]] = i
    this.vec = this.vec[:this.size]
    delete(this.mp, val)
    return true
}


func (this *RandomizedSet) GetRandom() int {
    i := rand.Intn(this.size)
    return this.vec[i]
}

// Time Complexity: O(1)
// Space Complexity: O(n)
