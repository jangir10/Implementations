/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* root, unordered_map<int, vector<int>>& mp,
                   int parent) {
        if (!root)
            return;
        if (root->left)
            mp[root->val].push_back(root->left->val);
        if (root->right)
            mp[root->val].push_back(root->right->val);
        if (parent != -1) {
            mp[root->val].push_back(parent);
        }
        makeGraph(root->left, mp, root->val);
        makeGraph(root->right, mp, root->val);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        if (!root || (!root->left && !root->right))
            return 0;
        int minute = 0;
        unordered_map<int, vector<int>> mp;
        makeGraph(root, mp, -1);
        queue<int> q;
        set<int> visited;
        visited.insert(start);
        q.push(start);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int curr = q.front();
                q.pop();
                vector<int> temp = mp[curr];
                for (int i = 0; i < temp.size(); i++) {
                    if (visited.find(temp[i]) == visited.end()) {
                        visited.insert(temp[i]);
                        q.push(temp[i]);
                    }
                }
            }

            minute++;
        }
        return minute - 1;
    }
};