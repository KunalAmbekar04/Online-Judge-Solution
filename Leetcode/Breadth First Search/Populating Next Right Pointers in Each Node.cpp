// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Solution 1

class Solution {
	void solve(Node *l, Node *r) {
		if (!l || !r) {
			return;
		}
		l->next = r;
		r->next = NULL;

		solve(l->left, l->right);
		solve(l->right, r->left);
		solve(r->left, r->right);
	}
public:
	Node* connect(Node* root) {
		if (!root) {
			return NULL;
		}

		solve(root->left, root->right);
		return root;
	}
};

// Solution 2

class Solution {
	void solve(Node *root) {
		if (root->left && root->right) {
			root->left->next = root->right;
			if (root->next) {
				root->right->next = root->next->left;
			}

			solve(root->left);
			solve(root->right);

			if (root->next) {
				root->right->next = root->next->left;
			}
		}
	}
public:
	Node* connect(Node* root) {
		if (!root) {
			return NULL;
		}
		solve(root);
		return root;
	}
};

// Solution 3

class Solution {
public:
	Node* connect(Node* root) {
		if (!root) {
			return NULL;
		}
		list<Node*> q;
		q.push_back(root);

		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				Node *node = q.front();
				q.pop_front();

				if (node->left) {
					node->left->next = node->right;
					q.push_back(node->left);
				}

				if (node->right) {
					if (node->next) {
						node->right->next = node->next->left;
					}
					q.push_back(node->right);
				}
			}
		}
		return root;
	}
};