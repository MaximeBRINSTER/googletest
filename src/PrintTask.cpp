#include "PrintTask.h"
using namespace std;

PrintTask::PrintTask(const string& msg) : message(msg) {}

void PrintTask::execute() {
    cout << message << endl; 
}