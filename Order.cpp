#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>//for delayyy
#include <cstdlib>
#include "doublyll.cpp"
#include "BST.cpp"
#include <stdlib.h>
Doubly_Linked_List dll;
Doubly_Linked_List dll2;
BST bt;
BST bt2;

class timber
{
	public:
		string item[100];
		timber()
		{
			ifstream myFileStream("timber.txt" ,ios::in);
			if(!myFileStream.is_open())
			{
				cout<<"Failed to open the file"<<endl;
				return;
			}
			
			int i=0;
			while(!myFileStream.eof())	
			{
				getline(myFileStream,item[i]);
				dll.add_end(item[i]);	
			}
			myFileStream.close();
			
			ifstream myFileStream2("torder.txt" ,ios::in);
			if(!myFileStream2.is_open())
			{
				cout<<"Failed to open the file"<<endl;
				return;
			}
			
			i=0;
			while(!myFileStream2.eof())	
			{
				string a;
				string b;
				string c;
				string d;
				getline(myFileStream2,a);
				getline(myFileStream2,b);
				getline(myFileStream2, c);
				getline(myFileStream2,d);
				bt.insert(a,b,c,d);
				
			}
			myFileStream2.close();	
			
			
			
		}
	
	void Tshow_avalible()
	{
		dll.forward_traverse();
		system("pause");	
		
	}
	string orders[50];
	int amm[50];
	string cnic[51];
	int price;
	int pbill[51];
	
	
	void Tnew_order()
	{
			for(int j=0;j<1;j++)
		{
			
			ofstream file2("torder.txt",ios::app);
			int s=0;
			cout<<"How many type of items do you want to order ??"<<endl;
			cin>>s;
			
		
			
		for(int i=1;i<=s;i++)
		{
			int trac=0;
			cout<<"\nEnter the order for type "<<i<<endl<<endl;
			cout<<"Enter name ";
			cin>>orders[i];
			cout<<"Enter ammount ";
			cin>>amm[i];
			
			file2<<orders[i]<<endl;
			file2<<amm[i]<<endl;
				trac=rand()%1000000+1;
				
				file2<<trac<<endl;
				price=rand()%100+1;
				pbill[i]=price*amm[i];
				file2<<pbill[i]<<endl;
			
			cout<<trac<<"is your tracking  numberr for this product. please remember it "<<endl;
			
			
		}
		file2.close();
		system("pause");
			
	}
		
}
	
	

	
	
	void Ttrack_order()
	{
		string co;
		cout<<"enter your tracking number : ";
		cin>>co;
		bt.search(bt.getroot(),co);
		system("pause");
	}
	
};

class furniture
{
	public:	
		string item2[100];
		
	furniture()
	{
		ifstream myFileStream("furniture.txt" ,ios::in);
			if(!myFileStream.is_open())
			{
				cout<<"Failed to open the file"<<endl;
				return;
			}
			
			int i=0;
			while(!myFileStream.eof())	
			{
				getline(myFileStream,item2[i]);
				dll2.add_end(item2[i]);	
			}
			myFileStream.close();
			
			ifstream myFileStream2("forder.txt" ,ios::in);
			if(!myFileStream2.is_open())
			{
				cout<<"Failed to open the file"<<endl;
				return;
			}
			
			i=0;
			while(!myFileStream2.eof())	
			{
				string a;
				string b;
				string c;
				string d;
				getline(myFileStream2,a);
				getline(myFileStream2,b);
				getline(myFileStream2, c);
				getline(myFileStream2,d);
				bt2.insert(a,b,c,d);
				
			}
			myFileStream2.close();	
			
			
	}
	void Fshow_avalible()
	{
		ifstream myFileStream("furniture.txt" ,ios::in);
		if(!myFileStream.is_open())
		{
			cout<<"Failed to open the file"<<endl;
			return;
		}
		
		int i=0;
		while(!myFileStream.eof())	
		{
			getline(myFileStream,item2[i]);
			dll2.add_end(item2[i]);	
		}
		myFileStream.close();
		dll2.forward_traverse();
	}
		string orders[50];
	int amm[50];
	string cnic[51];
	int price;
	int pbill[51];
	
	
	void Fnew_order()
	{
			for(int j=0;j<1;j++)
		{
			int trac=0;
			ofstream file2("forder.txt",ios::app);
			int s=0;
			cout<<"How many type of items do you want to order ??"<<endl;
			cin>>s;
			
		
			
		for(int i=1;i<=s;i++)
		{
			cout<<"\nEnter the order for type "<<i<<endl<<endl;
			cout<<"Enter name ";
			cin>>orders[i];
			cout<<"Enter ammount ";
			cin>>amm[i];
			
			file2<<orders[i]<<endl;
			file2<<amm[i]<<endl;
				trac=rand()%1000000+1;
				
				file2<<trac<<endl;
				price=rand()%100+1;
				pbill[i]=price*amm[i];
				file2<<pbill[i]<<endl;
			
			cout<<trac<<"is your tracking  numberr for this product. please remember it "<<endl;
		}
		file2.close();
		system("pause");
	}
			
	}
	
