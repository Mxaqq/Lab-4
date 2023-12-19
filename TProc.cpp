#include "TProc.h"
#include <iostream>
TProc::TProc() {
    ActiveJob = 0;
}

bool TProc::IsActive() const {
    return ActiveJob != 0;
}

void TProc::SetActiveJob(int job) {
    ActiveJob = job;
}

void TProc::ProcessJob() {
    if (IsActive()) {

        std::cout << "Работа " << ActiveJob << " обрабатывается процессором." << std::endl;
        ActiveJob = 0;
    }
}