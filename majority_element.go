func majorityElement(nums []int) int {
    ans, count := 0, 0

    for _, num := range nums {
        if count == 0 {
            ans = num
        }

        if num == ans {
            count++
        } else {
            count--
        }
    }
    return ans
}

// Time Complexity : O(n)
// Space COmplexity : O(1)