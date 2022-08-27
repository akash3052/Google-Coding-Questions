class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string,int> ump;
    string solve(TreeNode* root){
        if(!root)
            return "";
        string left = solve(root->left);
        string right = solve(root->right);
        string s = "("+left+to_string(root->val)+right+")";
      // note -> we are checking ump[s] == 1 to check duplicates. If a node is present 3 times then ump[s] will become 2, hence we will not go inside this if condition.
      // Therefore, even if a node is present 3 or 4 times,it will be added only one time in our final answer res.
        if(ump[s]==1){
            res.push_back(root);
        }
        ump[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)
            return res;
        solve(root);
        return res;
    }
};
