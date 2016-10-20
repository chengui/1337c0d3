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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    TreeNode *p = NULL, *q = NULL;
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6);
    p = &a, a.left = &b, a.right = &c, b.left = &d, b.right = &e;
    q = &f;
    Solution s = Solution();
    cout << s.isSameTree(p, q) << endl;
}
