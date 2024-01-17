func uniqueOccurrences(arr []int) bool {
    mp := make(map[int]int)
    mpmp := make(map[int]int)

    for _, val := range arr {
        mp[val]++
    }
    for _, val := range mp {
        mpmp[val]++
    }
    for _,val := range mpmp {
        if val != 1 {
            return false
        }
    }
    return true
}

// Time Complexity : O(n)
// Space Complexity : O(n)
