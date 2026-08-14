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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        // if(head==NULL)
        // {
        //     return head;
        // }
        if(head->next==NULL && n==1)
        {
            delete head;
            head=NULL;
            return 0;
        }

        ListNode *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        if(count==n){
            ListNode *node=head;
            head=head->next;
            delete node;
            return head;
        }
        int pos=(count-n);
        ListNode *temp1=head;
        for(int i=1;i<pos &&  temp1!=NULL ; i++)
        {
            temp1=temp1->next;
        }
        if(temp1==NULL )
        {
            cout<<"invalid";
            return 0;
        }
        ListNode * node=temp1->next;
        temp1->next=node->next;
        delete node;
        

        return head;
        
        
    }
};
