#include <iostream>
#include "TJobStream.h"
#include "TQueue.h"
#include "TStack.h"
#include "TProc.h"

int main() {
    setlocale(LC_ALL, "Russian");
    TJobStream jobStream(0.5);
    TQueue queue;
    TStack stack;
    TProc processor;

    for (int i = 1; i <= 10; i++) {
        int newJob = jobStream.GetNewJob();
        if (newJob != 0) {
            queue.Enqueue(newJob);
            std::cout << "Работа " << newJob << " добавленна в очередь." << std::endl;
        }

        if (!queue.IsEmpty() && !processor.IsActive()) {
            int jobInProcess = queue.Front();
            queue.Dequeue();
            processor.SetActiveJob(jobInProcess);
            std::cout << "Работа " << jobInProcess << " перемещена из очереди в процессор." << std::endl;
        }

        processor.ProcessJob();

        std::cout << std::endl;
    }

    return 0;
}