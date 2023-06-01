/* Beginning with an empty binary search tree, Construct binary search tree by inserting the 
values in the order given. After constructing a binary tree -
i. Insert new node 
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree 
iv. Change a tree so that the roles of the left and right pointers are swapped at every 
node 
v. Search a value */

#include<iostream>
using namespace std;
class node
{
     public:
     	int data;
     	node *left;
     	node *right;
};
class bst
{

public:
		node *root;
	bst() 
	{
		root=NULL; 
	}
	void create();
	void insert();
	void postorder(node*);
	void inorder(node *);
        void preorder(node *);
       
};



			
void bst::create()
{
	node *curr,*temp;
	int ans=1;
	cout<<"enter data:";
	do
	{
		curr=new node;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data<=temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"want to continue:";
		cin>>ans;
	}while(ans==1);
}
void bst::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}
void bst::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<"  "<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void bst::postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->data;
	}
}
void bst::insert()
{
	node *curr,*temp;
	int ans=1;
	cout<<"enter data:";
	
	
		curr=new node;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data<=temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}//end of while
		}
}




int main()
{
	bst b;
	int key,ch;
	do
	{
		cout<<"\n1.create\n2.insert\n3.inorder\n4.preorder\n5.postorder\npress 0 to exit\n";
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:b.create();
				break;
			case 2:b.insert();
				break;
			case 3:cout<<"inorder traversal is\n";
					b.inorder(b.root); 
					break;
			case 4:cout<<"preorder traversal is\n";
					b.preorder(b.root);
					break;
			case 5:cout<<"postorder traversal is\n";
					b.postorder(b.root);
					break;
			
		}
	}while(ch!=0);
	return 0;
}
