struct BST {
    int value;
    BST* left;
    BST* right;

    explicit
    BST(int value)
    : value(value)
    , left(0)
    , right(0)
    {
    }

    void add(int newValue)
    {
        if (newValue < value) { // left in tree
            if (left) {
                left->add(newValue);
            } else {
                left = new BST(newValue);
            }
        } else {
            if (right) {
                right->add(newValue);
            } else {
                right = new BST(newValue);
            }
        }
    }

};

BST* createBST1(const bsl::vector<int>& uniqueSortedNums)
{
    if (uniqueSortedNums.empty()) {
        return 0;
    }

    BST* root = new BST(uniqueSortedNums.first());

    auto it = uniqueSortedNums.begin() + 1; // start w/ second elem
    for (; it != uniqueSortedNums.end(); ++it) {
        root->add(*it);
    }

    return root;
}

// NOTES:
//
// Assuming binary seach tree bias is < and >=.
//
// Inefficient! This takes O(nlogn), because we go through the logn search
// process n times (once for each node). A better solution is given below.

BST* createMinimalBST(int* arr, int start, int end)
{
    if (end < start) {
        return 0;
    }

    int mid = (start + end) / 2;
    BST* node = new BST(arr[mid]);
    node.left = createMinimalBST(arr, start, mid - 1);
    node.right = createMinimalBST(arr, mid + 1, end);
    return node;
}

BST* createBST2(const bsl::vector<int>& uniqueSortedNums)
{
    // O(n) time complexity, since `createMinimalBST` is executed exactly `n`
    // times.
    // Spatial complexity is O(1), if exclude the memory taken by the tree
    // (which is `O(n)` of course).
    return createMinimalBST(
        uniqueSortedNums.data(), 0, uniqueSortedNums.size());
}
