/*14] Company maintains employee information as employee ID, name, designation and salary. 
Allow user to add, delete information of employee. Display information of particular 
employee. If employee does not exist an appropriate message is displayed. If it is, then 
the system displays the employee details. Use index sequential file to maintain the data. */

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Employee
{
 int employeeId;
 char sname[20];
 char Designation[20];
 float salary;
 
 public:
 Employee()
 {
 employeeId=0;
 strcpy(sname,"\0");
 strcpy(Designation,"\0");
 salary=0.0;
 }
int acceptEmployeeId()
{
 return(employeeId);
}
void acceptDetails()
{
cout<<"\nEnter Details: ";
cout<<"\nEmployee Id : ";
cin>>employeeId;
cout<<"Sname: ";
cin>>sname;
cout<<"Designation : ";
cin>>Designation;
cout<<"Salary: ";
cin>>salary;
}
void putData()
{
cout<<"\nEmployeeId :" ;
cout<<employeeId;
cout<<"\tSname :";
cout<<sname;
cout<<"\nDesignation: ";
cout<<Designation;
cout<<"\tSalary:";
cout<<salary;
cout<<"\n\n";
}
};
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
 Employee r;
 r.acceptDetails();
 fout.open("Data.txt",ios::ate|ios::app);
 fout.write((char*)&r,sizeof(r));
 fout.close();
}
void Operation::show()
{
 Employee r;
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
 Employee r;
 int flag=0;
 fin.open("Data.txt");
 fin.seekg(0,ios::beg);
 while(fin.read((char*)&r,sizeof(r)))
 {
 if(r.acceptEmployeeId()==rno)
 {
 flag=1;
 break;
 }
 }
 fin.close();
 if(flag==1)
 {
 cout<<"\nEmployee Found:";
 r.putData();
 }
 else
 {
 cout<<"Employee not Found!!";
 }
}
int Operation::DelRecord(int rno)
{
 Employee r;
 int flag=0;
 fin.open("Data.txt");
 fin.seekg(0,ios::beg);
 while(fin.read((char*)&r,sizeof(r)))
 {
 if(r.acceptEmployeeId()==rno)
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
 Employee r;
 int flag=0;
 fs.open("Data.txt");
 fs.seekg(0,ios::beg);
 while(fs.read((char*)&r,sizeof(r)))
 {
 if(r.acceptEmployeeId()==rno)
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
 cout<<"\n1.Employee Record \n2.show \n3.Search \n4.Delete \n5.Edit";
 cout<<"\nEnter your choice:";
 cin>>ch;
 switch(ch)
 {
 case 1:cout<<"\nEnter a Employee Details:";
 o.addRecord();
 break;
 case 2:cout<<"\nEmployee details are:";
 o.show();
 break;
 case 3:cout<<"\nEnter Employee Id to search:";
 cin>>n;
 o.search(n);
 break;
 case 4:cout<<"\nEnter Employee Id to Delete:";
 cin>>n;
o.DelRecord(n);
 break;
 case 5:cout<<"\nEnter Employee Id to edit:";
 cin>>n;
 o.edit(n);
 break;
 }
 }while(ch<6);
 return 0;
}
