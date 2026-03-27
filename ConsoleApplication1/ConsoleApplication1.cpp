#include <iostream>
#include <windows.h>
#include "Task.h"
#include "ToDoList.h"



void workWithTDL(ToDoList& TDL) {
    std::cout << "=== Работа с задачами ===";
    std::cout << "\n Чтобы добавить задачу введите 1.";
    std::cout << "\n Чтобы изменить статус задачи введите 2.";
    std::cout << "\n Чтобы удалить задачу введите 3.";
    std::cout << "\n Вывести все задачи, введите 4.";
    std::cout << "\n Для выхода введите 0.";
    std::cout << "\n Ваш выбор: ";
    while (true) {
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            std::string task;
            std::cout << "\n=== Добавление задачи ===";
            std::cout << "\n Введите задачу: ";
            std::getline(std::cin, task);
            TDL.AddTask(new Task(task));
            std::cout << "\n Ваш выбор: ";
        }
        else if (choice == 2) {
            int tIndex;
            std::cout << "\n=== Изменение статуса задачи ===";
            std::cout << "\n Введите номер задачи, подлежащей изменению: ";
            std::cin >> tIndex;
            try{
            TDL.ChangeStatus(tIndex);
            }
            catch (std::exception& e) {
                std::cerr << e.what();
            }
            std::cout << "\n Ваш выбор: ";
        }
        else if (choice == 3) {
            int tdIndex;
            std::cout << "\n=== Удаление задачи ===";
            std::cout << "\n Введите номер задачи для удаления: ";
            std::cin >> tdIndex;
            try {
                TDL.DeleteTask(tdIndex);
            }
            catch (std::exception& e) {
                std::cerr << e.what();
            }
            std::cout << "\n Ваш выбор: ";
        }
        else if (choice == 4) {
            std::cout << "\n=== Вывод текущих задач ===\n";
            TDL.printT();
            std::cout << "\n Ваш выбор: ";
        }
        else if (choice == 0) {
            std::string file = "logs.txt";
            std::cout << "\n=== Выход из программы ===";
            std::cout << "\n Сохранение в файл.";
            TDL.writeIntoTheFile();
            break;
        }
        else {
            std::cout << "\n Некоректный ввод.\n";
        }
    }
}

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    ToDoList tdl;
    try {
        tdl.loadFromFile();
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }

    std::vector<Task*> todolist;
    workWithTDL(tdl);
    return 0;
}

