func timeRequiredToBuy(tickets []int, k int) int {
    var ans int = 0;
        
    for index, val := range tickets {
        if index > k {
            ans += min(tickets[k]-1, val);
        } else {
            ans += min(tickets[k], val);
        }
    }
    return ans; 
}

// Time Complexity : O(n)
// Space Complexity : O(1)
