#include "Order.cpp"



class records : public order
{
private:
string UserName;
string PassCode;


public:
	records()
	{
		
	}
	
	
	void GetUser()
	{
		system("cls");
		cout << "Please Enter Your Username: ";
		cin >> UserName;
	}
	
	
	void CompareUser()
	{
		string FileUser;
	
		ifstream input;
		input.open("DefaultUser.txt");
		input >> FileUser;
		input.close();
	
		while (UserName != FileUser)
		{
			cout << "Incorrect Username. Try Again: ";
			Sleep(900);
			system("CLS");
			cout << "Please Enter Your Username: ";
			cin >> UserName;
		}
	}
	
	void GetPass()
	{
		cout << "Please Enter Your Password: ";
		cin >> PassCode;
	}
	//Comparing Input For Password With That Of File
	void ComparePass()
	{
		string FileUser, FilePass;
	
		ifstream input;
		input.open("DefaultUser.txt");
		input >> FileUser >> FilePass;
		input.close();
	
		while (PassCode != FilePass)
		{
			cout << "Incorrect Password. Try Again: ";
			cin >> PassCode;
		}
	
		cout << endl << "Username And Password Verified. Logging In, Please Wait: ";
		cout << endl;
		Sleep(1000);
		cout << "Login Successful";
		cout << endl;
		Sleep(900);
		system("CLS");
	}
	
	void show_orders()
	{
		ifstream read;
		read.open("torder.txt");
		cout << "\n\n\n\t>>>>>>>>>> WOOD/TIMBER ORDERS <<<<<<<<<<<<<" << endl << endl;
		cout<<"TYPE"<< "\t\tQUANTITY"<<"\t\tTRACKING NUMBER"<<"\t\tPRICE"<<endl;
//		bt.inorder(bt.getroot());

		string line;
		int i=0;
		while(getline(read, line)){
			cout<<line<<"\t\t\t";
			i++;
			
			if(i == 4){
				cout<<endl;
				i=0;
			}
		}
		ifstream read2;
		read2.open("forder.txt");
		
			cout << "\n\n\n\t>>>>>>>>>> FURNITURE ORDERS <<<<<<<<<<<<<" << endl << endl;
		cout<<"TYPE"<< "\t\tQUANTITY"<<"\t\tTRACKING NUMBER"<<"\t\tPRICE"<<endl;
//		bt2.inorder(bt2.getroot());

//		line;
		i=0;
		while(getline(read2, line)){
			cout<<line<<"\t\t\t";
			i++;
			
			if(i == 4){
				cout<<endl;
				i=0;
			}
		}
		
	}
	
	

	

};

