class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       /* if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* p=NULL;
        //l1->val<l2->val?p=l1,l1=l1->next:p=l2,l2=l2->next;
        if(l1->val<=l2->val)
        {
            p=l1;
            l1=l1->next;
        }else
        {
            p=l2;
            l2=l2->next;
        }
        
        ListNode* q=p;
        
        while(l1!=NULL&& l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }else
            {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if(l1!=NULL)
            p->next=l1;
        if(l2!=NULL)
            p->next=l2;
        return q;*/
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val<l2->val)
        {
           
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
            
        
    }
};
