/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords and display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may 
require for finding any keyword. 
*/

#include<iostream>
using namespace std;

class node
{
public:
	string key;
	string meaning;
	node *left;
	node *right;
};

class AVL
{
	node *root;
        public:
            	AVL()
            	{
            		root=NULL;
            	}
            	
	            void create();
	            node* insert(node *cur,node *temp);
            	node* balance(node *temp);
            	int dif(node *temp);
            	int height(node *temp);
            	int maximum(int a,int b);
            	
            	node* LL(node *par);
            	node* RR(node *par);
            	node* LR(node *par);
            	node* RL(node *par);
            	
            	void ascending(node *temp);
            	
            	
            	node* extractmin(node *t);
                void descending(node *temp);
                void display();
                
};

void AVL::create()
{
	char answer;
	node *temp;
	do
	{
		temp=new node();
		cout<<"\n Enter the keyword:";
		cin>>temp->key;
		cout<<"\n Enter the meaning:";
		cin>>temp->meaning;
		temp->left=temp->right=NULL;

			root=insert(root,temp);

		cout<<"\n Do you want to add another word?(y/n)";
		cin>>answer;
	}
	while(answer=='y'||answer=='Y');
}


node*AVL::insert(node*cur,node*temp)
{
	if(cur==NULL)
	{
		return temp;
	}
	if(temp->key<cur->key)
	{
		cur->left=insert(cur->left,temp);
		cur=balance(cur);
	}
	else if(temp->key>cur->key)
	{
		cur->right=insert(cur->right,temp);
		cur=balance(cur);
	}
	return cur;
}

node*AVL::balance(node *temp)
{
	int bal;
	bal=dif(temp);
	
	if(bal>=2)
	{
		if(dif(temp->left)<0)
			temp=LR(temp);
		else
			temp=LL(temp);
	}
	else if(bal<=-2)
	{
		if(dif(temp->right)<0)
			temp=RR(temp);
		else
			temp=RL(temp);
	}
	return temp;
}


int AVL::dif(node *temp)
{
	int l,r;
	l=height(temp->left);
	r=height(temp->right);
	return(l-r);
}

int AVL::height(node *temp)
{
	if(temp==NULL)
		return(-1);
	else
		return(max(height(temp->left),height(temp->right))+1);
}

int AVL::maximum(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

node* AVL::LL(node *par)
{
	node *temp,*temp1;
	temp=par->left;
	temp1=temp->right;
	temp->right=par;
	par->left=temp1;
	return temp;
}

node* AVL::RR(node *par)
{
	node *temp,*temp1;
	temp=par->right;
	temp1=temp->left;
	temp->left=par;
	par->right=temp1;
	return temp;
}

node* AVL::LR(node *par)
{
	par->left=RR(par->left);
	return(LL(par));
}

node* AVL::RL(node *par)
{
	par->right=LL(par->right);
	return(RR(par));
}

void AVL::ascending(node *temp)
{
        if(temp!=NULL)
        {
                ascending(temp->left);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                ascending(temp->right);
        }
}

void AVL::descending(node *temp)
{
        if(temp!=NULL)
        {
                descending(temp->right);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                descending(temp->left);
        }
}


void AVL::display()
{
        cout<<"\n The keywords in ascending order are : \n";
        ascending(root);
        cout<<"\n The keywords in descending order are : \n";
        descending(root);
}



int main()
{
  char c;
  int ch;
  AVL a;
  do
  {
      cout<<"*********************************";
	  cout<<"\n 1.Insert a keyword in AVL tree.";
	  cout<<"\n 2.Display the AVL tree.";
	  
	  cout<<"\n Enter your choice : ";
	  cin>>ch;
	  switch(ch)
	  {
      	  case 1 : a.create();
               break;
      	  case 2 : a.display();
               break;
      	 
      	  default : cout<<"\n Wrong choice ! ";
	  }
	  cout<<"\n Do you want to continue? (y/n): ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');
  return 0;
}
