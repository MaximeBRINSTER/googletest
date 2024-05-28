#include "taskmanager.h"
#include "printtask.h"
#include "threadpool.h"

using namespace std;

int main() {
    TaskManager* manager = TaskManager::getInstance();

    ThreadPool pool(4);

    manager->addTask(new PrintTask("Hello World!"));
    manager->addTask(new PrintTask("Task 2"));
    manager->addTask(new PrintTask("Task 3"));

    pool.addTask(new PrintTask("Hello from the thread pool"));
    pool.addTask(new PrintTask("Another task in the thread pool"));

    manager->executeTasks();

    return 0;
}