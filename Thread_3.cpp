//
// Created by GuoylyL on 2022/8/24.
//
//#include <iostream>
//#include <string>
//#include <thread>
//#include <vector>
//#include <list>
//
//using namespace std;
//vector <int> g_v = {1,2,3}; //ֻ������
////�߳���ں���
//void myprint1(int n){
//    //���Ը�����߳�ʹ��
////    cout<<"myprint1��ʼִ�� ��thread id = "<<n<<endl;
////
////    cout<<"myprint1����ִ�� ��thread id = "<<n<<endl;
//    cout<<"id is "<<std::this_thread::get_id()<<"'s thread,print g_v is "<<g_v[0]<<g_v[1]<<g_v[2]<<endl;
//}
//class Fw{
//public:
//    void inMsgRecvQueue(){
//        for(int i=0;i<100000;++i){
//            cout<<"inMsgRecvQueue(),insert a enum " << i <<endl;
//            msg_Recv_Queue.push_back(i);
//        }
//    }
//
//    //ȡ��������߳�
//    void outMsgRecvQueue(){
//        for(int i=0;i<100000;++i){
//            if(!msg_Recv_Queue.empty()){
//                //��Ϣ���в�Ϊ��
//                int command = msg_Recv_Queue.front(); //���ص�һ��Ԫ�أ��������Ԫ���Ƿ����
//                msg_Recv_Queue.pop_front(); //�Ƴ��Ѿ���Ӧ��Ԫ��
//                //���´��봦��data
//            }
//            else{
//                //
//                cout<<"outMsgRecvQueue(),Ŀǰ��Ϣ���пգ�"<<i<<endl;
//            }
//        }
//        cout<<"END!"<<endl;
//    }
//private:
//    std::list<int> msg_Recv_Queue; //������ר�����ڴ�����ҷ�����������
//};
//int main(){
//    //1.�����͵ȴ�����߳�
//    //a> ����߳�ִ��˳�����ҵģ������������ڲ����̵߳����е��Ȼ����йأ�
//    //b> ���̵߳ȴ��������߳����н��������߳̽�����join������д���ȶ��ĳ���
//    //c> thread������뵽�����й�����һ�δ����������̲߳��Դ������̹߳���ܷ���
////    vector<thread> ts;
////    //����ʮ���̣߳��߳���ں���ͳһʹ���Ϻ���
////    for (int i = 0;i<10;i++){
////        ts.push_back(thread(myprint1,i)); //����10���̣߳�ͬʱ��ʼִ��
////    }
////    for(auto iter = ts.begin();iter!=ts.end();++iter){
////        iter->join();
////    }
////    cout<<"================sss==============="<<endl;
//
//
//    //2.���ݹ�����������
//    //ֻ���������ǰ�ȫ�ȶ��ģ�ֱ�Ӷ��Ϳ���
//    //�ж���д������-----2���߳�д��8���̶߳� ��򵥵�һ�ַ���������Ҫ����ʱ����д��д��ʱ���ܶ���2���̲߳���ͬʱд��8���̲߳���ͬʱ��
//    //����
//    //���磺
//    //����--���� �� T123��10����Ʊ���� ��Ʊ��1��2����ͬʱ��Ҫ��99����λ��
//    //�������ݵı�����������
//
//    //������Ϸ�������������Լ��������̣߳�һ���߳��ռ�������������������д��һ��������
//    //                                          ��һ���̴߳Ӷ�����ȡ�����������ִ�ж���
//    //��Ա���������߳���ں���
//    //���뻥������������߳����ݱ������⣻
//    Fw a_i;
//    std::thread myOut(&Fw::outMsgRecvQueue,&a_i); //�ڶ������������ã����ܱ�֤thread���õ���ͬһ������
//    std::thread myIn(&Fw::inMsgRecvQueue,&a_i);
//    myOut.join();
//    myIn.join();
//
//    return 0;
//}