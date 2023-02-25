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
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }

        vector<ListNode *> vec;

        ListNode *node = head;

        while (node != nullptr) {
            vec.emplace_back(node);
//            emplace_back () 和 push_abck () 的区别是：
//            push_back () 在向 vector 尾部添加一个元素时，首先会创建一个临时对象，
//            然后再将这个临时对象移动或拷贝到 vector 中（如果是拷贝的话，事后会自动销毁先前创建的这个临时元素）；
//            而 emplace_back () 在实现时，则是直接在 vector 尾部创建这个元素，省去了移动或者拷贝元素的过程。
            node = node->next;
        }

        int i = 0, j = vec.size() - 1;

        while (i < j) {

            vec[i]->next = vec[j];
            i++;

            if (i == j) {
                break;
            }

            vec[j]->next = vec[i];
            j--;
        }

        vec[i]->next = nullptr;
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
    ListNode* node4 = new ListNode (4);

    Solution solution;

    solution.reorderList(headA);

    return 0;
}
// 时间复杂度： O(N)
// 空间复杂度：O(N)
