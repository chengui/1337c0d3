#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define SSTR(x) static_cast<std::ostringstream &>((std::ostringstream() << std::dec << x)).str()

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

string str(TreeNode* root)
{
    if (root == NULL)
        return "";
    string left = str(root->left);
    string val = SSTR(root->val);
    string right = str(root->right);
    return left + " " + val + " " + right;
}

int main()
{
    TreeNode *root = NULL;
    TreeNode a(4), b(2), c(7), d(1), e(3), f(6), g(9);
    root = &a, a.left = &b, a.right = &c, b.left = &d, b.right = &e, c.left = &f, c.right = &g;
    cout << str(root) << endl;
    Solution s = Solution();
    cout << str(s.invertTree(root)) << endl;
}
