#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast != nullptr) {

            slow = slow->next;

            if (fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next; // 任意时刻，fast走过的距离是slow的2倍

            if (fast == slow) { // 两个指针相遇
                ListNode *ptr = head;

                // 数学规律：ptr和slow在入环点相遇（等量关系）
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};

int main(){
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head -> next = node2;
    node2 -> next = node3;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node2;

    Solution solution;

    int n = 2;

    ListNode* res = solution.detectCycle(head);

    cout << "the result is " << res -> val << endl;

    return 0;
}

// 时间复杂度：O(N)
// 空间复杂度：O(1)
