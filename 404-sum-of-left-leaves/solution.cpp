#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return sumOfLeftLeaves(root->right);
        if (root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main()
{
    TreeNode *root = NULL;
    TreeNode a(3), b(9), c(20), d(15), e(7);
    root = &a, a.left = &b, a.right = &c, c.left = &d, c.right = &e;
    Solution s = Solution();
    cout << s.sumOfLeftLeaves(root) << endl;
}
