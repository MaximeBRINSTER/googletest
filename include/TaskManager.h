#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <mutex>
using namespace std;

class TaskManager {
    private:
        static TaskManager* instance; 
        static mutex mtx;
        TaskManager() {}
    public: 
        static TaskManager* getInstance();
        void addTask(Task* task);
        void executeTasks();
}

#endif