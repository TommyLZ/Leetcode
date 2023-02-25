#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;

        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
            if (vals[i] != vals[j]) {
                return false;
            }
        }
        return true;
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
    ListNode* headA = new ListNode (1);
    ListNode* node2 = new ListNode (2);
    ListNode* node3 = new ListNode (3);
    ListNode* node4 = new ListNode (3);
    ListNode* node5 = new ListNode (2);
    ListNode* node6 = new ListNode (1);

    Solution solution;

    bool res = solution.isPalindrome(headA);

    cout << "the result is " << res << endl;

    return 0;
}
// 时间复杂度： O(N)
// 空间复杂度：O(N)
