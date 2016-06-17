/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    typedef ListNode *Lp;
    typedef ListNode Ln;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Lp cur = NULL;
        Lp ret = NULL;
        if(!l1 && !l2) {
            return ret;
        }
        print(l1);print(l2);
        for(Lp b = l1, e = l2; b || e; ) {
            if(!cur) {
                cur = new Ln(0);
                ret = cur;
            } else {
                cur->next = new Ln(0);
                cur = cur->next; 
            }
            if(b) {
                cur->val += b->val;
                b = b->next;
            }
            if(e) {
                cur->val += e->val;
                e = e->next;
            }
        }
        
        for(Lp b = ret; b; b = b->next) {
            if(b->val >= 10) {
                if(b->next == NULL) b->next = new Ln(0);
                b->next->val += b->val / 10;
                b->val %= 10;
            }
        } 
        print(ret);
        return ret;
    }
    Lp getList(istream &is) {
        Lp ret = NULL, cp = ret;
        int val;
        int cnt; 
        is>>cnt; 
        while(cnt-- && is>>val) {
            if(!ret) {
                ret = new Ln(val);
                cp = ret;
            } else {
                cp -> next = new Ln(val);
                cp = cp->next;
            }
        }
        return ret;
    }
    void print(Lp lp) {
        for(Lp b = lp; b; b = b->next) {
            if(b == lp) {
                cout<<b->val;
            } else {
                cout<<"->"<<b->val;
            }
        }
        cout<<endl;
    }
};


int main() {
    Solution s;
    Solution::Lp l1 = s.getList(cin), l2 = s.getList(cin);
    Solution::Lp res = s.addTwoNumbers(l1, l2);
    s.print(res);
    return 0;
}
    
    
        
