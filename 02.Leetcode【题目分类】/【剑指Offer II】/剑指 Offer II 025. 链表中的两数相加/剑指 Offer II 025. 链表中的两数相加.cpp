#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        int carry = 0;
        ListNode* ans = nullptr;

        while (!s1.empty() or !s2.empty() or carry != 0) {

            int a = s1.empty() ? 0 : s1.top();

            int b = s2.empty() ? 0 : s2.top();

            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();

            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;

            auto curnode = new ListNode(cur);
            curnode -> next = ans;  // 采用头插法
            ans = curnode;
        }

        return ans;
    }
};

void print(ListNode * head) {
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }

    cout << endl;
}


int main() {
    ListNode* headA = new ListNode (7);
    ListNode* node2 = new ListNode (2);
    ListNode* node3 = new ListNode (4);
    ListNode* node4 = new ListNode (3);

    ListNode* headB = new ListNode (5);
    ListNode* nodeB2 = new ListNode (6);
    ListNode* nodeB3 = new ListNode (4);


    headA -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;

    headB -> next = nodeB2;
    nodeB2 -> next = nodeB3;

    Solution solution;

    ListNode * res;

    res = solution.addTwoNumbers(headA, headB);

    print(res);
    return 0;
}

// 时间复杂度： O(max(m,n))
// 空间复杂度：O(m+n)
