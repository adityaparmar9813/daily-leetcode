func maxSubarrayLength(nums []int, k int) int {
    maxi, ans, i := 0, 0, 0
    freq := make(map[int]int)
    
    for j:=0; j < len(nums); j++ {
        freq[nums[j]]++
        maxi = max(freq[nums[j]], maxi)
        
        if(maxi > k) {
            for nums[i] != nums[j] {
                freq[nums[i]]--
                i++
            }
            freq[nums[i]]--
            i++
            maxi = k
        }
        ans = max(ans, j-i+1)
    }
    return ans;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
