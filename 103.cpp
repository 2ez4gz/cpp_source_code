//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend) {
    if (poststart > postend) return nullptr;
    TreeNode* root = new TreeNode(postorder[postend]);
    int cut;
    for (cut = instart; cut <= inend; ++cut) {
        if (inorder[cut] == root->val) break;
    }
    TreeNode* left = build(inorder, instart, cut - 1, postorder, poststart, poststart + cut - instart - 1);
    TreeNode* right = build(inorder, cut + 1, inend, postorder, poststart + cut - instart, postend - 1);
    root->left = left;
    root->right = right;
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0) return nullptr;
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
int main()
{
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};

    buildTree(inorder, postorder);
}