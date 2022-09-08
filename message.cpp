////
//// Created by GuoylyL on 2022/9/8.
////
//#include <iostream>
//#include <string>
//#include <set>
//
//class Folder;
//
//class Message {
//    friend class Folder;
//
//public:
//    explicit Message(const std::string &str = " ") : contents(str) {}
//
//    Message(const Message &);
//
//    Message &operator=(const Message &);
//
//    ~Message();
//
//    void save(Folder &);
//
//    void remove(Folder &);
//
//    void swap(Message &lm, Message &rm) {
//        using std::swap;
//        for (auto f: lm.folders)
//            f->remMsg(&lm);
//        for (auto f: rm.folders)
//            f->remMsg(&rm);
//        swap(lm.folders, rm.folders);
//        swap(lm.contents, rm.contents);
//        for (auto f: lm.folders)
//            f->addMsg(&lm);
//        for (auto f: rm.folders)
//            f->addMsg(&rm);
//    }
//
//private:
//    std::string contents;
//    std::set<Folder *> folders;
//
//    void add_to_Folders(const Message &);
//
//    void remove_of_Folders();
//};
//
//void Message::save(Folder &f) {
//    folders.insert(&f);
//    f.addMsg(this);
//}
//
//void Message::remove(Folder &f) {
//    folders.erase(&f);
//    f.remMsg(this);
//}
//
//void Message::add_to_Folders(const Message &m) {
//    //for(有迭代器的数据类型：一个序列)
//    //      语句块
//    for (auto f: m.folders) //C++11新特性
//        f->addMsg(this);
//}
//
//Message::Message(const Message &m) {
//    contents = m.contents;
//    folders = m.folders;
//    add_to_Folders(m);
//}
//
//void Message::remove_of_Folders() {
//    for (auto f: folders)
//        f->remMsg(this);
//}
//
//Message::~Message() {
//    remove_of_Folders();
//}
//
//Message &Message::operator=(const Message &m) {
//    remove_of_Folders();
//    contents = m.contents;
//    folders = m.folders;
//    add_to_Folders(m);
//    return *this;
//}
//
//class Folder {
//    friend class Message;
//
//public:
//    Folder() = default;
//
//    Folder(const Folder &);
//
//    Folder &operator=(const Folder &);
//
//    ~Folder();
//
//    void addMsg(Message *);
//
//    void remMsg(Message *);
//
//private:
//    std::set<Message *> message;
//
//    void add_to_Message(const Folder &);
//
//    void remove_from_Message();
//};
//
//void Folder::addMsg(Message *m) {
//    message.insert(m);
//}
//
//void Folder::remMsg(Message *m) {
//    message.erase(m);
//}
//
//void Folder::add_to_Message(const Folder &f) {
//    for (auto m: f.message)
//        m->folders.insert(this);
//}
//
//void Folder::remove_from_Message() {
//    for (auto m: message)
//        m->folders.erase(this);
//}
//
//
//Folder &Folder::operator=(const Folder &f) {
//    remove_from_Message();
//    message = f.message;
//    add_to_Message(f);
//    return *this;
//}
//
//Folder::~Folder() {
//    remove_from_Message();
//}
//
//
