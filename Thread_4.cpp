////
//// Created by GuoylyL on 2022/9/6.
////互斥量 死锁
////
//#include <iostream>
//#include <string>
//#include <thread>
//#include <vector>
//#include <list>
//#include <mutex>
//using namespace std;
//
//class Fw{
//public:
//    std::unique_lock<std::mutex> rtn_unique_lock(){
//        std::unique_lock<std::mutex> tmpguard(my_mutex_1);
//        return tmpguard;
//    }
//    void inMsgRecvQueue(){
//        for(int i=0;i<1000000;++i){
//            cout<<"inMsgRecvQueue(),insert a enum " << i <<endl;
//           // my_mutex.lock();
//
////                my_mutex_1.lock();
////                std::unique_lock<std::mutex> sbguard(my_mutex_1,std::adopt_lock); //构造函数lock 析构函数unlock
//            //my_mutex_1.lock();
//                //.....//
//            //my_mutex_2.lock();
//
////            std::unique_lock<std::mutex> sbguard1(my_mutex_1,std::try_to_lock);
////            if(sbguard1.owns_lock()){
//            //std::unique_lock<std::mutex> sbguard(my_mutex_1,std::defer_lock);
//            //sbguard.lock();
//         // // // //std::unique_lock<std::mutex> sbguard(my_mutex_1);
//         //// ////  std::unique_lock<std::mutex> sbguard2(std::move(sbguard)); //sbguard指向空， sbguard2指向my_mutex_1
//
//            //std::mutex *ptx = sbguard.release();
//            std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();
//            //if(sbguard.try_lock() == true){
//            msg_Recv_Queue.push_back(i);
//            //}
//           // else{
//           //     cout << "inMsgRecvQueue执行。no ！！！！！！！！ lock !!"<< endl;
//           // }
//
//           // my_mutex_2.unlock();
//              // my_mutex_1.unlock();
//            ptx->unlock();
//        }
//    }
//    bool outMsgLULProc(int &command){
//        std::unique_lock<std::mutex> sbguard(my_mutex_1); //构造函数lock 析构函数unlock
//        //my_mutex_2.lock();
//        //my_mutex_1.lock();
//        std::chrono::milliseconds dura(5000); // 1s = 1000ms
//        std::this_thread::sleep_for(dura);
//        if(!msg_Recv_Queue.empty()){
//            //消息队列不为空
//            command = msg_Recv_Queue.front(); //返回第一个元素，但不检查元素是否存在
//            msg_Recv_Queue.pop_front(); //移除已经响应的元素
//            //以下代码处理data
//           // my_mutex_1.unlock();
//           // my_mutex_2.unlock();
//            return true;
//        }
//        else
//        {
//            //my_mutex_1.unlock();
//            //my_mutex_2.unlock();
//            return false;
//        }
//    }
//    //取出命令的线程
//    void outMsgRecvQueue(){
//        int command =0;
//
//        for(int i=0;i<1000000;++i){
//            bool result = outMsgLULProc(command);
//            if(result){
//                cout<<"outMsgRecvQueue(),取出一个元素 "<< command <<endl;
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
//    std::mutex my_mutex_1;
//    std::mutex my_mutex_2;
//};
//int main(){
//
//    Fw a_i;
//    std::thread myOut(&Fw::outMsgRecvQueue,&a_i);
//    std::thread myIn(&Fw::inMsgRecvQueue,&a_i);
//    myOut.join();
//    myIn.join();
//    //保护共享数据，操作时，某个线程用代码把共享数据锁住，其他想操作共享数据的线程必须等待解锁
//    //1.互斥量 mutex
//     /*
//     互斥亮是个类对象，多个线程尝试用lock() 成员函数来加锁，只有一个线程和锁定成功，成功的标志是lock函数返回
//     如果锁定失败，那么流程卡在lock这里，不断的尝试去锁定
//     互斥量选择合适的临界区域来锁定 解锁
//     用法 "
//        lock() unlock()
//        lock(), operator shared data, unlock()
//        需要成对使用
//
//        防止忘记成对使用 std::lock_guard的类模板，自动unlock
//        std::lock_guard类模板 直接取代lock and unlock
//        "
//      */
//     //死锁
//
//     //两个互斥量 上锁顺序一致
//     //std::lock()函数模板，一次锁住两个或两个以上的互斥量； 不会出现死锁，顺序无所谓
//    // unique_lock是个类模板，工作中，一般lock_guard推荐使用
//    //unique_lock的第二个参数
//    /*
//     *  2.unique_lock的第二个参数
//            2.1 std::adopt_lock：
//            表示这个互斥量已经被lock()，即不需要在构造函数中lock这个互斥量了。
//            前提：必须提前lock
//            lock_guard中也可以用这个参数
//
//            2.2 std::try_to_lock：
//            尝试用mutex的lock()去锁定这个mutex，但如果没有锁定成功，会立即返回，不会阻塞在那里；
//            使用try_to_lock的原因是防止其他的线程锁定mutex太长时间，导致本线程一直阻塞在lock这个地方
//            前提：不能提前lock();
//            owns_lock()方法判断是否拿到锁，如拿到返回true
//
//            2.3 std::defer_lock：
//            如果没有第二个参数就对mutex进行加锁，加上defer_lock是始化了一个没有加锁的mutex
//            不给它加锁的目的是以后可以调用unique_lock的一些方法
//            前提：不能提前lock
//            unique_lock 成员函数
//            ·lock()
//            ·unlock()
//            ·try_lock() 尝试给互斥量加锁，如果拿不到锁就返回true,不阻塞
//            ·release() 返回它所管理的mutex对象指针，并释放所有权，unique_lock喝mutex不再有关系
//                返回的是原始mutex的指针
//     *          有时候需要unlock()，因为lock的代码段越少，执行越快，效率越高
//     *
//     * unique_lock 需要管理一个mutex指针  一个mutex喝一个sbguard（unique_lock<mutex>对象）绑定在一起
//     * 所有权概念sbguard拥有my_mutex的所有权
//     * sbguard可以把自己对mutex的所有权转移给其他的unique_lock对象
//     * 所以 unique_lock对象这个mutex的所有权属于 可以转移，但是不可以复制
//     * */
//    return 0;
//}
