#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val =x;
        left =nullptr;
        right =nullptr;
    }
};

class Solution{
    public:
        int maxPathSum(TreeNode* root){
            int maxi=INT_MIN;
            maxPathDown(root, maxi);
            return maxi;
        }
    private:
        int maxPathDown(TreeNode* node, int &maxi){
            if(node==NULL) return 0;
            int left= max(0, maxPathDown(node->left, maxi));
            int right= max(0, maxPathDown(node->right, maxi));
            maxi= max(maxi, left+right+node->val);
            return max(left, right)+node->val;

        }
};

int main() {

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << obj.maxPathSum(root) << endl;

    return 0;
}
