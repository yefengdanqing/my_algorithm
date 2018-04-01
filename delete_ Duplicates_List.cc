//由于直接从链表中摘除，需要考虑内存泄漏
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* p=NULL;
        ListNode* q=head;
        p=head;
        //head=head->next;
        while(head!=NULL)
        {
            /*head=head->next;
            if(head==NULL)
                break;
            if(p->val==head->val)
            {
                head* tmp=head;
                p->next=head->next;
                if(head->next==NULL)
                    break;
                delete tmp;
            }else
            {
                p=head;
                if(head->next==NULL)
                    break;
            }*/
            head=head->next;
            if(head==NULL||p->val!=head->val)
            {
                p->next=head;
                p=p->next;  
            }
        }
        return q;
    }
};
