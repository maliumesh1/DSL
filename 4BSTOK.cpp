/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the 
values in the order given. After constructing a binary tree -
i. Insert new node 
ii. Find number of nodes in longest path from root 
. Search a value
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{  int a;
   node *left,*right;
 };
class Bt
{ 
     node *root=NULL,*temp=NULL,*t1=NULL,*s=NULL, *t=NULL;
     int count;
     public:
     Bt(){  count=0;    }
     node *create();
     void insert();
     void del();
     node *delet(node*,int);
     void find();
     void search();
     void sw();
     void swap(node*);
     void height();
     int he(node*,int);
     void disp(node*);
     void display();
     node *findmin(node*);
    
};      
node *Bt::create()
{  
     node *p=new(struct node);
     p->left=NULL;
     p->right=NULL;
     cout<<"\n enter the data";
     cin>>p->a;
     return p;
}
void Bt::insert()
{  
     temp=create();
     if(root==NULL)
     {      root=temp;       }
     else
     {    t1=root;
          while(t1!=NULL)
          {      s=t1;
                 if((temp->a)>(t1->a))
                 {     t1=t1->right;    }
                 else
                 {     t1=t1->left;     }
          }
              if((temp->a)>(s->a))
              {     s->right=temp;    }
              else
              {   s->left=temp;       }
      }             
}
void Bt::search()
{   
      int m,f=0;
      if(root==NULL)
      {  cout<<"\n tree not exist";
      }
      else
      {
              cout<<"\n enter data to be searched";
              cin>>m;
        if(root->a==m)
        {   cout<<"\ndata found";   }
        else
        {    t1=root;
             while(t1->a!=m)
             {
                 if((m)>(t1->a))
                 {     t1=t1->right;  }
                 else
                 {   t1=t1->left;       }
                 if(t1==NULL)
                 {   cout<<"\n data not found";     f=1; 
                     break;
                 }
             }
          if(f==0)
          {   cout<<"\n data found";    }
             
        }
      }  
}  
void Bt::height()
{
    count=0;
    if(root==NULL)
    {  cout<<"\n tree not exist";
    }
    else
    {
    he(root,0); cout<<"\n height of the tree is"<<count;    
    }
   
}
int Bt::he(node *q,int c)  // he is a function that will be used to calculate height of the tree. Can be called using root and counter intilized to 0
{  
      c++;
     // cout<<"\n*"<<q->a<<"*"<<c<<"*\n";
          if(q->left!=NULL)
      {      he(q->left,c);    
      }
          if(q->right!=NULL)
          { 
                he(q->right,c);
          }
          if(count<c)
          {
                count=c;  
          }
     
     
          return 0;

}
  
void Bt::display()
{
  
    if(root==NULL)
    {  cout<<"\n tree not exist";
    }
    else
    {
       disp(root);    
    }
   
}
void Bt::disp(node *q) 
{ 
      cout<<"\n*"<<q->a;
          if(q->left!=NULL)
      {      disp(q->left);    
      }
          if(q->right!=NULL)
          { 
                disp(q->right);
          }
         
 }
int main()
{ 
     Bt b;  int x;     char ch;
     while(1)
     {
               cout<<"\n enter your choice";
               cout<<"\n 1.insert";
               
               cout<<"\n 3.search";
               
               cout<<"\n 5.height";
               
               cout<<"\n 7.display";
               cout<<"\n 8.exit";
               cin>>x;
               switch(x)
               {     case 1: b.insert();
                                    break;
                     
                     case 3: b.search();
                                    break;
                       
                    
                     case 5: b.height();
                                    break;
                     
                     case 7: b.display();
                                    break;
                     case 8:exit(0);
               }
                
       }       
   
    return 0;
}
