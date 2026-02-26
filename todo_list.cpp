
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Task {
    std::string description;
    int priority; // 1 (Highest) to 5 (Lowest)
    bool completed;
    
    Task(std::string desc, int prio) 
        : description(desc), priority(prio), completed(false) {}
    
    void display() {
        std::cout << "[" << (completed ? "✓" : " ") << "] ";
        std::cout << "P" << priority << ": " << description << "\n";
    }
};

class TodoList {
private:
    std::vector<Task> tasks;
    
public:
    void addTask(std::string desc, int priority) {
        tasks.push_back(Task(desc, priority));
        std::cout << "Task added: " << desc << "\n";
    }
    
    void completeTask(int index) {
        if(index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task completed: " << tasks[index].description << "\n";
        }
    }
    
    void removeTask(int index) {
        if(index >= 0 && index < tasks.size()) {
            std::cout << "Removed: " << tasks[index].description << "\n";
            tasks.erase(tasks.begin() + index);
        }
    }
    
    void showAll() {
        std::cout << "\n=== All Tasks ===\n";
        for(size_t i = 0; i < tasks.size(); i++) {
            std::cout << i+1 << ". ";
            tasks[i].display();
        }
    }
    
    void showByPriority() {
        std::vector<Task> sorted = tasks;
        std::sort(sorted.begin(), sorted.end(), 
            [](const Task& a, const Task& b) {
                return a.priority < b.priority;
            });
        
        std::cout << "\n=== Tasks by Priority ===\n";
        for(auto& task : sorted) {
            task.display();
        }
    }
    
    void showStats() {
        int total = tasks.size();
        int completed = 0;
        for(auto& task : tasks) if(task.completed) completed++;
        
        std::cout << "\n=== Statistics ===\n";
        std::cout << "Total tasks: " << total << "\n";
        std::cout << "Completed: " << completed << "\n";
        std::cout << "Pending: " << total - completed << "\n";
        std::cout << "Progress: " << (total > 0 ? (completed * 100 / total) : 0) << "%\n";
    }
};

int main() {
    TodoList todo;
    todo.addTask("Finish project report", 1);
    todo.addTask("Buy groceries", 3);
    todo.addTask("Call mom", 2);
    todo.showAll();
    todo.completeTask(0);
    todo.showByPriority();
    todo.showStats();
    return 0;
}

// # To-Do List with Priority

// ## Overview
// A feature-rich task management system with priority levels and progress tracking.

// ## Features
// - Add tasks with priority (1-5)
// - Mark tasks as complete
// - Remove tasks
// - View by priority order
// - Progress statistics
// - Visual task status (✓)

// ## Priority Levels
// - P1: Highest priority
// - P2: High priority
// - P3: Medium priority
// - P4: Low priority
// - P5: Lowest priority

// ## Build & Run
// ```bash
// g++ todo_list.cpp -o todo
// ./todo