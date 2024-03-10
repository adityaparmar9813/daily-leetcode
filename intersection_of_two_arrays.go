func intersection(nums1 []int, nums2 []int) []int {
    mp := make(map[int]int)
    ans := make([]int, 0)

    for _, num := range nums1 {
        mp[num]++
    }
    for _, num := range nums2 {
        if mp[num] > 0 {
            ans = append(ans, num)
            mp[num] = 0
        }
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)