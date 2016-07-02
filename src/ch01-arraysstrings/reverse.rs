//
/// Time Complexity:    `O(n)` (`n * O(1)` swaps)
/// Spacial Complexity: `O(1)` (reverses array in-place)
///
/// # Examples
///
/// ```
/// use cracking_code_interview::arraystrings::reverse::reverse;
///
/// let arr1 = &mut[1, 2];
/// reverse(arr1);
/// assert_eq!(&[2, 1], arr1);
///
/// let arr2 = &mut[8, 1, 5];
/// reverse(arr2);
/// assert_eq!(&[5, 1, 8], arr2);
///
/// let mut arr3 : &mut[i32] = &mut[];
/// let empty_array : &[i32] = &[];
/// reverse(arr3);
/// assert_eq!(empty_array, arr3);
///
/// ```
pub fn reverse<T>(array: &mut[T]) {
    // Because `array.len()` returns an unsigned integer, we can't just compute
    // left and right and let the algorithm decide to do nothing, as length - 1
    // when length is 0 results in arithmetic overflow.
    // Instead, we check for 0-length arrays explicitly and short-circuit.
    if array.is_empty() {
        return;
    }

    let mut left = 0;
    let mut right = array.len() - 1;
    while left < right {
        // Swap the elements at the left and right pointer.

        // Can't do the following, since it requires two mutable references to
        // the same bit of a data (unless we copy).
        // let tmp = array[left];
        // array[left] = array[right];
        // array[right] = tmp;

        // Use rust's built-in unsafe `swap` function instead.
        array.swap(left, right);

        left = left + 1;
        right = right - 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty() {
        let array : &mut[i32] = &mut[ ];

        reverse(array);

        let expected_empty_array : &[i32] = &[ ];
        assert_eq!(expected_empty_array, array);
    }

    #[test]
    fn single_element() {
        let array = &mut[1];
        reverse(array);
        assert_eq!(&[1], array);
    }

    #[test]
    fn two_elements() {
        let array = &mut[1, 2];
        reverse(array);
        assert_eq!(&[2, 1], array);
    }

    #[test]
    fn three_elements() {
        let array = &mut[1, 8, 3];
        reverse(array);
        assert_eq!(&[3, 8, 1], array);
    }

    #[test]
    fn four_elements() {
        let array = &mut[17, 3, 12, 13];
        reverse(array);
        assert_eq!(&[13, 12, 3, 17], array);
    }

    #[test]
    fn elements_all_the_same() {
        let array = &mut[5, 5, 5, 5];
        reverse(array);
        assert_eq!(&[5, 5, 5, 5], array);
    }

    #[test]
    fn symmetric_elements() {
        let array = &mut[3, 4, 3];
        reverse(array);
        assert_eq!(&[3, 4, 3], array);

        let array = &mut[3, 4, 4, 3];
        reverse(array);
        assert_eq!(&[3, 4, 4, 3], array);
    }

}
