/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* helper(ListNode* lp,ListNode* rp)
    {
        if(rp==NULL)
            return lp;
        ListNode* tmp=rp->next;
        rp->next=lp;
        lp=rp;
        rp=tmp;
        return helper(lp,rp);
    }
    ListNode* reverseList(ListNode* head) {
        /*if(head==NULL)
            return NULL;

        if(head->next==NULL)
            return head;
        
        ListNode* q=head->next;
        head->next=NULL;
        
        ListNode* tmp=NULL;
        
        while(q!=NULL)
        {
            tmp=q;
            q=q->next;
            tmp->next=head;
            head=tmp;
        }
        return head;*/
       /* if(head==NULL)
            return NULL;
        
        ListNode* p=head->next;
        head->next=NULL;
        ListNode* tmp=NULL;
        
        while(p)
        {
            tmp=p->next;
            p->next=head;
            head=p;
            p=tmp;
        }
        return head;*/
        //return helper(head,p);
        if(head==NULL||head->next==NULL) return head;
        ListNode* new_node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_node;       
    }
};
