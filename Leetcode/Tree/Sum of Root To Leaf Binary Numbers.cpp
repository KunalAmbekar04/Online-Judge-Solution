// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	int sum = 0;

	int decimalVal(vector<int> digit) {
		int decimal = 0;
		int power = 0;
		for (auto itr : digit) {
			decimal = decimal * 2 + itr;
		}
		return decimal;
	}

	void sumUtil(TreeNode *root, vector<int> digit) {
		if (!root) {
			return;
		}
		digit.push_back(root->val);
		if (!root->left && !root->right) {
			sum += decimalVal(digit);
		}
		sumUtil(root->left, digit);
		sumUtil(root->right, digit);
	}

public:
	int sumRootToLeaf(TreeNode* root) {
		if (!root) {
			return 0;
		}
		vector<int> digit;
		sumUtil(root, digit);
		return sum;
	}
};