#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Shopping {
private:
	int pcode;
	float price;
	float discount;
	string pname;

public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void remove();
	void list();
	void receipt();

};

void Shopping:: menu() {

	m:
	int choice=0;
	string email;
	string password;

	cout << "\t\t\t\t________________________________________________________\n";
	cout << "\t\t\t\t                                                        \n";
	cout << "\t\t\t\t					Supermasket Main menu                \n";
	cout << "\t\t\t\t                                                        \n";
	cout << "\t\t\t\t________________________________________________________\n";
	cout << "\t\t\t\t                                                        \n";
	cout << "\t\t\t\t| 1. Administrator           \n";
	cout << "\t\t\t\t|                            \n";
	cout << "\t\t\t\t| 2. Buyer                   \n";
	cout << "\t\t\t\t|						      \n";
	cout << "\t\t\t\t| 3. Exit                    \n";
	cout << "\t\t\t\t|                            \n";
	cout << "\t\t\t\t Please Select Option:       \n";

	switch (choice)
	{
	case 1:
		cout << "\t\t\t\t Please Login \n";
		cout << "\t\t\t\t Enter Email   \n";
		cin >> email;
		cout << "\t\t\t\t Enter Password   \n";
		cin >> password;


		if (email == "nndurere32@gmail.com && password== 12345")
		{
			administrator();
		}
		else
			break;


	case 2:
		{
			buyer();

		}
		case 3:
		{
			exit(0);
		}
	default:
		{
			cout << "Please select from the given options";
		}
	}
	goto m;
}




void Shopping::administrator() {
	m:
	int choice;
	cout << "\n\n\n\t\t\tAdministrator menu";
	cout << "\n\t\t\t|___________1. Add the product     ";
	cout << "\n\t\t\t|                                  ";
	cout << "\n\t\t\t|___________2. Modify the product  ";
	cout << "\n\t\t\t|                                  ";
	cout << "\n\t\t\t|___________3. Delete the product  ";
	cout << "\n\t\t\t|                                   ";
	cout << "\n\t\t\t|___________4. Back to main menu   ";

	cout << "\n\n\t Please Enter your choice";
	cin >> choice;

	switch (choice) 
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		remove();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "Invalid choice entered";
	}
	goto m;
}


void Shopping::buyer() 
{
	m:
	int choice;
	cout << "\t\t\t    Buyer           \n";
	cout << "\t\t\t______________      \n";
	cout << "                          \n";
	cout << "\t\t\t 1. Buy product	   \n";
	cout << "                          \n";
	cout << "\t\t\t 2. Go Back         \n";
	cout << "\t\t\t Enter your choice: ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		receipt();
		break;
	case 2:
		menu();
		break;
	default:
		cout << "Invalid choice entered";

	}
	goto m;

}


void Shopping::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;


	cout << "\n\n\t\t\t Add new product  ";
	cout << "\n\n\t Product code ";
	cin >> pcode;
	cout << "\n\n Name of product ";
	cin >> pname;
	cout << "\n\n\t Price of the product";
	cin >> price;
	cout << "\n\n\t Discount on the product";
	cin >> discount;
	
	data.open("database.txt", ios::in);

	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
		data.close();

	}
	else
		data >> c >> n >> p >> d;
	while (!data.eof())
	{
		if (c == pcode)
		{
			token++;
		}
		data >> c >> n >> p >> d;

	}
	data.close();



	if (token == 1)
		goto m;
	else
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
		data.close();
	}

	cout << "\n\n\t\t Record Inserted";




}

void Shopping::edit()
{
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;

	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Enter the product code:";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n File is non-existent!";

	}
	else {
		data1.open("database.txt", ios::app | ios::in);

		data >> pcode >> pname >> price >> discount;
		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\n\t\t Product new code:";
				cin >> c;
				cout << "\n\t\t Name the product:";
				cin >> pname;
				cout << "\n\t\t Price:";
				cin >> p;
				cout << "\n\t\t Discount: ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record edited";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";

			}
			data >> pcode >> pname >> price >> discount;

		}
		data.close();
		data1.close();

		remove();
		//remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found1";
		};

	};

}

void Shopping::remove()
{
	fstream data, data1;
	int pkey;
	int token=0;

	cout << "\n\n\t  Delete product";
	cout << "\n\n\tEnter the product code:";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "File doesn't exist";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::in);
		data >> pcode >> pname >> price >> discount;
		while (!data.eof())
		{
			if (pcode == pkey)
			{
				cout << "\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
			}
			data >> pcode >> pname >> price >> discount;
		}
		data.close();
		data1.close();
		remove();
		//remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found";

		}
	}
}


void Shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n_______________________________________________________________________\n";
	cout << "ProNo\t\tName\t\tPrice\n";
	cout << "\n\n_______________________________________________________________________\n";
	data >> pcode >> pname >> price >> discount;

	while (!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> discount;

	}
	data.close();

}

void Shopping::receipt()
{
	m:
	fstream data;
	int arrc[100];
	int arrq[100];
	string choice;
	int c = 0;
	float amount = 0;
	float discount = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t Receipt";
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout << "\n__________________________________________________________________________\n";
		cout << "\n 																		 \n";
		cout<<"\n 						Please place the order								 \n";
		cout << "\n 																		 \n";
		cout << "\n__________________________________________________________________________\n";
		do
		{
			cout << "\n\n Enter product code:";
			cin >> arrc[c];
			cout << "\n\n Enter the quantity: ";
			cin >> arrq[c];
			for (int i = 0; i < c;i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to enter another product? If yes then pres y else n:";
			cin >> choice;

		} while (choice == "y");
			cout << "\n\n\t\t\t_______________________Receipt_____________________________________\n";
			cout << "\n Product No\t Product Name\t Product Quantity\t Price\t Amount\t Amount After Discount\n";
		for (int i = 0;i < c;i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> discount;
			while (!data.eof())
			{
				if (pcode = arrc[i])
				{
					amount = price * arrq[i];
					discount = amount - (amount * discount / 100);
					total = total + discount;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << price << "\t\t" << amount << "\t\t" << discount;

				}
				data >> pcode >> pname >> price >> discount;
			}
			data.close();

		}
		cout << "\n\n_______________________________________________________________";
		cout << "\n Total Amount:" << total;

	}
}


int main() 
{
	Shopping s;
	s.menu();
	


}
