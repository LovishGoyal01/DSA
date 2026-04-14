/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode* DummyNode=new ListNode(-1);
        ListNode* curr = DummyNode;
        int sum=0,carry=0;
        while(t1!=nullptr || t2!=nullptr){
            sum=carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
            carry=sum/10;
            ListNode* Node = new ListNode(sum%10);
            curr->next = Node;
            curr=curr->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry==1){
            ListNode* Node = new ListNode(1);
            curr->next=Node;
        }
      return DummyNode->next;
    }
};