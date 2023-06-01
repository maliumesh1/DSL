/*13]Department maintains a student information. The file contains roll number, name, 
division and address. Allow user to add, delete information of student. Display 
information of particular employee. If record of student does not exist an appropriate 
message is displayed. If it is, then the system displays the student details. Use sequential 
file to main the data.*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Student
{
int rno;
char sname[20];
char subject[20];
int sub_code;
float internal;
float university;
public:
Student()
{
rno=0;
strcpy(sname,"\0");
strcpy(subject,"\0");
sub_code=0;
internal=0.0;
university=0.0;
}
int acceptRollno()
{
return(rno);
}
void acceptDetails()
{
cout<<"\nEnter Details: ";
cout<<"\nRoll no : ";
cin>>rno;
cout<<"Sname: ";
cin>>sname;
cout<<"Subject Code : ";
cin>>sub_code;
cout<<"Subject Sname: ";
cin>>subject;
cout<<"Internal Assessment Marks: ";
cin>>internal;
cout<<"University Exam Marks: ";
cin>>university;
}
void putData()
{
cout<<"\nRoll No. :" ;
cout<<rno;
cout<<"\tSname :";
cout<<sname;
cout<<"\nSubject Code: ";
cout<<sub_code;
cout<<"Subject Sname:";
cout<<subject;
cout<<"\nInternal Assess Ment Marks: ";
cout<<internal;
cout<<"\nUniversity Exam Marks: ";
cout<<university<<"\n\n";
} };
class Operation
{
ifstream fin;
ofstream fout;
fstream fs;
public:
void addRecord();
void show();
void search(int);
int DelRecord(int);
int edit(int);
};
void Operation::addRecord()
{
Student r;
r.acceptDetails();
fout.open("Data.txt",ios::ate|ios::app);
fout.write((char*)&r,sizeof(r));
fout.close();
}
void Operation::show()
{
Student r;
fin.open("Data.txt");
fin.seekg(0,ios::beg);
while(fin.read((char*)&r,sizeof(r)))
{
r.putData();
}
fin.close();
}
void Operation::search(int rno)
{
Student r;
int flag=0;
fin.open("Data.txt");
fin.seekg(0,ios::beg);
while(fin.read((char*)&r,sizeof(r)))
{
if(r.acceptRollno()==rno)
{
flag=1;
break;
}
}
fin.close();
if(flag==1)
{
cout<<"\nStudent Found:";
r.putData();
}
else
{
cout<<"Staudent not Found!!";
}
}
int Operation::DelRecord(int rno)
{
Student r;
int flag=0;
fin.open("Data");
fin.seekg(0,ios::beg);
while(fin.read((char*)&r,sizeof(r)))
{
if(r.acceptRollno()==rno)
{
flag=1;
}
else
{
fout.write((char*)&r,sizeof(r));
}
}
fin.close();
fout.close();
remove("Data.txt");
rename("temp.txt","Data.txt");
return(flag);
}
int Operation::edit(int rno)
{
Student r;
int flag=0;
fs.open("Data");
fs.seekg(0,ios::beg);
while(fs.read((char*)&r,sizeof(r)))
{
if(r.acceptRollno()==rno)
{
flag=1;
cout<<"\nEnter New Details:";
r.acceptDetails();
fs.seekp((int)fs.tellg()-sizeof(r),ios::beg);
fs.write((char*)&r,sizeof(r));
}
}
fs.close();
return(flag);
}
int main()
{
Operation o;
int ch,n;
do{
cout<<"\n1.Student Record \n2.show \n3.Search \n4.Delete \n5.Edit";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1:cout<<"\nEnter a student Details:";
o.addRecord();
break;
case 2:cout<<"\nStudent details are:";
o.show();
break;
case 3:cout<<"\nEnter rollno to search:";
cin>>n;
o.search(n);
break;
case 4:cout<<"\nEnter rollno to Delete:";
cin>>n;
o.DelRecord(n);
break;
case 5:cout<<"\nEnter rollno to edit:";
cin>>n;
o.edit(n);
break;
}
}while(ch<5);
return 0;
}
