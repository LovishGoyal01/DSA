/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* copyNode = nullptr;

        while(temp!=nullptr){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next=node;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=nullptr){
            copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = nullptr;
            temp=temp->next->next; 
        }
         temp=head;
        Node* dmyNode = new Node(-1);
        Node* res = dmyNode;
         while(temp!=nullptr){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp=temp->next; 
            res=res->next;
        }
        return dmyNode->next;

    }
};