	void Ftrack_order()
	{
			string co;
		cout<<"enter your tracking number : ";
		cin>> co;
		bt.search(bt2.getroot(),co);
		system("pause");
	}
	
	
};



class order : public timber,furniture
{
	public:
		void menu()
		{
			while(true)
			{
			
				int choice2;
					system("cls");
					cout << "\n\t\t\t\t\t\t>>>>>>>>>> SHOP <<<<<<<<<<<<<" << endl << endl;
					cout << "\n\t\t\t\t\t\t\t1. TIMBER" << endl;
					cout << "\n\t\t\t\t\t\t\t2. FURNITURE" << endl;
					cout << "\n\t\t\t\t\t\t\t3. BACK TO MAIN MENU" << endl<< endl;
					cin>>choice2;
					
					if(choice2==1)
					{
						while (true)
						{
							int choice3;
							system("cls");
							cout << "\n\t\t\t\t\t\t\t>>>>>>>>>> TIMBER <<<<<<<<<<<<<" << endl << endl;
							cout << "\n\t\t\t\t\t\t\t1. SHOW AVALIBLE" << endl;
							cout << "\n\t\t\t\t\t\t\t2. NEW ORDER" << endl;
							cout << "\n\t\t\t\t\t\t\t3. TRACK ORDER" <<  endl;
							cout << "\n\t\t\t\t\t\t\t4. BACK TO PREVIOUS MENU" << endl<< endl;
							cin>>choice3;
							if(choice3==1)
							{
								system("cls");
								Tshow_avalible();
							}
							if(choice3==2)
							{
								system("cls");
								Tnew_order();
							}
							if(choice3==3)
							{
								system("cls");
								Ttrack_order();
							}
							else
							{
								break;
							}
			
						}
					}
					else if(choice2==2)
					{
						while (true)
						{
							int choice4;
							system("cls");
							cout << "\n\n\n\t>>>>>>>>>> FURNITURE <<<<<<<<<<<<<" << endl << endl;
							cout << "\n\t\t\t\t\t\t\t1. SHOW AVALIBLE" << endl;
							cout << "\n\t\t\t\t\t\t\t2. NEW ORDER" << endl;
							cout << "\n\t\t\t\t\t\t\t3. TRACK ORDER" <<  endl;
							cout << "\n\t\t\t\t\t\t\t4. BACK TO PREVIOUS MENU" << endl<< endl;
							cin>>choice4;
							if(choice4==1)
							{
								system("cls");
								Fshow_avalible();
							}
							if(choice4==2)
							{
								system("cls");
								Fnew_order();
							}
							if(choice4==3)
							{
								system("cls");
								Ftrack_order();
								
							}
							else
							{
								break;
							}
						}
					}
					else
					{
						break;
					}
			}
		}
		
	
};


