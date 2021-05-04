#include<iostream>
using namespace std;
class Person{
    private:// thuộc tính nên được bảo mật. Mình có thể set với chế độ khác private
        string id;// string là chuỗi trong thư viện iostream, không gian tên std
        string name;
        int age;
        float gpa;
    public:
    // NOTE: hàm khởi tạo
        Person();// hàm khởi tạo
        Person(string id, string name, int age, float gpa);// khởi tạo có tham số truyền vào
        Person(const Person& other);// khởi tạo sao chép
    // NOTE: hàm hủy
        ~Person(){// hàm này gọi tự động để thu dọn bộ nhớ, trong các ngôn ngữ cấp cao thì hàm này k cần
            cout<<"destructor called of "<<id<<endl;// hàm này có thể sử dụng để hủy cấp phát bộ nhớ khi dùng biến con trỏ
        }    
        void print();// hàm xuất thông tin người
};
Person::Person(){
    this->id = "00000000";
    this->name = "no name";
    this->age = 0;
    this->gpa = 0;
}
Person::Person(string id, string name, int age, float gpa){
    this->id = id;
    this->name = name;
    this->age = age;
    this->gpa = gpa;
}
Person::Person(const Person& other){
    this->id = other.id;
    this->name =  other.name;
    this->age = other.age;
    this->gpa = other.gpa;
}
void Person::print(){
    cout<<"id: "<<this->id<<", name: "<<this->name<<",age: "<<this->age<<" ,gpa: "<<this->gpa<<endl;
}
int main(){
    Person person;// khởi tạo mặc định
    Person person2 = Person("001","Minh Anh",13,8.5);// khởi tạo có đối số 
    Person person3 = Person(person2);// Khởi tạo sao chép, sao chép dữ liệu từ person2
    person.print();
    person2.print();
    person3.print();
    return 0;
}