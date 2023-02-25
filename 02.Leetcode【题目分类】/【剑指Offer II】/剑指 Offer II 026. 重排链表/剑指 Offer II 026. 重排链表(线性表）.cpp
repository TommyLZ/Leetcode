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
//            emplace_back () �� push_abck () �������ǣ�
//            push_back () ���� vector β�����һ��Ԫ��ʱ�����Ȼᴴ��һ����ʱ����
//            Ȼ���ٽ������ʱ�����ƶ��򿽱��� vector �У�����ǿ����Ļ����º���Զ�������ǰ�����������ʱԪ�أ���
//            �� emplace_back () ��ʵ��ʱ������ֱ���� vector β���������Ԫ�أ�ʡȥ���ƶ����߿���Ԫ�صĹ��̡�
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
// ʱ�临�Ӷȣ� O(N)
// �ռ临�Ӷȣ�O(N)
