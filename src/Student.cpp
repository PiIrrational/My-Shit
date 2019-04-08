#include "Student.h"
#include <string>
#include <cstring>

using namespace std;

Student::Student()
{
    //ctor
    fName = " ";
    lName = " ";
    id = " ";
    email = " ";
    exam1 = " ";
    exam2 = " ";
    exam3 = " ";
}

Student::~Student()
{
    //dtor

}

void setFName(string t){
    this.fName = t;
}

void setLName(string t){
    this.lName = t;
}

void setID(string t){
    this.id = t;
}

void setEmail(string t){
    this.email = t;
}

void setExam1(string t){
    this.exam1 = t;
}

void setExam2(string t){
    this.exam2 = t;
}

void setExam3(string t){
    this.exam3 = t;
}

string getFName(){
    return this.fName;
}

string getLName(){
    return this.lName;
}

string getID(){
    return this.id;
}

string getEmail(){
    return this.email;
}

string getExam1(){
    return this.exam1;
}

string getExam2(){
    return this.exam2;
}

string getExam3(){
    return this.exam3;
}
