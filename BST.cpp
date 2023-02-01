#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>//for delayyy
#include <cstdlib>

using namespace std;


class node{
	public:
		string data;
		string amount;
		string cnic;
		string pbill;
		
		node *left;
		node *right;
		node()
		{
			data="";
			amount="";
			cnic="";
			pbill="";
			left=NULL;
			right=NULL;
		}
		node(string d, string a, string c, string pb)
		{
			data=d;
			amount=a;
			cnic=c;
			pbill=pb;
			left=NULL;
			right=NULL;
		}
};

bool isleaf(node *temp)
{
	if(temp->left==NULL&&temp->right==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

class BST{
	node *root;
	public:
		BST()
		{
			root=NULL;
		}
		void insert(string d, string a, string c, string pb)
		{
			if(root==NULL)
			{
				root=new node(d,a,c,pb);
				return;
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(c<current->cnic)
					{
						if(current->left==NULL)
						{
							current->left=new node(d,a,c,pb);
						}
						else
						{
							current=current->left;
						}
					}
					else if(c>current->cnic)
					{
						if(current->right==NULL)
						{
							current->right=new node(d,a,c,pb);
						}
						else
						{
							current=current->right;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		node *getminvaluenode(node *n)
		{
			if(n==NULL)
			{
				return n;
			}
			while(n->left!=NULL)
			{
				n=n->left;
			}
			return n;
		}
	
		void inorder(node *r)
		{
		
			if(r==NULL)
			{
				return;
			}
			inorder(r->left);
			
			cout<<r->data<<"\t\t"<<r->amount<<"\t\t"<<r->cnic<<"\t\t"<<r->pbill<<endl;
			inorder(r->right);
		}
		node *getroot()
		{
			return root;
		}
		
		void setroot(node *r)
		{
			this->root=r;
		}
		
		node* searchhelper(node* root, string c)
		{
		    // Base Cases: root is null or key is present at root
		    if (root == NULL || root->cnic == c)
		       return root;
		   
		    // Key is greater than root's key
		    if (root->cnic < c)
		       return searchhelper(root->right, c);
		
		    // Key is smaller than root's key
		    return searchhelper(root->left, c);
		    
		   
		}
		
		void search(node* root, string c){
			inorder(searchhelper(root, c));
		}
		
};




