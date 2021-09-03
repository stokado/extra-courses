#include <map>
#include <string>
#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

// return next TaskStatus in enum class  
TaskStatus Next(TaskStatus cur){
    return static_cast<TaskStatus>(static_cast<int>(cur) + 1);
}

// Delete Tasks with 0 count
void RemoveZeroes(TasksInfo& tasks_info){
    // Prepare vector of TaskStatus
    vector<TaskStatus> to_remove;
    for (const auto& item : tasks_info){
        // If there are 0 tasks of current TaskStatus, add it to remove
        if (item.second == 0){
            to_remove.push_back(item.first);
        }
    }
    // Iterate over specified TaskStatus and remove it from class
    for (const TaskStatus& status : to_remove){
        tasks_info.erase(status);
    }
}

class TeamTasks {
    public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return person_for_tasks.at(person);
    };

    // Add new task
    void AddNewTask(const string& person){
        person_for_tasks[person][TaskStatus::NEW]++;
    };
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        // Prepare to return tuple of Updated tasks (with done) and Unchanged tasks (without done)
        TasksInfo untouched, updated;
        // Use reference for objects data
        TasksInfo& tasks = person_for_tasks[person];
        // Use for loop with enum like this
        // Prepare map of updated tasks 
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            // Add either task_count if we send command to do less count of tasks than current TaskStatus
            // or add all of current TaskStatus for updated status if task_cout is more than tasks with current tasks 
            updated[Next(status)] = min(task_count, tasks[status]);
            // Subtract number of tasks with updated status from task_count (number of tasks to edit)  
            task_count -= updated[Next(status)];
        }
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            // Prepare map of untouched tasks
            untouched[status] = tasks[status] - updated[Next(status)];
            // Update current tasks
            tasks[status] += updated[status] - updated[Next(status)]; 
        }
        // In previous loop we didnt add New Done tasks to list of tasks
        tasks[TaskStatus::DONE] += updated[TaskStatus::DONE];
        // Delete zeroes from tasks
        RemoveZeroes(updated);
        RemoveZeroes(untouched);
        RemoveZeroes(person_for_tasks.at(person));
        return {updated, untouched};
    };
    private:
    map<string, TasksInfo> person_for_tasks;
};

