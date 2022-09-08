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
//vector <int> g_v = {1,2,3}; //只读数据
////线程入口函数
//void myprint1(int n){
//    //可以给多个线程使用
////    cout<<"myprint1开始执行 ，thread id = "<<n<<endl;
////
////    cout<<"myprint1结束执行 ，thread id = "<<n<<endl;
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
//    //取出命令的线程
//    void outMsgRecvQueue(){
//        for(int i=0;i<100000;++i){
//            if(!msg_Recv_Queue.empty()){
//                //消息队列不为空
//                int command = msg_Recv_Queue.front(); //返回第一个元素，但不检查元素是否存在
//                msg_Recv_Queue.pop_front(); //移除已经响应的元素
//                //以下代码处理data
//            }
//            else{
//                //
//                cout<<"outMsgRecvQueue(),目前消息队列空！"<<i<<endl;
//            }
//        }
//        cout<<"END!"<<endl;
//    }
//private:
//    std::list<int> msg_Recv_Queue; //容器，专门用于代表玩家发送来的命令
//};
//int main(){
//    //1.创建和等待多个线程
//    //a> 多个线程执行顺序是乱的，跟造作西永内部对线程的运行调度机制有关；
//    //b> 主线程等待所有子线程运行结束后，主线程结束；join更容易写出稳定的程序
//    //c> thread对象放入到容器中管理，对一次创建大量的线程并对大量的线程管理很方便
////    vector<thread> ts;
////    //创建十个线程，线程入口函数统一使用上函数
////    for (int i = 0;i<10;i++){
////        ts.push_back(thread(myprint1,i)); //创建10个线程，同时开始执行
////    }
////    for(auto iter = ts.begin();iter!=ts.end();++iter){
////        iter->join();
////    }
////    cout<<"================sss==============="<<endl;
//
//
//    //2.数据共享的问题分析
//    //只读的数据是安全稳定的，直接读就可以
//    //有读有写的数据-----2个线程写，8个线程读 最简单的一种方法就是需要读的时候不能写，写的时候不能读，2个线程不能同时写，8个线程不能同时读
//    //其他
//    //例如：
//    //北京--深圳 火车 T123，10个售票窗口 买票：1，2窗口同时都要订99号座位；
//    //共享数据的保护案例代码
//
//    //网络游戏服务器。两个自己创建的线程，一个线程收集玩家命令，并把命令数据写道一个队列中
//    //                                          另一个线程从队列中取出命令，解析，执行动作
//    //成员函数来做线程入口函数
//    //引入互斥量，解决多线程数据保护问题；
//    Fw a_i;
//    std::thread myOut(&Fw::outMsgRecvQueue,&a_i); //第二个参数是引用，才能保证thread里用的是同一个对象
//    std::thread myIn(&Fw::inMsgRecvQueue,&a_i);
//    myOut.join();
//    myIn.join();
//
//    return 0;
//}