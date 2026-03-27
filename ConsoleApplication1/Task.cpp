#include "Task.h"

Task::Task()
	: task("Empty"), isCompleted(0) { }

Task::Task(const std::string& s)
	: task(s), isCompleted(0) { }


Task::Task(const std::string& s, bool tof)
	: task(s), isCompleted(tof) { }

void Task::setStatus(bool newStatus)
{
	isCompleted = newStatus;
}

void Task::changeStatus()
{
	isCompleted = !isCompleted;
}

