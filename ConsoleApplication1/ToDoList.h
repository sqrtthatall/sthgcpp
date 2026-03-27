#pragma once
#include <vector>
#include "Task.h"
#include <iostream>
#include <fstream>


class ToDoList {
protected:
    std::vector<Task*> List;
    static int nextId;
    const int id;
public:
    ToDoList();
    ToDoList(const std::vector<Task*>& v);
    ToDoList(const ToDoList& other);
    ~ToDoList();

    void AddTask(Task* t);
    void ChangeStatus(int index);
    void DeleteTask(int index);
    int getID()const { return id; }

    void writeIntoTheFile()const;
    void loadFromFile();
    void printT()const;
};