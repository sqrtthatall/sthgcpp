#include "ToDoList.h"

const std::string FileName = "logs.txt";
int ToDoList::nextId = 1;

ToDoList::ToDoList() 
    : id(nextId++) { }

ToDoList::ToDoList(const std::vector<Task*>& v)
	: List(v), id(nextId++) { }

ToDoList::ToDoList(const ToDoList& other)
	: ToDoList(other.List) { }

ToDoList::~ToDoList()
{
    for (Task* task : List) {
        delete task;
    }
}

void ToDoList::AddTask(Task* t)
{
    List.push_back(t);
    std::cout << "Task " << List.size() << " added.";
}

void ToDoList::ChangeStatus(int index)
{
    if (List.empty() || index < 1 || index > List.size()) throw std::out_of_range("Error: Out of range at list.");
    List[index - 1]->changeStatus();
}

void ToDoList::DeleteTask(int index)
{
    if (List.empty() || index < 1 || index > List.size()) throw std::out_of_range("Error: Out of range at list.");
    delete List[index - 1];
    List.erase(List.begin() + index - 1);
    std::cout << "Task " << index << " deleted.";
}

void ToDoList::writeIntoTheFile()const
{
    std::ofstream fout(FileName);
    if (!fout.is_open()) throw std::runtime_error("Error: could not open the file " + FileName);
    for (Task* t : List) {
        fout << "Task: " << t->getTask().c_str() << " - Status: " << t->getStatus() << std::endl;
    }
    fout.close();
}

void ToDoList::loadFromFile()
{
    
    std::ifstream fin(FileName);
    if (!fin.is_open()) std::runtime_error("Error: could not open the file"); 
        
    std::string line;

    while (std::getline(fin, line)) {
        if (line.empty()) continue;

        size_t taskStart = line.find("Task: ") + 6;
        size_t statusPos = line.find(" - Status: ");

        if (taskStart == std::string::npos || statusPos == std::string::npos) {
            continue;
        }

        std::string taskText = line.substr(taskStart, statusPos - taskStart);
        int status = std::stoi(line.substr(statusPos + 11));

        List.push_back(new Task(taskText, (status == 1)));
    }

    fin.close();
    std::cout << "Loaded from file: " << List.size() << "\n";
}

void ToDoList::printT() const
{
    if (List.size() == 0) {
        std::cout << "No task here! Add it!\n";
    }
    int i = 1;
    for (Task* t : List) {
        std::cout << i++ << ") Task: " << t->getTask() << " Status: " << ((t->getStatus() == 0) ? "Not done.\n" : "Done.\n");
    }
}




