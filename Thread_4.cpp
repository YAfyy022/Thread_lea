////
//// Created by GuoylyL on 2022/9/6.
////������ ����
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
////                std::unique_lock<std::mutex> sbguard(my_mutex_1,std::adopt_lock); //���캯��lock ��������unlock
//            //my_mutex_1.lock();
//                //.....//
//            //my_mutex_2.lock();
//
////            std::unique_lock<std::mutex> sbguard1(my_mutex_1,std::try_to_lock);
////            if(sbguard1.owns_lock()){
//            //std::unique_lock<std::mutex> sbguard(my_mutex_1,std::defer_lock);
//            //sbguard.lock();
//         // // // //std::unique_lock<std::mutex> sbguard(my_mutex_1);
//         //// ////  std::unique_lock<std::mutex> sbguard2(std::move(sbguard)); //sbguardָ��գ� sbguard2ָ��my_mutex_1
//
//            //std::mutex *ptx = sbguard.release();
//            std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();
//            //if(sbguard.try_lock() == true){
//            msg_Recv_Queue.push_back(i);
//            //}
//           // else{
//           //     cout << "inMsgRecvQueueִ�С�no ���������������� lock !!"<< endl;
//           // }
//
//           // my_mutex_2.unlock();
//              // my_mutex_1.unlock();
//            ptx->unlock();
//        }
//    }
//    bool outMsgLULProc(int &command){
//        std::unique_lock<std::mutex> sbguard(my_mutex_1); //���캯��lock ��������unlock
//        //my_mutex_2.lock();
//        //my_mutex_1.lock();
//        std::chrono::milliseconds dura(5000); // 1s = 1000ms
//        std::this_thread::sleep_for(dura);
//        if(!msg_Recv_Queue.empty()){
//            //��Ϣ���в�Ϊ��
//            command = msg_Recv_Queue.front(); //���ص�һ��Ԫ�أ��������Ԫ���Ƿ����
//            msg_Recv_Queue.pop_front(); //�Ƴ��Ѿ���Ӧ��Ԫ��
//            //���´��봦��data
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
//    //ȡ��������߳�
//    void outMsgRecvQueue(){
//        int command =0;
//
//        for(int i=0;i<1000000;++i){
//            bool result = outMsgLULProc(command);
//            if(result){
//                cout<<"outMsgRecvQueue(),ȡ��һ��Ԫ�� "<< command <<endl;
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
//    //�����������ݣ�����ʱ��ĳ���߳��ô���ѹ���������ס������������������ݵ��̱߳���ȴ�����
//    //1.������ mutex
//     /*
//     �������Ǹ�����󣬶���̳߳�����lock() ��Ա������������ֻ��һ���̺߳������ɹ����ɹ��ı�־��lock��������
//     �������ʧ�ܣ���ô���̿���lock������ϵĳ���ȥ����
//     ������ѡ����ʵ��ٽ����������� ����
//     �÷� "
//        lock() unlock()
//        lock(), operator shared data, unlock()
//        ��Ҫ�ɶ�ʹ��
//
//        ��ֹ���ǳɶ�ʹ�� std::lock_guard����ģ�壬�Զ�unlock
//        std::lock_guard��ģ�� ֱ��ȡ��lock and unlock
//        "
//      */
//     //����
//
//     //���������� ����˳��һ��
//     //std::lock()����ģ�壬һ����ס�������������ϵĻ������� �������������˳������ν
//    // unique_lock�Ǹ���ģ�壬�����У�һ��lock_guard�Ƽ�ʹ��
//    //unique_lock�ĵڶ�������
//    /*
//     *  2.unique_lock�ĵڶ�������
//            2.1 std::adopt_lock��
//            ��ʾ����������Ѿ���lock()��������Ҫ�ڹ��캯����lock����������ˡ�
//            ǰ�᣺������ǰlock
//            lock_guard��Ҳ�������������
//
//            2.2 std::try_to_lock��
//            ������mutex��lock()ȥ�������mutex�������û�������ɹ������������أ��������������
//            ʹ��try_to_lock��ԭ���Ƿ�ֹ�������߳�����mutex̫��ʱ�䣬���±��߳�һֱ������lock����ط�
//            ǰ�᣺������ǰlock();
//            owns_lock()�����ж��Ƿ��õ��������õ�����true
//
//            2.3 std::defer_lock��
//            ���û�еڶ��������Ͷ�mutex���м���������defer_lock��ʼ����һ��û�м�����mutex
//            ������������Ŀ�����Ժ���Ե���unique_lock��һЩ����
//            ǰ�᣺������ǰlock
//            unique_lock ��Ա����
//            ��lock()
//            ��unlock()
//            ��try_lock() ���Ը�����������������ò������ͷ���true,������
//            ��release() �������������mutex����ָ�룬���ͷ�����Ȩ��unique_lock��mutex�����й�ϵ
//                ���ص���ԭʼmutex��ָ��
//     *          ��ʱ����Ҫunlock()����Ϊlock�Ĵ����Խ�٣�ִ��Խ�죬Ч��Խ��
//     *
//     * unique_lock ��Ҫ����һ��mutexָ��  һ��mutex��һ��sbguard��unique_lock<mutex>���󣩰���һ��
//     * ����Ȩ����sbguardӵ��my_mutex������Ȩ
//     * sbguard���԰��Լ���mutex������Ȩת�Ƹ�������unique_lock����
//     * ���� unique_lock�������mutex������Ȩ���� ����ת�ƣ����ǲ����Ը���
//     * */
//    return 0;
//}
