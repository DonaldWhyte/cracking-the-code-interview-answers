
struct Node {
    std::vector<Node*> outNodes;
    bool visited;

    explicit
    Node(const std::vector<Node*>& outNodes)
    : outNodes(outNodes)
    , visited(false)
    {
    }
};

bool isRouteToNode(Node* source, Node* destination) {
    assert(source);

    if (source == destination) {
        return true;
    }

    auto nextNode = source->outNodes.begin();
    for (; nextNode != source->outNodes.end(); ++nextNode) {
        assert(*nextNode);
        if (!(*nextNode)->visited) {
            const bool isRoute = isRouteToNode((*nextNode));
            if (isRoute) {
                return true;
            }
        }
    }

    return false;
}


// NOTES:
//
// Using DFS with cycle detection, to prevent infinite loops.
//
// Assumes visited flags are initially set to false. Could also use a set to
// contain all nodes if we can't assume this. (this means we have O(n) additional
// memory usage due to the set).
//
// Using pointers of nodes to identity end of route (i.e. we've found the
// target node). Could use an extra field on the node if desired.
//
// If we care about the SHORTEST path, then we should use BFS.
//
