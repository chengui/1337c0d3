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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

void print(TreeNode* root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout<< ' '<<root->val<<' ';
    print(root->right);
}

int main()
{
    TreeNode *root = NULL;
    TreeNode a(4), b(2), c(7), d(1), e(3), f(6), g(9);
    root = &a, a.left = &b, a.right = &c, b.left = &d, b.right = &e, c.left = &f, c.right = &g;
    print(root);
    cout << endl;
    Solution s = Solution();
    print(s.invertTree(root));
    cout << endl;
}
