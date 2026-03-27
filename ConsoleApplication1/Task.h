#pragma once
#include <string>

class Task {
protected:
    std::string task;
    bool isCompleted;
public:
    Task();
    Task(const std::string& s);
    Task(const std::string& s, bool tof);

    std::string getTask()const { return task; };
    bool getStatus()const { return isCompleted; };

    void setStatus(bool newStatus);

    void changeStatus();

    ~Task() = default;
};