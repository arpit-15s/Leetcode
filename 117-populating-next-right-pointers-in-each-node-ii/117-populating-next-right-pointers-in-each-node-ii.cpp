/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> temp_q;
            Node *temp_node = q.front();
            q.pop();
            while(!q.empty()){
                temp_node -> next = q.front();
                if(temp_node -> left != NULL)
                    temp_q.push(temp_node -> left);
                if(temp_node -> right != NULL)
                    temp_q.push(temp_node -> right);
                temp_node = q.front();
                q.pop();
            }
            temp_node -> next = NULL;
            if(temp_node -> left != NULL)
                temp_q.push(temp_node -> left);
            if(temp_node -> right != NULL)
                temp_q.push(temp_node -> right);
            q = temp_q;
        }
        return root;
    }
};