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
int dfs(TreeNode* node , int &move) {
            if (node == nullptr) return 0;

            // Postorder traversal: process children first
            int leftExcess = dfs(node->left , move);
            int rightExcess = dfs(node->right , move);

            // Total excess at this node
            int totalExcess = node->val + leftExcess + rightExcess - 1;

            // Moves needed are the absolute values of excess coins moved
            move += abs(leftExcess) + abs(rightExcess);

            return totalExcess;
        }
    int distributeCoins(TreeNode* root) {
        int moves= 0;
        
        // Helper function to perform DFS and calculate moves
        dfs(root , moves);
        return moves;
    }
};