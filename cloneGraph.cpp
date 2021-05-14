/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:
void dfs_clone(Node* node, unordered_map<Node*, bool>& visited, Node*& clone_node, unordered_map<int, Node*>& address)
{
	if (visited[node])
	{
		clone_node = address[node->val];
		return;
	}
	
	visited[node] = true;
	clone_node = new Node(node->val, vector<Node*>(node->neighbors.size(), NULL));
	address[clone_node->val] = clone_node;

	vector<Node*>& neighbors = node->neighbors;

	for (int i = 0; i < neighbors.size(); i++)
		dfs_clone(neighbors[i], visited, clone_node->neighbors[i], address);
}

Node* cloneGraph(Node* node)
{
    if(node == NULL)
        return node;
	Node* clone_node = NULL;
	unordered_map<Node*, bool> visited;
	unordered_map<int, Node*> address;
	dfs_clone(node, visited, clone_node, address);
	return clone_node;
}
};
