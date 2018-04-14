class Solution {
public:
    struct cmp
    {
        bool operator() (const ListNode* a,const ListNode* b){
            return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int len =lists.size();
        if(len<=0)
            return NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp> queue;
        for(int i=0;i<len;i++)
        {
            if(lists[i]!=NULL)
                queue.push(lists[i]);
        }
        ListNode* head=NULL,*pre=NULL,*tmp=NULL;
        while(!queue.empty())
        {
            tmp=queue.top();
            queue.pop();
            if(pre==NULL)
            {
                pre=tmp;
                head=tmp;
            }else
            {
                pre->next=tmp;
            }
            pre=tmp;
            if(tmp->next)
                queue.push(tmp->next);
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if(len<=0)
            return nullptr;
        while(len>1)
        {
            int k=(len+1)/2;
            for(int i=0;i<len/2;i++)
            {
                lists[i]=mergeTwoList(lists[i],lists[k+i]);
            }
            len=k;
        }
        return lists[0];
        
        
    } 
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {  
        if(l1 == NULL) return l2;  
        if(l2 == NULL) return l1;  
        //ListNode* dummy = new ListNode(-1);
        ListNode dummy(-1);
        ListNode *p = &dummy;  
        while(l1 != NULL && l2 != NULL) {  
            if(l1->val > l2->val) {  
                p->next = l2;  
                l2 = l2->next;  
            }else {  
                p->next = l1;  
                l1 = l1->next;  
            }  
            p = p->next;  
        }  
        if(l1 == NULL) {  
            p->next = l2;  
        }else if(l2 == NULL) {  
            p->next = l1;  
        }  
        return dummy.next;  
    }    
};
