//
// Created by GuoylyL on 2022/8/23.
//
//其他方法创建线程
//#include <thread>
//#include <iostream>
//using namespace std;
//class TA{
//public:
//    int m_i;
//    TA(int i):m_i(i){
//        cout<<"构造函数\n";
//    }
//    TA(const TA&ta):m_i(ta.m_i){
//        cout<<"拷贝构造\n";
//    }
//    ~TA(){
//        cout<<"析构函数\n";
//    }
//
//    void operator()(){ //可调用对象
//        cout<<"m_i1 = "<<m_i<<endl;
//
//        cout<<"m_i2 = " <<m_i<<endl;
//        cout<<"m_i3 = " <<m_i<<endl;
//        cout<<"m_i4 = " <<m_i<<endl;
//    }
//};
//int main(){
//    int myi = 6;
//    TA ta(myi);
//    thread t(ta);
//    t.detach();
    //ta是局部对象 当主线程结束后，这个对象实际上是被复制到了新线程中去
    //TA类对象中没有引用，没有指针，就不会产生问题

    //2.使用lambda表达式
//    auto mylamthread = []{
//        cout<< "线程开始\n";
//
//        cout<<"线程结束\n";
//    };
//    thread t2(mylamthread);
//    t2.detach();
//    cout<<"-------------g------------\n";
//
//    return 0;
//}
