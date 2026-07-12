#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> st;

        while (true) {

            // Push all left nodes
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            // Visit the top node
            root = st.top();
            st.pop();

            if (--k == 0)
                return root->val;

            // Move to right subtree
            root = root->right;
        }
    }
};

// Function to insert into BST
TreeNode* insert(TreeNode* root, int val) {

    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
              5
            /   \
           3     6
          / \
         2   4
        /
       1

    Inorder: 1 2 3 4 5 6
    */

    TreeNode* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\n";

    Solution obj;

    int k = 3;

    cout << "Kth Smallest Element = " << obj.kthSmallest(root, k);

    return 0;
}