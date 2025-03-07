#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
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
    int getPriority() const {
        return priority;
    }
    string getTitle()const {
        return title;
    }
    string getDescription()const {
        return description;
    }
    string getCategory()const {
        return category;
    }
    string getDuedate()const {
        return dueDate;
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
    cout<<"Added Successfully\n";

}

void listTasks() {
     if(tasks.empty()) {
         cout<<"No tasks available !\n";
         return;
     }
    sort(tasks.begin(),tasks.end(),[](const  Task &a, const Task &b) {
        return  a.getPriority()<b.getPriority();
    });
    for (size_t i=0; i< tasks.size();++i) {
        cout<<i+1<<".";
        tasks[i].displayTask();
    }
}
void removeTask() {
    listTasks();
    if (tasks.empty()) {
        cout<<"No tasks available";
    }
    int num;
    cout<<"Enter task number to be deleted:";
    cin>>num;
    if (num<1 || num> tasks.size()) {
        cout<<"Invalid number\n";
    }
    tasks.erase(tasks.begin() +(num-1));
    cout<<"Task removed successfully!\n";
}
const  string FILE_NAME="tasks.txt";
void saveFile() {
    ofstream file(FILE_NAME);
    for( const auto &task:tasks) {
        file<<task.getTitle()<<","<<task.getDescription()<<","<<task.getCategory()<<","<<task.getDuedate()<<","<<task.getPriority()<<"\n";

    }
    file.close();
}
void loadFile() {
    ifstream file(FILE_NAME);
        if(!file) return;
        string line;
    while(getline(file,line)){
        stringstream ss(line);
        string title,description,category,duedate,priority;
        getline(ss,title,',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, duedate, ',');
        getline(ss, priority, ',');
        tasks.push_back(Task(title,description,category,duedate,stoi(priority)));
    }
    file.close();
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
    addTask();
    listTasks();


    return 0;
}
