#ifndef PRINTTASK_H
#define PRINTTASK_H

#include "Task.h"
#include <string>
#include <iostream>
using namespace std;

class PrintTask : public Task {
        string message;
    public:
        PrintTask(const string& msg);
        void execute() override;
};

#endif