use std::collections::HashSet;

//
/// Time Complexity:    `O(n)` (`n * O(1)` insertions)
/// Spacial Complexity: `O(n)` (worst case: all chars are unique)
///
/// # Examples
///
/// ```
/// use cracking_code_interview::arraystrings::uniquechars::only_unique_chars;
/// assert_eq!(only_unique_chars("donald"), false);
/// assert_eq!(only_unique_chars("raby"), true);
/// ```
pub fn only_unique_chars(s : &str) -> bool {
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty_string() {
        assert_eq!(only_unique_chars(""), true);
    }

    #[test]
    fn single_char() {
        assert_eq!(only_unique_chars("a"), true);
    }

    #[test]
    fn two_chars_different() {
        assert_eq!(only_unique_chars("ab"), true);
    }

    #[test]
    fn two_chars_same() {
        assert_eq!(only_unique_chars("aa"), false);
    }

    #[test]
    fn many_chars_different() {
        assert_eq!(only_unique_chars("abcdefghijkl"), true  );
    }

    #[test]
    fn many_chars_same() {
        assert_eq!(only_unique_chars("aabaaa"), false);
    }
}
