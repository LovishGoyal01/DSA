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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,val;
        ListNode *dummyNode=new ListNode(-1);
        ListNode *dummyHead=dummyNode;
        ListNode *first=l1;
        ListNode *second=l2;
        while(first!=nullptr || second!=nullptr){
            val=0;
            if(first!=nullptr) {
                val=first->val;
                first=first->next;
            }
            if(second!=nullptr){
                val+=second->val;
                second=second->next;
            }
            val=carry+val;
            carry=val/10;
            val=val%10;
            ListNode* node=new ListNode(val);
            dummyNode->next=node;
            dummyNode=dummyNode->next;
        }
        if(carry==1){
            ListNode* node=new ListNode(carry);
            dummyNode->next=node;
        }
        return dummyHead->next;
    }
};