func numSubarrayProductLessThanK(nums []int, k int) int {
    if k <= 1 {
        return 0
    }
    var curr uint64 = 1
    count, l := 0, 0

    for r := 0; r < len(nums); r++ {
        curr *= uint64(nums[r])

        for curr >= uint64(k) {
            curr /= uint64(nums[l])
            l++
        }
        count += (r-l+1)
    }
    return count
}

// Time Complexity: O(n)
// Space Complexity: O(1)
