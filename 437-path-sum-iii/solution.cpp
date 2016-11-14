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
    int pathSumRec(TreeNode *root, int sum, bool inc)
    {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL)
            return (inc && root->val==sum) ? 1 : 0;
        if (inc)
            return (root->val==sum) + pathSumRec(root->left, sum-root->val, true) + pathSumRec(root->right, sum-root->val, true);
        else
            return pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathSumRec(root, sum, false) + pathSumRec(root, sum, true);
    }
};

int main()
{
    TreeNode *root = NULL;
    int sum = 8;
    TreeNode a(10), b(5), c(-3), d(3), e(2), f(11), g(3), h(-2), i(1);
    root = &a, a.left=&b, a.right=&c, b.left=&d, b.right=&e, c.right=&f, d.left=&g, d.right=&h, e.right=&i;
    // TreeNode a(1);
    // int sum = 1;
    // root = &a;
    Solution s = Solution();
    cout << s.pathSum(root, sum) << endl;

}
