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
    int get_length(ListNode* node)
    {
        int count=0;
        while(node!=NULL)
        {
            ++count;
            node=node->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
            return NULL;
        /*while(headA!=NULL)
        {
            while(headB!=NULL)
            {
                if(headA->val==headB->val)
                    return headB;
                headB=headB->next;
            }
            headA=headA->next;
        }
        return NULL;
       ListNode* a=headA,*b=headB;
        while(a!=b)
        {
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        return a;*/
        
        
       /*istNode* a=headA,*b=headB;
        while(a!=NULL||b!=NULL)
        {
            if(a==b)
                return a;
            else
            {
                a=a?a->next:headB;
                b=b?b->next:headA;
            }
        }
        return a;*/
        int lengthA=get_length(headA);
        int lengthB=get_length(headB);
        if(lengthA>lengthB)
        {
            while(lengthA-lengthB>0)
            {
                headA=headA->next;
                lengthA--;
            }
        }else
        {   while(lengthB-lengthA)
            {
                headB=headB->next;
                lengthB--;
            }
        }
        while(headA!=NULL&&headB!=NULL)
        {
            if(headA==headB)
                return headA;
            else
            {
                headA=headA->next;
                headB=headB->next;
            }
        }
        return NULL;
    }
};
