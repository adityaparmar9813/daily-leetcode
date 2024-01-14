func closeStrings(word1 string, word2 string) bool {
    mp1, mp2 := make([]int, 26), make([]int, 26)

    for _, char := range word1 {
        mp1[char - 'a']++
    }
    for _, char := range word2 {
        mp2[char - 'a']++
    }

    for i:=0; i < 26; i++ {
        if (mp1[i] > 0 && mp2[i] == 0) || (mp1[i] == 0 && mp2[i] > 0) { 
            return false 
        }
    }

    sort.Ints(mp1)
    sort.Ints(mp2)

    return slices.Equal(mp1, mp2)
}

// Time Complexity: O(n)
// Space Complexity: O(1)
