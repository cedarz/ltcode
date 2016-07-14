#include <stack>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        stack<ListNode *> stk;
        ListNode * p = head;
        //head = NULL;
        ListNode * res = NULL;
        ListNode * __p = p;
        int cnt = 0;
        while(p != NULL) {
            __p = p;
           for(int i = 0; i < k; ++i) {
              if(p) {
                 stk.push(p);
                 p = p->next;
              } else break;
           }
           if(stk.size() == k) {
               for(int i = 0; i < k; ++i) {
                   if(!res) {
                       res = stk.top();
                       head = res;
                   } else {
                       res->next = stk.top();
                       res = res->next;
                   }
                   stk.pop();
               }
               //Ñ­»·£¬ÀáÄ¿
               res->next = NULL;
           } else {
               if(!res) {
                    res = __p;
                    head = res;
               } else {
                   res->next = __p;
               }
               break;
           }
        } 
        //cout << "cnt = " << cnt << endl;
        return head;
    }
};

