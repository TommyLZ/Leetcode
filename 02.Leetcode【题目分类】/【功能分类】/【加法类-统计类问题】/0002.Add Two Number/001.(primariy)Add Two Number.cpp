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
        ListNode* head = nullptr;   // 头指针
        ListNode* tail = nullptr;   // 尾指针（负责加法移动）

        int carry = 0;

        while (l1 || l2){   // 加法放到整个循环当中进行
            int n1 = l1? l1->val : 0;   // 三目运算符：先判断列表是否为空，然后根据情况进行赋值
            int n2 = l2? l2->val : 0;
            int sum = n1 + n2 + carry;  // 先计算好求和结果

            if (!head){ // 结果链表为空链表
                head = tail = new ListNode(sum % 10);
            }
            else{
                tail->next = new ListNode(sum % 10);    // 创建新结点
                tail = tail->next; 
            }
            
            carry = sum / 10;   // 进位计算

            if (l1){    // 指针后移
                l1 = l1->next;
            }

            if (l2){    // 指针后移
                l2 = l2->next;
            }
        }

        if (carry > 0){
            tail->next = new ListNode(carry);   // 为最后的进位创建一个新的结点
        }

        return head;    // 返回结果链表
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