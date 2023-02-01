#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>//for delayyy
#include <cstdlib>
#include "Record.cpp"









void main_menu()// main starting page
{
	system("cls");

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "\t\t\t\t\t\tSHALIMAAR TIMBER LIMITED. - DARGAAI,MALAKAND                              " << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "\n\t\t\t\t\t\t\t1. SHOP" << endl;
	cout << "\n\t\t\t\t\t\t\t2. RECORD" << endl;
	cout << "\n\t\t\t\t\t\t\t3. EXIT" << endl;

}




int main()
{
	
	
	order o;
	int choice;
	while (true)
	{

		
	
		main_menu();
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
				o.menu();
		}
	
		if (choice == 2)
		{
			while (true)
			{
				int cho;
				system("cls");
				cout << "\n\n\n\t>>>>>>>>>> RECORD <<<<<<<<<<<<<" << endl << endl;
				cout << "\n\t\t\t\t\t\t\t1. ORDERS" << endl;
				cout << "\n\t\t\t\t\t\t\t2. KHAATA" << endl;
				cout << "\n\t\t\t\t\t\t\t3. EXIT" << endl;
				cin>>cho;
				records r;
				r.GetUser();
				r.CompareUser();
				r.GetPass();
				r.ComparePass();
				if (cho==1)
				{
					system("cls");
					r.show_orders();
				}
				if (cho==1)
				{
					system("cls");
					break;
					
				}
				if (cho==1)
				{
					system("cls");
					break;
				}
				
				system("pause");
			
				
			}
		}
		if (choice == 3)
		{
			while (true)
			{
				system("cls");
				cout << "\n\n\n\t>>>>>>>>>> EXIT <<<<<<<<<<<<<" << endl << endl;
				
			}
		}

	}
}





