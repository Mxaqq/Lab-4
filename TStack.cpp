#include "TStack.h"

TStack::TStack() {
    pHead = nullptr;
}

TStack::~TStack() {
    while (!IsEmpty()) {
        Pop();
    }
}

bool TStack::IsEmpty() const {
    return pHead == nullptr;
}

void TStack::Push(int value) {
    TNode* pNode = new TNode(value);
    pNode->pNext = pHead;
    pHead = pNode;
}

int TStack::Top() const {
    if (!IsEmpty()) {
        return pHead->data;
    }
    return 0;
}

void TStack::Pop() {
    if (!IsEmpty()) {
        TNode* pNode = pHead;
        pHead = pHead->pNext;
        delete pNode;
    }
}