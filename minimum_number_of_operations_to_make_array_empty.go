func minOperations(nums []int) int {
    mp := make(map[int]int)
    ans := 0

    for _, num := range nums {
        mp[num]++
    }

    for _, val := range mp {
        if val == 1 {
            return -1
        }
        if val % 3 != 0 {
            ans += 1
        }
        ans += val / 3
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)