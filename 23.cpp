#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static ListNode MAX(INT_MAX);
static ListNode MIN(INT_MIN);

int ls[100000];

void adjust(vector<ListNode *> & lists, int k, int x) {
    int t = (k + x) / 2;
    int s = x;
    //cout << "x = " << x << endl;
    while(t > 0) {
        if(lists[s]->val > lists[ls[t]]->val) {
            int tmp = s;
            s = ls[t];
            ls[t] = tmp;
        }
        t /= 2;
    }
    ls[0] = s;
    //cout <<lists[x]->val << " " <<  ls[0] << endl;
}

void create(vector<ListNode *> & lists, int k) {
    for(int i = 0; i < k; ++i) {
        ls[i] = k;
    }
    for(int i = 0; i < k; ++i) {
        adjust(lists, k, i);
    }
}
    
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        if(lists.empty()) return head;
        ListNode * tail = NULL;
        int len = lists.size();
        //cout << len << endl;
        for(int i = 0; i < len; ++i) {
            if(!lists[i]) {
                lists[i] = &MAX;
            }
        }

        lists.push_back(&MIN);
        create(lists, len);
        
        while(lists[ls[0]]->val != INT_MAX) {
            if(head) {
                tail->next = lists[ls[0]];
                tail = tail->next;
            } else {
                head = lists[ls[0]];
                tail = head;
            }
            lists[ls[0]] = lists[ls[0]]->next;
            if(!lists[ls[0]]) {
                lists[ls[0]] = &MAX;
            }
            adjust(lists, len, ls[0]);
        }
       
        return head;
                
    }
};
;

int main() {
    return 0;
}
    


    
    

