#include <iostream>

using namespace std;

struct Node {
    int n;
    Node* nextNode = nullptr;
};

struct List {
    Node* beginNode = nullptr;
    Node* lastNode = nullptr;
};

void addNodeToTailList(int n, List* list) {
    Node* newNode = new Node;
    newNode->n = n;
    newNode->nextNode = nullptr;

    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        list->beginNode = newNode;
        list->lastNode = newNode;
    }
    // if list has 1 elm 
    else if (list->beginNode->nextNode == nullptr){
        list->lastNode = newNode;
        list->beginNode->nextNode = list->lastNode;
    }
    // if list has > 1 elm 
    else {
        list->lastNode->nextNode = newNode;
        list->lastNode = newNode;
    }
}

void addNodeToHeadList(int n, List* list) {
    Node* newNode = new Node;
    newNode->n = n;

    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        newNode->nextNode = nullptr;
        list->beginNode = newNode;
        list->lastNode = newNode;
    }
    // if list has 1 elm 
    else if (list->beginNode->nextNode == nullptr){
        newNode->nextNode = list->lastNode;
        list->beginNode = newNode;
    }
    // if list has > 1 elm 
    else {
        newNode->nextNode = list->beginNode;
        list->beginNode = newNode;
    }
}

void addValueOfNodeAt(int n, List* list, int index) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return;
    }

    Node* curNode = list->beginNode;

    int i=1;
    while (true) {
        if (i == index) {
            curNode->n += n;
            break;
        }
        i++;
        curNode = curNode->nextNode;
    }
}

List* revertList(List* list) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return list;
    }

    List* resList = new List;
    Node curNode = *(list->beginNode);

    while(true) {
        addNodeToHeadList(curNode.n, resList);

        if (curNode.nextNode == nullptr)
            break;
        curNode = *(curNode.nextNode);
    }
    
    return resList;
}

void printList(List* list) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return;
    }

    Node currenNode = *(list->beginNode);
    while(true) {
        cout << currenNode.n << "\n";

        if (currenNode.nextNode == nullptr)
            break;
        currenNode = *(currenNode.nextNode);
    }
}

void removeTail(List* list) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return;
    }
    // if list has 1 elm 
    else if (list->beginNode->nextNode == nullptr){
        list->lastNode = nullptr;
        list->beginNode = nullptr;
        return;
    }

    Node* curNode = list->beginNode;
    Node* befNode = list->beginNode;

    while(true) {
        if (curNode->nextNode == nullptr) {
            befNode->nextNode = nullptr;
            break;
        }

        befNode = curNode;
        curNode = curNode->nextNode;
    }
}

void removeHead(List* list) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return;
    }
    // if list has 1 elm 
    else if (list->beginNode->nextNode == nullptr){
        list->lastNode = nullptr;
        list->beginNode = nullptr;
        return;
    }

    list->beginNode = list->beginNode->nextNode;
}

void removeNodeAt(List* list, int k) {
    // if list has no elm
    if (list->beginNode == nullptr && list->lastNode == nullptr) {
        return;
    }
    // if list has 1 elm 
    else if (list->beginNode->nextNode == nullptr){
        list->lastNode = nullptr;
        list->beginNode = nullptr;
        return;
    }

    Node* curNode = list->beginNode;
    Node* befNode = list->beginNode;

    int i=1;
    while (curNode->nextNode != nullptr) {
        if (i == k) {
            befNode->nextNode = curNode->nextNode;
            break;
        }

        i++;
        befNode = curNode;
        curNode = curNode->nextNode;
    }
}

int indexOf(List* list, int n) {
    Node* curNode = list->beginNode;

    int res = -1;
    int i=1;
    while (curNode->nextNode != nullptr) {
        if (curNode->n == n)
            res = i;
        
        i++;
        curNode = curNode->nextNode;
    }

    return res;
}

void remove3FirstNode(List* list) {
    for (int i=0; i<3; i++) {
        removeHead(list);
    }
}

void removeValue(int n, List* list) {
    int idx = indexOf(list, n);
    while (idx != -1)
        removeNodeAt(list, indexOf(list, idx));
}

void Ex1(List* list) {
    // 1,2,3,4,5,6,7,3,8,9,3,0,0,2
    addNodeToTailList(1, list);
    addNodeToTailList(2, list);
    addNodeToTailList(3, list);
    addNodeToTailList(4, list);
    addNodeToTailList(5, list);
    addNodeToTailList(6, list);
    addNodeToTailList(7, list);
    addNodeToTailList(3, list);
    addNodeToTailList(8, list);
    addNodeToTailList(9, list);
    addNodeToTailList(3, list);
    addNodeToTailList(0, list);
    addNodeToTailList(0, list);
    addNodeToTailList(2, list);
}


void Ex2(List* list) {
    printList(list);
}

void Ex3(List* list){
    addValueOfNodeAt(4, list, 2);
}

void Ex4(List* list) {
    removeTail(list);
}

void Ex5(List* list) {
    removeNodeAt(list, indexOf(list, 3));
}

void Ex6(List* list) {
    remove3FirstNode(list);
}

void Ex7(List* list) {
    revertList(list);
}

void Ex8(List* list) {
    removeValue(3, list);
}

int main() {
    List* list = new List;
    Ex1(list);
    //Ex2(list);
    //Ex3(list);
    //Ex4(list);
    //Ex5(list);
    //Ex6(list);
    //Ex7(list);
    Ex8(list);

    printList(list);
}