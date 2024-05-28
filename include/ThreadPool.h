#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "Task.h"
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <semaphore.h>

class ThreadPool {
    std::vector<std::thread> workers;
    std::mutex queue_mutex;
    std::queue<Task*> tasks;
    std::binary_semaphore sem{0};

public:
    ThreadPool(size_t num_threads);
    void addTask(Task* task);
    ~ThreadPool();
};

#endif // THREADPOOL_H
