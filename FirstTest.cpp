#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        short age;

    public:
        Student(short age){
            if(age>26) age=25;
            if(age<18) age=19;
            this->age=age;
        }
        short getAge(){
            return age;
        }
};
// test metod klasy Student
class StudentTest{
    private:
        Student *studentRef;

    public:
        StudentTest(Student* studentRef){
            this->studentRef=studentRef;
        }
        bool SprawdzeniePoprawnosciWieku(){
            if (studentRef->getAge()>26) {
            cout << "blad wieku- za duzo";
            return false; 
            }
            else return true;
        }
        bool SprawdzenieWiekuPonizej(){
            if(studentRef->getAge()<18){
            cout << "wartoisc minusowa";
            return false;
            }
            else return false;
        }
};
//...................
int main(){

    Student* student = new Student(23);
    StudentTest* test1 = new StudentTest(student);
    test1->SprawdzeniePoprawnosciWieku();
    test1->SprawdzenieWiekuPonizej();

    delete student;
    delete test1;
    
    return 0;
}