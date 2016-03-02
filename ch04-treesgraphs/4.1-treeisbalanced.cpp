#include <cassert>

struct BinaryTree {
    int value;
    BinaryTree* left;
    BinaryTree* right;

    explicit
    BinaryTree(int value = 0)
    : value(value)
    , left(0)
    , right(0)
    {
    }
};

inline
bool isLeaf(BinaryTree* tree)
{
    return (tree->left || tree->right);
}

int getMaxAndMinDepth(BinaryTree* tree,
                      int& minEndDepth,
                      int& maxEndDepth,
                      int currentDepth)
{
    assert(tree); // should never happen if algo works correctly

    // NOTE: if we're worried about huge trees causing stock overflow, then
    // impose depth limit here (and return some error/exception saying tree
    // to big). Or use a stack and make this algo iterative (still need to
    // impose limit to be 100% sure we won't run out of memory though)x

    if (isLeaf(tree)) {
        // Reached end of path, record the path length if it's the min or max
        if (currentDepth < min) {
            minEndDepth = currentDepth;
        }
        if (currentDepth > max) {
            maxEndDepth = currentDepth;
        }
    } else {
        if (tree->left) {
            getMaxAndMinDepth(tree->left, minEndDepth, maxEndDepth, currentDepth + 1);
        }
        if (tree->right) {
            getMaxAndMinDepth(tree->right, minEndDepth, maxEndDepth, currentDepth + 1);
        }
    }
}

bool isBalanced(BinaryTree* tree)
{
    // Time Complexity: theta(n), where `n` is the number of nodes.
    // Always looks through every node. See notes for better algorithm.
    // Spatial Complexity: O(d), where `d` is the maximum depth.
    // We use memory for each recursive call to `getMaxAndMinDepth`.

    int minEndDepth = 0;
    int maxEndDepth = 0;
    getMaxAndMinDepth(tree, minEndDepth, maxEndDepth, 0);

    return (std::abs(maxEndDepth - minEndDepth) < 2);
}


// NOTES:
//
// We're assuming no cycles because it is a tree.
//
// Could also solve this by computing height of both sub-trees (recursively)
// and comparing the result at each level (aborting if they're different).
// This has the advantage of aborting early if imbalance found early (making
// algo O(n)).
//
// Are trees wide or deep? If deep, use BFS. If wide, use DFS.
//
// Think about imposing limits depth (if DFS) or breadth (if BFS) if you're
// worried about out-of-memory or stack overflow errors.
//
