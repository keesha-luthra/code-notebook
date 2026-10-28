
class Solution {
public:
    unordered_map<Node*, Node*> clones;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (clones.count(node))
            return clones[node];

        Node* copy = new Node(node->val);
        clones[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(
                cloneGraph(neighbor)
            );
        }

        return copy;
    }
};
