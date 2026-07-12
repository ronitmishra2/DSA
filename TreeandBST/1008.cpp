#include <bits/stdc++.h>
using namespace std;

//definition of binary tree
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A){
        int i=0;
        return build(A,i,INT_MAX);
    }
    TreeNode* build(vector<int>& A,int &i,int bound){
        if(i==A.size() || A[i]>bound) return NULL;
        TreeNode* root=new TreeNode(A[i++]);
        root->left=build(A,i,root->val);
        root->right=build(A,i,bound);
        return root;
    }

};
void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        while (n--) {
            TreeNode* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }
}

int main() {
    Solution s;

    vector<int> preorder = {8,5,1,7,10,12};

    TreeNode* root = s.bstFromPreorder(preorder);

    cout << "Tree:\n";
    printLevelOrder(root);

    return 0;
}

