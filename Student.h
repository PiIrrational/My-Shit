#ifndef STUDENT_H
#define STUDENT_H
#include <string> //idk if I need this

class Student
{
    public:
        Student();
        ~Student();
        void setFName(string t);
        void setLName(string t);
        void setID(string t);
        void setEmail(string t);
        void setExam1(string t);
        void setExam2(string t);
        void setExam3(string t);

        string getFName();
        string getLName();
        string getID();
        string getEmail();
        string getExam1();
        string getExam2();
        string getExam3();

    protected:

    private:
        string fName;
        string lName;
        string id;
        string email;
        string exam1;
        string exam2;
        string exam3;
};

#endif // STUDENT_H
