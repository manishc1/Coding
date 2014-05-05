/*
Sink Zero in Binary Tree. Swap zero value of a node with non-zero value of one of its descendants 
so that no node with value zero could be parent of node with non-zero.
*/

void sinkzero(Node& node, deque<int>& d) {
	if (node == null) return;
	if (node->val == 0) d.push_back(node);
	else {
		swap(node->val, d.front()->val);
		d.pop_front();
		d.push_back(node);
	}
	sinkzero(node->left, d);
	sinkzero(node->right, d);
	if (!d.empty() && d.back() == node) d.pop_back();
}
