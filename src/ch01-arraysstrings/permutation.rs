use std::collections::HashMap;

fn count_char_frequencies(s: &str) -> HashMap<char, i32> {
    let mut freqs: HashMap<char, i32> = HashMap::new();
    for ch in s.chars() {
        if freqs.contains_key(&ch) {
            *freqs.get_mut(&ch).unwrap() += 1;
        } else {
            freqs.insert(ch, 1);
        }
    }

    freqs
}

fn sort_chars(s: &str) -> Vec<char> {
    let mut chars: Vec<char> = s.chars().collect();
    chars.sort();
    chars
}

// TODO: document with tests

pub fn is_permutation(a: &str, b: &str) -> bool {
    count_char_frequencies(a) == count_char_frequencies(b)
}

pub fn is_permutation_sort(a: &str, b: &str)  -> bool {
    sort_chars(a) == sort_chars(b)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn hashmap_empty_strings() {
        assert!(is_permutation("", ""));
        assert!(!is_permutation("a", ""));
        assert!(!is_permutation("", "a"));
        assert!(!is_permutation("ab", ""));
        assert!(!is_permutation("", "ab"));
    }

    #[test]
    fn hashmap_single_char_and_is_permutation() {
        assert!(is_permutation("a", "a"));
    }

    #[test]
    fn hashmap_single_char_and_not_permutation() {
        assert!(!is_permutation("a", "b"));
        assert!(!is_permutation("b", "a"));
    }

    #[test]
    fn hashmap_two_chars_and_is_permutation() {
        assert!(is_permutation("aa", "aa"));
        assert!(is_permutation("ab", "ab"));
        assert!(is_permutation("ab", "ba"));
    }

    #[test]
    fn hashmap_two_chars_and_not_permutation() {
        assert!(!is_permutation("ab", "a1"));
        assert!(!is_permutation("ab", "12"));
    }

    #[test]
    fn hashmap_many_chars() {
        assert!(!is_permutation("eo3i4u89", "w8wu892"));
        assert!(is_permutation("abcdef12345", "3ad21c4bf5e"));
        assert!(is_permutation("aaabbbccc", "cccbbbaaa"));
        assert!(is_permutation("aaabbbaaa", "bbbaaaaaa"));
    }

    #[test]
    fn sort_empty_strings() {
        assert!(is_permutation_sort("", ""));
        assert!(!is_permutation_sort("a", ""));
        assert!(!is_permutation_sort("", "a"));
        assert!(!is_permutation_sort("ab", ""));
        assert!(!is_permutation_sort("", "ab"));
    }

    #[test]
    fn sort_single_char_and_is_permutation_sort() {
        assert!(is_permutation_sort("a", "a"));
    }

    #[test]
    fn sort_single_char_and_not_permutation() {
        assert!(!is_permutation_sort("a", "b"));
        assert!(!is_permutation_sort("b", "a"));
    }

    #[test]
    fn sort_two_chars_and_is_permutation_sort() {
        assert!(is_permutation_sort("aa", "aa"));
        assert!(is_permutation_sort("ab", "ab"));
        assert!(is_permutation_sort("ab", "ba"));
    }

    #[test]
    fn sort_two_chars_and_not_permutation() {
        assert!(!is_permutation_sort("ab", "a1"));
        assert!(!is_permutation_sort("ab", "12"));
    }

    #[test]
    fn sort_many_chars() {
        assert!(!is_permutation_sort("eo3i4u89", "w8wu892"));
        assert!(is_permutation_sort("abcdef12345", "3ad21c4bf5e"));
        assert!(is_permutation_sort("aaabbbccc", "cccbbbaaa"));
        assert!(is_permutation_sort("aaabbbaaa", "bbbaaaaaa"));
    }

}

// count frequencies (hash_map)
// sort
