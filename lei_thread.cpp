//
// Created by GuoylyL on 2022/8/23.
//
//�������������߳�
//#include <thread>
//#include <iostream>
//using namespace std;
//class TA{
//public:
//    int m_i;
//    TA(int i):m_i(i){
//        cout<<"���캯��\n";
//    }
//    TA(const TA&ta):m_i(ta.m_i){
//        cout<<"��������\n";
//    }
//    ~TA(){
//        cout<<"��������\n";
//    }
//
//    void operator()(){ //�ɵ��ö���
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
    //ta�Ǿֲ����� �����߳̽������������ʵ�����Ǳ����Ƶ������߳���ȥ
    //TA�������û�����ã�û��ָ�룬�Ͳ����������

    //2.ʹ��lambda���ʽ
//    auto mylamthread = []{
//        cout<< "�߳̿�ʼ\n";
//
//        cout<<"�߳̽���\n";
//    };
//    thread t2(mylamthread);
//    t2.detach();
//    cout<<"-------------g------------\n";
//
//    return 0;
//}
