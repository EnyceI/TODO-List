#include <iostream>
#include <vector>
using namespace std;
void menu() {
    cout<<"TO-DO LIST:\n";
    cout<<"1. Add Task\n";
    cout<<"2. List Task\n";
    cout<<"3. Remove Task\n";
    cout<<"4. Exit\n";
    cout<<"=====================\n";
    cout<<"Enter your choice:\n";

}
class Task {
public:
    Task( string ti, string de,string cat,string date,int pp) {
        title=ti;
        description=de;
        category=cat;
        dueDate=date;
        priority=pp;
    }

    void displayTask() const {
        cout<<"Title: "<<title<<"\n"<<"Description: "<<description<<"\n"<<"Category: "<<category<<"\n"<<"Due date: "<<dueDate<<"\n"<<"Priority:"<<priority<<"\n";
    }

private:
    string title,description,category,dueDate;
    int priority;


};
vector<Task>tasks;
void addTask() {
    string ti,description,category,duedate;
    int priority;
    cout<<"TASK DETAILS\n";
    cout<<"=============\n";
    cout<<"Enter Title:";
    cin>>ti;
    cout<<"Enter Description:";
    cin>>description;
    cout<<"Enter Category:";
    cin>>category;
    cout<<"Enter Due Date:";
    cin>>duedate;
    cout<<"Enter priority:";
    cin>>priority;
    cin.ignore();
    tasks.push_back(Task(ti,description,category,duedate,priority));
    cout<<"Added Successfully";

}
int main()
{   //INPUT CHOICE AND VALIDATE
    int choice;
    menu();
    cin>>choice;
    while(choice>4 || choice<1) {
        cout<<"Invalid choice!\n";
        cout<<"Enter your choice again:\n";
        cin>>choice;

    }
    switch (choice) {
        case 1:
            cout << "Feature to add task is not implemented yet.\n";
            break;
        case 2:
            cout << "Feature to list tasks is not implemented yet.\n";
            break;
        case 3:
            cout << "Feature to remove task is not implemented yet.\n";
            break;
        case 4:
             cout<<"Exiting...\n";
            break;
    }
    //TESTING TASK AND DISPLAY TASK
    Task task1("c++","coding language","skill","1 week",2);
    task1.displayTask();
    //TESTING VECTOR AND ADDING
    addTask();


    return 0;
}
