func pivotInteger(n int) int {
    sum, curr := n*(n+1)/2, 0;

    for i:=1; i <= n; i++ {
        curr += i;
        if(curr == sum-curr+i) {
            return i;
        }
    }
    return -1;
}

// Time Complexity : O(n)
// Space Complexity : O(1)