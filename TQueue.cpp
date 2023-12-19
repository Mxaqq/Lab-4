#include "TQueue.h"

TQueue::TQueue() {
    pHead = nullptr;
    pTail = nullptr;
}

TQueue::~TQueue() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

bool TQueue::IsEmpty() const {
    return pHead == nullptr;
}

void TQueue::Enqueue(int value) {
    TNode* pNode = new TNode(value);
    if (IsEmpty()) {
        pHead = pNode;
        pTail = pNode;
    }
    else {
        pTail->pNext = pNode;
        pTail = pNode;
    }
}

int TQueue::Front() const {
    if (!IsEmpty()) {
        return pHead->data;
    }
    return 0;
}

void TQueue::Dequeue() {
    if (!IsEmpty()) {
        TNode* pNode = pHead;
        pHead = pHead->pNext;
        if (pHead == nullptr) {
            pTail = nullptr;
        }
        delete pNode;
    }
}