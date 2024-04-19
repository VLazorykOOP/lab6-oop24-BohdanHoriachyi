
#include <iostream> 
#include <string> 

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}
    virtual ~Person() {}

    virtual void inputInfo() {
        std::cout << "Enter name: ";
        std::cin >> name;
    }

    virtual void printInfo() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Father : virtual public Person {
protected:
    int age;

public:
    Father(const std::string& n, int a) : Person(n), age(a) {}

    void inputInfo() override {
        Person::inputInfo();
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    void printInfo() const override {
        Person::printInfo();
        std::cout << "Age: " << age << std::endl;
    }
};

class Mother : virtual public Person {
protected:
    int age;

public:
    Mother(const std::string& n, int a) : Person(n), age(a) {}

    void inputInfo() override {
        Person::inputInfo();
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    void printInfo() const override {
        Person::printInfo();
        std::cout << "Age: " << age << std::endl;
    }
};

class Daughter : public Father, public Mother {
public:
    Daughter(const std::string& n, int a, int b) : Person(n), Father(n, a), Mother(n, b) {}

    void inputInfo() override {
        Father::inputInfo();
        Mother::inputInfo();
    }

    void printInfo() const override {
        Father::printInfo();
        Mother::printInfo();
    }
};

int main() {
    Daughter d("Emily", 40, 38);
    d.inputInfo();
    d.printInfo();

    return 0;
}


