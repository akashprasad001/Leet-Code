/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
         int ans = 0;

        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* node) {

                if (node == NULL) {
                    return make_pair(0, 0);
                }

                auto left = dfs(node->left);
                auto right = dfs(node->right);

                int sum = left.first + right.first + node->val;
                int count = left.second + right.second + 1;

                if (sum / count == node->val) {
                    ans++;
                }

                return make_pair(sum, count);
            };

        dfs(root);

        return ans;
    }
};