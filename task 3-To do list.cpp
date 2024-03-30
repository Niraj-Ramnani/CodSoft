#include <iostream>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};


void displayMenu();
void addTask(Task* tasks[], int& taskCount, const string& description);
void viewTasks(Task* tasks[], int taskCount);
void markTaskCompleted(Task* tasks[], int taskCount, int index);
void removeTask(Task* tasks[], int& taskCount, int index);

int main() {
    const int MAX_TASKS = 100;
    Task* tasks[MAX_TASKS];
    int taskCount = 0;

    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    string description;
                    cout << "Enter task description: ";
                    cin.ignore(); 
                    getline(cin, description);
                    addTask(tasks, taskCount, description);
                    break;
                }
            case '2':
                viewTasks(tasks, taskCount);
                break;
            case '3':
                {
                    int index;
                    cout << "Enter the index of the task to mark as completed: ";
                    cin >> index;
                    markTaskCompleted(tasks, taskCount, index);
                    break;
                }
            case '4':
                {
                    int index;
                    cout << "Enter the index of the task to remove: ";
                    cin >> index;
                    removeTask(tasks, taskCount, index);
                    break;
                }
            case '5':
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '5');


    for (int i = 0; i < taskCount; ++i) {
        delete tasks[i];
    }

    return 0;
}

void displayMenu() {
    cout << "\n==== To-Do List Manager ====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(Task* tasks[], int& taskCount, const string& description) {
    Task* newTask = new Task;
    newTask->description = description;
    newTask->completed = false;
    tasks[taskCount++] = newTask;
    cout << "Task added successfully!" << endl;
}

void viewTasks(Task* tasks[], int taskCount) {
    cout << "\n==== Task List ====" << endl;
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". ";
        if (tasks[i]->completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i]->description << endl;
    }
}

void markTaskCompleted(Task* tasks[], int taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        tasks[index - 1]->completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please try again." << endl;
    }
}

void removeTask(Task* tasks[], int& taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        delete tasks[index - 1];
        for (int i = index; i < taskCount; ++i) {
            tasks[i - 1] = tasks[i];
        }
        taskCount--;
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please try again." << endl;
    }
}
