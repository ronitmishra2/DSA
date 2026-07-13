#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store index of each value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int left, int right) {

        // Base case
        if (left > right)
            return nullptr;

        // Current root
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int index = inorderMap[rootValue];

        // Build left subtree
        root->left = helper(preorder, left, index - 1);

        // Build right subtree
        root->right = helper(preorder, index + 1, right);

        return root;
    }
};

// Inorder Traversal (to verify the tree)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (to verify the tree)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Preorder Traversal : ";
    preorderTraversal(root);

    cout << "\nInorder Traversal  : ";
    inorderTraversal(root);

    return 0;
}