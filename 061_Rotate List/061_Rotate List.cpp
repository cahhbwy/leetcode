#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

ostream &operator<<(ostream &out, ListNode *head) {
    ListNode *p = head;
    while (p) {
        out << p->val << " -> ";
        p = p->next;
    }
    out << "NULL";
    return out;
}

void destory(ListNode **head) {
    ListNode *p = *head;
    while (p->next) {
        p = p->next;
        delete *head;
        *head = p;
    }
    *head = nullptr;
}

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        int length = 0;
        ListNode *p = head, *tail = head;
        while (p) {
            ++length;
            tail = p;
            p = p->next;
        }
        tail->next = head;
        k = (length - k % length) % length;
        while (k-- > 0) {
            tail = tail->next;
        }
        ListNode *result = tail->next;
        tail->next = nullptr;
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    ListNode *head, *x;
    x = new ListNode(5);
    x = new ListNode(4, x);
    x = new ListNode(3, x);
    x = new ListNode(2, x);
    head = new ListNode(1, x);
    cout << solution.rotateRight(head, 5) << endl;
    destory(&head);
    x = new ListNode(3);
    x = new ListNode(2, x);
    head = new ListNode(1, x);
    cout << solution.rotateRight(head, 3) << endl;
    destory(&head);
    x = new ListNode(2);
    head = new ListNode(1, x);
    cout << solution.rotateRight(head, 2) << endl;
    destory(&head);
    head = new ListNode(1);
    cout << solution.rotateRight(head, 3) << endl;
    destory(&head);
    head = nullptr;
    cout << solution.rotateRight(head, 0) << endl;
    destory(&head);
    return 0;
}
