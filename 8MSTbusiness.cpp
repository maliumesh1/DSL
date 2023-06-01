/*8] 
You have a business with several offices; you want to lease phone lines to connect them 
up with each other; and the phone company charges different amounts of money to 
connect different pairs of cities. Find set of lines that connects all your offices with 
a minimum total cost.[prims Algorithm]*/
#include<iostream>
using namespace std;
class tree
{
int a[20][20],l,u,w,i,j,v,e,visited[20];
public:
void input();
void display();
void minimum();
};
void tree::input()
{
cout<<"Enter no of branches : ";
cin>>v;
for(i=0;i<v;i++)
{
visited[i]=0;
for(j=0;j<v;j++)
{
a[i][j]=999;
}
}
cout<<"\nEnter no of connections: ";
cin>>e;
for(i=0;i<e;i++)
{
cout<<"Enter the end branches of connections: "<<endl;
cin>>l>>u;
cout<<"Enter the phone company charges for this connection: ";
cin>>w;
a[l-1][u-1]=a[u-1][l-1]=w;
}
}
void tree::display()
{
cout<<"\nAdjacency matrix:";
for(i=0;i<v;i++)
{
cout<<endl;
for(j=0;j<v;j++)
{
cout<<a[i][j]<<" ";
}
cout<<endl;
}
}
void tree::minimum()
{
int p=0,q=0,total=0,min;
visited[0]=1;
for(int count=0;count<v;count++)
{
min=999;
for(i=0;i<v;i++)
{
if(visited[i]==0)
{
for(j=0;j<v;j++)
{
if(visited[j]==0)
{
if(min>a[i][j])
{
min=a[i][j];
p=i;
q=j;
total=total+min;
}
min=999;
} }
}
}
visited[p]=1;
visited[q]=1;
}
cout<<"The minimum total cost of connections of all branches is:"<<total<<endl;
}
int main()
{
int ch,opt;
tree t;
do{
cout<<"==========PRIM's Algorithm=========="<<endl;
cout<<"\n1.Input\n \n2.Display\n \n.3.Minimum\n"<<endl;
cout<<"Enter your choice :"<<endl;
cin>>ch;
switch(ch)
{ case 1:
cout<<"***Input your values***"<<endl;
t.input();
break;
case 2:
cout<<"***Display the Contents***"<<endl;
t.display();
break;
case 3:
cout<<"***Minimum***"<<endl;
t.minimum();
break;
default:
cout<<"Wrong choice";
break;
}
cout<<"Do you want to continue?(y==1/n==0): ";
cin>>opt;
}while(opt==1);
return 0;
}
