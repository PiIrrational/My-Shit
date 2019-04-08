#include <iostream>
#include <vector>
#include "Student.h"
#include <fstream>
#include <string>
#include <cstring> //idk if I need this
#include <stdlib.h>     /* atof */

using namespace std;


void display(vector<Student> stud){
    for(int i = 0; i < stud.size(); i++){
        //cout<<"First name     last name     ID       email       exam1       exam2       exam3";
        cout<<(i + 1)<<stud[i].getfName()<<","<<stud[i].getlName()<<","<<stud[i].getID;
        cout<<","<<stud[i].getEmail()<<stud[i].getExam1<<","<<stud[i].getExam2();
        cout<<","<<stud[i].getExam3()<<"\n";
    }
}

Student makeNewStudent(){
    Student stud; //is this how you make a new student object?
    cout<<"Enter the first name: \n";
    string temp;
    stud.setFName(cin>>temp);
    cout<<"Enter the last name: \n";
    stud.setLName(cin>>temp);
    cout<<"Enter the ID: \n";
    stud.setID(cin>>temp);
    cout<<"Enter the email: \n";
    stud.setEmail(cin>>temp);
    cout<<"Enter the exam 1 grade: \n";
    stud.setExam1(cin>>temp);
    cout<<"Enter the exam 2 grade: \n";
    stud.setExam2(cin>>temp);
    cout<<"Enter the exam 3 grade: \n";
    stud.setExam3(cin>>temp);
    return stud;
}
void saveToFile(vector<Student> stud, ofstream oFile){
    double total = 0;
    for(int i = 0; i < stud.size(); i++){
        oFile<<stud[i].getFName()<<",";
        oFile<<stud[i].getLName()<<",";
        oFile<<stud[i].getID()<<",";
        oFile<<stud[i].getEmail()<<",";
        oFile<<stud[i].getExam1()<<",";
        double exam1 = atof(stud[i].getExam1());
        oFile<<stud[i].getExam2()<<",";
        double exam2 = atof(stud[i].getExam2());
        oFile<<stud[i].getExam3()<<",";
        double exam3 = atof(stud[i].getExam3());
        double average = (exam1 + exam2 + exam3)/3;
        oFile<<average<<"\n";
        total += average;
    }
    oFile<<"The class average is "<<(total/(stud.size()));
}


int main()
{
    //declare vector of 5 students
    vector<Student> studentVect(5);
    //get data from input file and assign it to each of 5 student objects in vector
    ifstream inFile("inData.csv");
    ofstream outFile("outdata.txt");

    int i = 0;
    while(!inFile.eof()){
        string temp;
        getline(inFile,temp, ",");
        studentVect[i].setFName(temp); //is this the right way to call the function?
        getline(inFile,temp,",");
        studentVect[i].setFName(temp);
        getline(inFile,temp,",");
        studentVect[i].setID(temp);
        getline(inFile,temp,",");
        studentVect[i].setEmail(temp);
        getline(inFile,temp,",");
        studentVect[i].setExam1;
        getline(inFile,temp,",");
        studentVect[i].setExam2;
        getline(inFile,temp,"\n");
        studentVect[i].setExam3;
        i++;

    }

    //get choice from user input

    int input;
    bool quit = false;
    while (!quit){
            //display menu
        cout<<"Enter the number corresponding to your desired choice: \n";
        cout<<" 1)Display Student Record \n";
        cout<<" 2)Add Student Record \n"
        cout<<" 3)Delete Student Record \n";
        cout<<" 4)Save Records to File \n";
        cout<<" 5)Exit \n";
        cin>>input;
        switch (input){
            case 1: cout<<"You chose option 1. \n";
                    display(studentVect);
                    System("PAUSE");
                    System("cls");
                    break;
            case 2: cout<<"You chose option 2. \n";
                    Student newStud = makeNewStudent();
                    studentVect.push_back(newStud); //adds newStud to the end of the Student Vector
                    System("PAUSE");
                    System("cls");
                    break;

            case 3: cout<<"You chose option 3. \n"
                    display(studentVect);
                    cout<<"Enter the number corresponding to the record you wish to delete: \n";
                    int num;
                    cin>>num;
                    studentVect.erase((num - 1));
                    System("PAUSE");
                    System("cls");
                    break;

            case 4: cout<<"You chose option 4. \n"
                    saveToFile(studentVect, outFile);
                    System("PAUSE");
                    System("cls");
                    break;

            case 5: cout<<"You chose option 5. \n"
                    quit = true;
                    System("PAUSE");
                    System("cls");
                    break;

        }
    }
    //respond accordingly
}
