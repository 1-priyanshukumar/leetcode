class Solution {
public:
    Node* connect(Node* root) {

        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            Node* prev = NULL;

            for (int i = 0; i < n; i++) {

                Node* curr = q.front();
                q.pop();

                // Connect previous node to current node
                if (prev != NULL)
                    prev->next = curr;

                prev = curr;

                // Add children
                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }

            // Last node of current level
            prev->next = NULL;
        }

        return root;
    }
};