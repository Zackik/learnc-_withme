#include <iostream>

using std::string;
//abstract thường được thể hiện rõ nhất qua bằng cách sử dụng hàm ảo thuần túy (Pure virtual function).
class Abstract{
    virtual void AskPromotion()=0;

};

//encapsulation trong ngôn ngữ lập trình hướng đối tượng là kỹ thuật gom nhóm dữ liệu và các hàm xử lý dữ liệu đó vào chung một lớp, đồng thời che giấu các chi tiết bên trong bao vệ dữ liệu.
class Employee:Abstract{
private:
    
    string Company;
    int Age;
protected:
    string Name;
public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void Introduce(){
        std::cout<<"Name - "<<Name<<std::endl;
        std::cout<<"Company - "<<Company<<std::endl;
        std::cout<<"Age - "<<Age<<std::endl;
    }
    //construct is a special member function inside a class that automatically called when an object of that class is created.
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;

    }
    void AskPromotion(){
        if(Age>30){
            std::cout<<Name <<" got promoted! "<<std::endl;
        }
        else{
            std::cout<<Name <<" sorry No got promoted for you! "<<std::endl;
        }
    }
    virtual void work(){
        std::cout<<Name<<" is checking email, task backlog, performing tasks.. "<<std::endl;
    }
};
//Inheritance is one of the fundametal concepts of OOP that allows a class to acquire the properties and behaviorrs of another class. It promotes code reusability by enabling new classes to extend exiting ones instead of rewriting code.
class Developer:public Employee{
public:
    string FavProgramming;
    Developer(string name, string company, int age, string language)
        : Employee(name, company, age)
    {
        FavProgramming = language;
    }
    void fixbug(){
        std::cout<<Name<< " fix bug using "<<FavProgramming <<std::endl;
    }
    void work(){
        std::cout<<Name<<" is writing "<<FavProgramming <<" code "<<std::endl;
    }

};
class Teacher:public Employee{
public:
    string Subject;
    void Prepare(){
        std::cout<<Name<<" is preparing "<<Subject<<" lesson "<<std::endl;
    }
     Teacher(string name, string company, int age, string sub):
        Employee(name, company, age)
    {
        Subject = sub;
    }
    void work(){
        std::cout<<Name<<" is teacher "<<Subject<<std::endl;
    }
};
int main(){
    
    Developer a = Developer("Thanh", "Codebeauty",23,"c++");
    Teacher t = Teacher("Jack", "Cool school", 34, "Math");
    Employee* e = &a;
    e->work();


}