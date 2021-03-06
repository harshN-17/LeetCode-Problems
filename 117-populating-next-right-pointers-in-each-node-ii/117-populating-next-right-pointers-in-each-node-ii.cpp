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
        Node* cur = root, *nxt=NULL, *head=NULL;
        while(cur!=NULL){
            while(cur!=NULL){
                if(cur->left){
                    if(nxt!=NULL)
                        nxt->next = cur->left;
                    else head = cur->left;
                    nxt=cur->left;
                }
                if(cur->right){
                    if(nxt!=NULL)
                        nxt->next=cur->right;
                    else head = cur->right;
                    nxt = cur->right;
                }
                cur = cur->next;
            }
            cur=head;
            head=NULL;
            nxt=NULL;
        }
        return root;
    }
};