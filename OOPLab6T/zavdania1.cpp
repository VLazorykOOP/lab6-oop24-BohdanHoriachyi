#include <iostream>
class Base {
protected:
    double data;
public:
    Base() : data(0) {}
    Base(double d) : data(d) {}
};

class B1 :public Base {
protected:
    double MoreData;
public:
    B1() : MoreData(0.0) {}
    B1(int d, double md1) : Base(d), MoreData(md1) {}
};

class B2 :public Base, virtual public B1 {
public:
    B2() {}
    B2(int d, double md1) : Base(d), B1(d, md1) {}
};

class B3 :public B1 {
protected:
    double MoreData;
public:
    B3() : MoreData(0.0) {}
    B3(int d, double md1, double md3) : B1(d, md1), MoreData(md3) {}
};

class B4 :public B2, virtual public B3 {
public:
    B4() {}
    B4(int d, double md1, double md3) : B2(d, md1), B3(d, md1, md3) {}
};

int main() {
    std::cout << "Test !\n";
    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for B1 " << sizeof(B1) << std::endl;
    std::cout << "Size for B2 " << sizeof(B2) << std::endl;
    std::cout << "Size for B3 " << sizeof(B3) << std::endl;
    std::cout << "Size for B4 " << sizeof(B4) << std::endl;
}