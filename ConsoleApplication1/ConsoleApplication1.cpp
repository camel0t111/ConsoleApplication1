#include <iostream>
#include <Windows.h>
using namespace std;

class Student 
{
    static int strLength(const char* s);
    static void strCopy(char*& dest, const char* src);
    char* name;
    int age;
public:
    Student();
    Student(const char* Name, int Age);
    Student(const Student& other);
    void Output();
    ~Student();
};
Student::Student() : name(nullptr), age(0) 
{
}
Student::Student(const char* Name, int Age) : age(Age) 
{
    name = new char[strLength(Name) + 1];
    strCopy(name, Name);
}

Student::Student(const Student& other) : age(other.age) 
{
    if (other.name) 
    {
        name = new char[strLength(other.name) + 1];
        strCopy(name, other.name);
    }
    else 
    {
        name = nullptr;
    }
}
void Student::Output() 
{
    cout << "Name: " << name;
    cout << "; Age: " << age << endl << endl;
}
Student::~Student() 
{
    delete[] name;
    cout << "Destruct\n";
    Sleep(1000);
}
int Student::strLength(const char* s) 
{
    const char* sc = s;
    for (; *sc != '\0'; ++sc);
    return sc - s;
}
void Student::strCopy(char*& dest, const char* src) 
{
    char* d = dest;
    while ((*d++ = *src++));
}
int main() {
    Student obj1("Oleg", 21);
    obj1.Output();
    Student obj2 = obj1;
    obj2.Output();
    Student mas[2] = { {"Alena", 20}, {"Maksim", 22} };
    for (int i = 0; i < 2; i++) 
    {
        mas[i].Output();
    }
    system("pause");
    return 0;
}