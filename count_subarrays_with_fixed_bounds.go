
func countSubarrays(nums []int, minK int, maxK int) int64 {
    mini, maxi := -1, -1
    i, j, n := 0, 0, len(nums)
    var cnt int64 = 0

    for j < n {
        if nums[j] < minK || nums[j] > maxK {
            mini = -1
            maxi = -1
            i = j+1
        }
        if nums[j] == minK {
            mini = j
        }
        if nums[j] == maxK {
            maxi = j
        }

        cnt += int64(max(0, min(mini, maxi)-i+1))
        j++
    }
    return cnt
}

// Time Complexity : O(n)
// Space Complexity : O(1)
