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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return l > r ? l + 1 : r + 1;
    }
};

int main()
{
    TreeNode *root = NULL;
    TreeNode a(1), b(2), c(3), d(4);
    root = &a, a.left = &b, b.left = &c, b.right = &d;
    Solution s = Solution();
    cout << s.maxDepth(root) << endl;
}
