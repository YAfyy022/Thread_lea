//
// Created by GuoylyL on 2022/9/7.
//
#include <iostream>
#include <string>
using namespace std;

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0),used(new std::size_t(1)){}
    HasPtr(const HasPtr &hasp):ps(hasp.ps),i(hasp.i),used(hasp.used){++*used;} //类指针 那么赋值后和源对象指向的是相同的string
    HasPtr& operator=(const HasPtr& s);
    ~HasPtr();

private:
    std::string *ps;
    int i;
    std::size_t *used;
};

HasPtr::~HasPtr() {
    if(--*used == 0){
        delete ps;
        delete used;
    }
}

HasPtr &HasPtr::operator=(const HasPtr &s) {
    ++*s.used;
    if(--*used == 0){
        delete ps;
        delete used;
    }
    ps = s.ps;
    used = s.used;
    i = s.i;
    return *this;
}
