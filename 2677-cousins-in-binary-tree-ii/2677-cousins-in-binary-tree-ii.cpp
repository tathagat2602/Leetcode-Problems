class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 0});
        int prev = 0;

        while(!qu.empty()) {
            int n = qu.size();
            int temp = 0;
            for(int i = 0; i < n; i++) {
                auto [curr, value] = qu.front(); qu.pop();

                curr -> val = (prev - value);
                int siblings = 0;
                
                if(curr -> right) siblings += curr -> right -> val;
                if(curr -> left) {
                    siblings += curr -> left -> val;
                    qu.push({curr -> left, siblings});
                }
                if(curr -> right) qu.push({curr -> right, siblings});
                
                temp += siblings;
            }
            prev = temp;
        }
        return root;
    }
};