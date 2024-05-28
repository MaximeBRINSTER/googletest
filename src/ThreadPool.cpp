#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t num_threads) {
    for (size_t i = 0; i < num_threads; ++i) {
        workers.emplace_back([this] {
            while (true) {
                Task* task;
                {
                    std::unique_lock<std::mutex> lock(queue_mutex);
                    sem.acquire();
                    if (tasks.empty()) {
                        return;
                    }
                    task = tasks.front();
                    tasks.pop();
                }
                task->execute();
                delete task;
            }
        });
    }
}

void ThreadPool::addTask(Task* task) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        tasks.push(task);
    }
    sem.release();
}

ThreadPool::~ThreadPool() {
    for (std::thread &worker : workers) {
        worker.join();
    }
}
