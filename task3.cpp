#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Task {
    string title;
    bool done;
};

vector<Task> tasks;

void addTask() {
    cout << "Enter task: ";
    string title;
    getline(cin, title);
    if (title.empty()) {
        cout << "Task cannot be empty.\n";
        return;
    }
    tasks.push_back({title, false});
    cout << "Task added.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet.\n";
        return;
    }
    cout << "\n--- Your Tasks ---\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title
             << " [" << (tasks[i].done ? "Completed" : "Pending") << "]\n";
    }
}

int getIndex(const string& action) {
    viewTasks();
    if (tasks.empty()) return -1;
    int n;
    cout << "Task number to " << action << ": ";
    if (cin >> n && n >= 1 && n <= (int)tasks.size()) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return n - 1;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid task number.\n";
    return -1;
}

void markCompleted() {
    int i = getIndex("mark completed");
    if (i != -1) {
        tasks[i].done = true;
        cout << "Marked as completed.\n";
    }
}

void removeTask() {
    int i = getIndex("remove");
    if (i != -1) {
        cout << "Removed: " << tasks[i].title << "\n";
        tasks.erase(tasks.begin() + i);
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== To-Do List ===\n"
             << "1. Add task\n2. View tasks\n3. Mark task completed\n"
             << "4. Remove task\n5. Exit\nChoose (1-5): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
