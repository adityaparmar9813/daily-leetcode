func countSubarrays(nums []int, k int) int64 {
    n, count, maxi := len(nums), 0, 0
    var ans int64 = 0

    for _, val := range nums {
        maxi = max(maxi, val)
    }

    for l, r := 0, 0; r < n; r++ {
        if nums[r] == maxi {
            count += 1
        } 

        for count >= k {
            if nums[l] == maxi {
                count -= 1
            }
            l++
        }
        ans += int64(l)
    }
    return ans
}

// Time Complexity: O(n)
// Space Complexity: O(1)
