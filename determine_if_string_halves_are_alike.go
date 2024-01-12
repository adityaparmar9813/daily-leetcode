var vowels = map[byte]bool {
    'a': true, 'e': true, 'i': true, 'o': true, 'u': true,
    'A': true, 'E': true, 'I': true, 'O': true, 'U': true,
}

func halvesAreAlike(s string) bool {
    vowelcount := 0
    for i := 0; i < len(s) / 2; i++ {
        if vowels[s[i]] {
            vowelcount++
        }
        if vowels[s[len(s) - i - 1]] {
            vowelcount--
        }
    }
    return vowelcount == 0
}

// Time Complexity : O(n)
// Space Complexity : O(1)
