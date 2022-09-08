////
//// Created by GuoylyL on 2022/8/23.
////
//#include <iostream>
//#include <thread>
//#include <string>
//using namespace std;
//class A{
//public:
//    int m_i;
//    //类型转换构造函数，可以把一个int对象转换对一个类A对象
//    A(int a):m_i(a){cout<<"A::A(int a)构造函数 "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//    A(const A& a):m_i(a.m_i){cout<<"A::A(const A)拷贝构造函数 "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//    ~A(){cout<<"A::~A()析构函数 "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//
//    void thread_work(int num){
//        cout<<"子线程thread_work "<<this<<" thread_id = "<<this_thread::get_id()<<endl;
//    }
//    void operator()(int n){
//        cout<<n<<"operator() "<<this<<" thread_id = "<<this_thread::get_id()<<endl;
//    }
//};
////void myprint(const int &i,char *p){
////void myprint(const int i,char *p){
////void myprint(const int i,const string &p){
////    cout<<i<<endl;    //i并不是mvar的引用，实际是值传递，即便主线程detach了子线程那么子线程中用i值是安全的
////    cout<<p.c_str()<<endl;    //指针再detach子线程是，会出现问题
////}
//void myprint(const int i,const A &p){
//    cout<< &p <<endl; //address of p
//}
//void myprint2(A &p){
//    p.m_i = 199;
//    cout<< "子线程myprint2的参数地址是："<<&p << " thread_id = "<<this_thread::get_id()<<endl; //address of p
//}
//void myprint3(unique_ptr<int> p){
//
//    cout<< "子线程myprint3的参数地址是："<<&p << " thread_id = "<<this_thread::get_id()<<endl; //address of p
//}
//
//int main(void){
//    //传递临时对象作为线程参数
//
////    int mvar = 1;
////    int &mvarry = mvar;
////    char mybuf[] = "this is test!";
////    //thread t1(myprint,mvar,mybuf); //mybuf是什么时候转化为string的？
////                                        //事实上 mubuf被回收了 系统才用mubuf转换string
////    //t1.join();
////    thread t1(myprint,mvar,string(mybuf));
//    cout<<"主线程ID是："<<this_thread::get_id()<<endl;
//    int mvar = 1;
//    int myseconder = 12;
//    A boj(10);
//    //unique_ptr<int> mvp(new int(100));
//    //thread t1(myprint3,std::move(mvp));//myseconder 转换为A类型对象传递给myprint的第二个参数
//    //thread t1(&A::thread_work,std::ref(boj),14);  //&boj == std::ref(boj) 不能使用detach 不安全
//
//    thread t1(std::ref(boj),15); //不调用拷贝构造函数 使用detach就会不安全
//    t1.join();
//    //_sleep(46);
//    cout << "-------------s------------" << endl;
////（a）若传递简单类型参数，值传递；
////（b）若传递类对象，避免隐式类型转换，那么使用classname(*)使用临时对象，然后再函数参数里，用引用来接，否则会再次进行复制；
//
//
////线程ID概念，id是个数字，每个线程实际上都对应一个数字，而且每个线程对应的id不同，线程id可以用c++标准库中的函数获取
//
////std::ref 函数
////不用拷贝构造函数了
//
////智能指针做参数传入 要用join()；
//
////用成员函数指针做线程函数 operator()
//    return 0;
//}