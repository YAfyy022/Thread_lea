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
//    //����ת�����캯�������԰�һ��int����ת����һ����A����
//    A(int a):m_i(a){cout<<"A::A(int a)���캯�� "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//    A(const A& a):m_i(a.m_i){cout<<"A::A(const A)�������캯�� "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//    ~A(){cout<<"A::~A()�������� "<<this<<" thread_id = "<<this_thread::get_id()<<endl;}
//
//    void thread_work(int num){
//        cout<<"���߳�thread_work "<<this<<" thread_id = "<<this_thread::get_id()<<endl;
//    }
//    void operator()(int n){
//        cout<<n<<"operator() "<<this<<" thread_id = "<<this_thread::get_id()<<endl;
//    }
//};
////void myprint(const int &i,char *p){
////void myprint(const int i,char *p){
////void myprint(const int i,const string &p){
////    cout<<i<<endl;    //i������mvar�����ã�ʵ����ֵ���ݣ��������߳�detach�����߳���ô���߳�����iֵ�ǰ�ȫ��
////    cout<<p.c_str()<<endl;    //ָ����detach���߳��ǣ����������
////}
//void myprint(const int i,const A &p){
//    cout<< &p <<endl; //address of p
//}
//void myprint2(A &p){
//    p.m_i = 199;
//    cout<< "���߳�myprint2�Ĳ�����ַ�ǣ�"<<&p << " thread_id = "<<this_thread::get_id()<<endl; //address of p
//}
//void myprint3(unique_ptr<int> p){
//
//    cout<< "���߳�myprint3�Ĳ�����ַ�ǣ�"<<&p << " thread_id = "<<this_thread::get_id()<<endl; //address of p
//}
//
//int main(void){
//    //������ʱ������Ϊ�̲߳���
//
////    int mvar = 1;
////    int &mvarry = mvar;
////    char mybuf[] = "this is test!";
////    //thread t1(myprint,mvar,mybuf); //mybuf��ʲôʱ��ת��Ϊstring�ģ�
////                                        //��ʵ�� mubuf�������� ϵͳ����mubufת��string
////    //t1.join();
////    thread t1(myprint,mvar,string(mybuf));
//    cout<<"���߳�ID�ǣ�"<<this_thread::get_id()<<endl;
//    int mvar = 1;
//    int myseconder = 12;
//    A boj(10);
//    //unique_ptr<int> mvp(new int(100));
//    //thread t1(myprint3,std::move(mvp));//myseconder ת��ΪA���Ͷ��󴫵ݸ�myprint�ĵڶ�������
//    //thread t1(&A::thread_work,std::ref(boj),14);  //&boj == std::ref(boj) ����ʹ��detach ����ȫ
//
//    thread t1(std::ref(boj),15); //�����ÿ������캯�� ʹ��detach�ͻ᲻��ȫ
//    t1.join();
//    //_sleep(46);
//    cout << "-------------s------------" << endl;
////��a�������ݼ����Ͳ�����ֵ���ݣ�
////��b������������󣬱�����ʽ����ת������ôʹ��classname(*)ʹ����ʱ����Ȼ���ٺ�����������������ӣ�������ٴν��и��ƣ�
//
//
////�߳�ID���id�Ǹ����֣�ÿ���߳�ʵ���϶���Ӧһ�����֣�����ÿ���̶߳�Ӧ��id��ͬ���߳�id������c++��׼���еĺ�����ȡ
//
////std::ref ����
////���ÿ������캯����
//
////����ָ������������ Ҫ��join()��
//
////�ó�Ա����ָ�����̺߳��� operator()
//    return 0;
//}