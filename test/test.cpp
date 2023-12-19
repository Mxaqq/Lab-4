#include "TQueue.cpp"
#include <gtest.h>

TEST(TQueue, New_queue_is_empty) {
    TQueue q;
    EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, Queue_is_not_empty_after_enqueue) {
    TQueue q;
    q.Enqueue(5);
    EXPECT_FALSE(q.IsEmpty());
}

TEST(TQueue, Enqueue_and_dequeue_one_element) {
    TQueue q;
    q.Enqueue(10);
    EXPECT_EQ(10, q.Front());
    q.Dequeue();
    EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, Dequeue_from_empty_queue_does_not_crash) {
    TQueue q;
    q.Dequeue(); 
}

TEST(TQueue, Front_returns_correct_element) {
    TQueue q;
    q.Enqueue(3);
    q.Enqueue(7);
    EXPECT_EQ(3, q.Front());
}

TEST(TQueue, Empty_queue_front_returns_zero) {
    TQueue q;
    EXPECT_EQ(0, q.Front());
}

