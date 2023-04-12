//
// Created by jojo on 2/20/23.
//

#include <iostream>
#include <vector>

using namespace std;
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val):val(val), next(nullptr) {};
    };

    MyLinkedList() {
        len = 0;
        head = new LinkedNode(0);
    }

    int get(int index) {
        if (index >= len) return -1;
        LinkedNode *node = head->next;
        for (int i = 0;i < index; ++i) {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val) {
        if (index > len) return;
        LinkedNode *node = head->next;
        LinkedNode *pre_node = head;
        for (int i = 0;i < index; ++i) {
            pre_node = pre_node->next;
            node = node->next;
        }
        LinkedNode *new_node = new LinkedNode(val);
        pre_node->next = new_node;
        new_node->next = node;
        ++len;
        return;
    }
    void printLinkedList() {
        LinkedNode* cur = head;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void deleteAtIndex(int index) {
        if (index >= len) return;
        LinkedNode *node = head->next;
        LinkedNode *pre_node = head;
        for (int i = 0;i < index; ++i) {
            pre_node = pre_node->next;
            node = node->next;
        }
        pre_node->next = node->next;
        delete node;
        --len;
        return;
    }
private:
    int len;
    LinkedNode *head;
};
int main()
{
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(2);
    linkedList->deleteAtIndex(1);

    linkedList->addAtHead(2);
    linkedList->addAtHead(7);
    linkedList->addAtHead(3);
    linkedList->addAtHead(2);
    linkedList->addAtHead(5);
    linkedList->addAtTail(5);
    linkedList->printLinkedList();
    cout << linkedList->get(5) << endl;
    linkedList->deleteAtIndex(6);
    linkedList->deleteAtIndex(4);
    linkedList->printLinkedList();

    //返回3        //返回3
    return 0;
}