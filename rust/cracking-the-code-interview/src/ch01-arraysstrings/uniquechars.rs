use std::collections::HashSet;

// Time Complexity:    O(n) (n O(1) insertions)
// Spacial Complexity: O(n) (worst case: all chars are unique)
fn only_unique_chars(s : &str) -> bool {
    let mut found_chars = HashSet::new();
    for c in s.chars() {
        // returns false if character is already in the set
        if !found_chars.insert(c) {
            return false;
        }
    }

    // If this point is reached, there was only one occurrence of each char in
    // the string. Therefore, the string must only contain unique chars.
    return true;
}
