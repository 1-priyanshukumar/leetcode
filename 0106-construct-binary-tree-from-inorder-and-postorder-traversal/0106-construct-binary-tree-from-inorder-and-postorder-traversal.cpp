class Solution {
public:
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int left,
                    int right) {

        if (left > right)
            return nullptr;

        // Last element in postorder is root
        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        int mid = pos[rootValue];

        // IMPORTANT:
        // Build right subtree first
        root->right = build(inorder,
                             postorder,
                             mid + 1,
                             right);

        root->left = build(inorder,
                            postorder,
                            left,
                            mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        postIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return build(inorder,
                     postorder,
                     0,
                     inorder.size() - 1);
    }
};