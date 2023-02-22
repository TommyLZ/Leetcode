#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        int carry = 0;
        
        while(l1 || l2 || carry){
            int n1 = l1? l1->val : 0;
            int n2 = l2? l2->val : 0;

            ListNode* node = new ListNode((n1 + n2 + carry) % 10);  // 结果直接创点计算
            cur->next = node;
            cur = cur->next;

            l1 = l1? l1->next : nullptr;            // 判空赋值
            l2 = l2? l2->next : nullptr;

            carry = (n1 + n2 + carry) / 10;   // 计算进位
        }

        return head->next;
    }
};

int main(){
    Solution solution;
    int a = 9999999, b = 9999;
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode* mov1 = l1;
    ListNode* mov2 = l2;
    ListNode* ans;

    while (a){
        int remain = a % 10;
        a /= 10;
        mov1->val = remain;
        if (!(mov1->next) && a!=0){
            mov1->next = new ListNode();
            mov1 = mov1->next;
        }
    }

    while (b){
        int remain = b % 10;
        b /= 10;
        mov2->val = remain;
        if (!(mov2->next) && b!=0){
            mov2->next = new ListNode();
            mov2 = mov2->next;
        }
    }

    ans = solution.addTwoNumbers(l1, l2);

    cout << "ans: [";

    while (ans){
        cout << ans->val;
        ans = ans -> next;
        if(ans){
            cout << ",";
        }
    }

    cout << "]" << endl;
    return 0;
}