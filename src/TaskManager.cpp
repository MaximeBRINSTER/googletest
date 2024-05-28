#include "TaskManager.h"
#include <queue>
#include <thread>
#include <iostream>

using namespace std;

// Initialisation des variables statiques
TaskManager* TaskManager::instance = nullptr;
mutex TaskManager::mtx;

TaskManager* TaskManager::getInstance() {
    lock_guard<mutex> lock(mtx);
    if (instance == nullptr){
        instance = new TaskManager();
    }
    return instance;
}

void TaskManager::addTask(Task* task){
    // Ajouter la tâche à une file d'attente
}

void TaskManager::executeTasks(){
    // Exécuter les tâches
}