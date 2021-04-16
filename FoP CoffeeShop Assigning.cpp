/*--------------------------------------------------------------------------------------------------------------------
FOP Project _ Coffee Shop Inventory Management System                                                              
Programmers: Aiya Alchaar - Rahaf Jaber - Samar Qassem                                                             
Program Purpose: This is a program used by the management of a coffee shop to record product and Suppliers details.

NOTE: To access this program:
		Username: fop
		Password: fop
---------------------------------------------------------------------------------------------------------------------*/

#include <iostream>		//For input and output stream
#include <string>		//For using String function
#include <ctime>		//For getting current time and date
#include <conio.h>		//For hiding the password while entering it
#include <windows.h>	// For Sleep function
using namespace std;

//Product Declarations 
struct product 
{
	int ID;
	float price;
	string name;
	string type;
};
int prodCtr=0;
product product[100];

//Supplier Declarations 
struct supplier
{
	int ID;
	string name;
	string phone;	
};
int supCtr=0;
supplier supplier[50];

string assignedSupplier[100]; //Array used to link suppliers and products by Assigning Products to Suppliers

//functions Prototypes
void startingInterface();
void listingOptions();
void addProduct();
void addSupplier();
void updateProduct();
void updateSupplier();
void deleteProduct();
void deleteSupplier();
void listProducts();
void listSuppliers();
void assignSupplier();
void UpdateAssignSupplier(int);
void searchSupplier();
void searchProduct();



int main()
{
	system("color 5F");
	startingInterface();
		
	int option, repeat=1;
	do 
	{
		listingOptions();
		
		cout << endl << endl << "Enter the number of the service that you want to carry out:" << endl;
		cin >> option;
		
		switch (option)
		{
			case 1:
				addProduct();
				break;
				
			case 2:
				int repeatAdd;
				do
				{
					addSupplier();	
					cout << "Do you want to add another supplier?  <1-Yes ... 2-No>" << endl;
					cin >> repeatAdd;
					
				}while (repeatAdd==1);
				if (repeatAdd>2 || repeatAdd <1)
					cout << "Invalid Input!" << endl;
				break;
				
			case 3:
				updateProduct();
				break;
				
			case 4:
				updateSupplier();
				break;
				
			case 5:
				deleteProduct();
				break;
				
			case 6:
				deleteSupplier();
				break;
				
			case 7:
				listProducts();
				break;
				
			case 8:
				listSuppliers();
				break;
				
			case 9:
				searchProduct();
				break;
				
			case 10:
				searchSupplier();
				break;
				
			default:
				cout << "Invalid Input!";
		}
		
		cout << "\n\nDo you want to carry out another service?  <1-Yes ... 2-Exit the program>" << endl;
		cin >> repeat;
		
		
	}while(repeat==1);
	return 0;
}



void startingInterface()
{
	cout << "\n\t\t\tлллллл лллл  ллллл     ллллл  ллллл   лллл       л лллллл  лллл  ллллллл" << endl;
	cout << "\t\t\tл     л    л л    л    л    л л    л л    л      л л      л    л    л"<< endl;
	cout << "\t\t\tллллл л    л л    л    л    л л    л л    л      л ллллл  л         л" << endl;
	cout << "\t\t\tл     л    л ллллл     ллллл  ллллл  л    л      л л      л         л" << endl;
	cout << "\t\t\tл     л    л л         л      л   л  л    л л    л л      л    л    л" << endl;
	cout << "\t\t\tл      лллл  л         л      л    л  лллл   лллл  лллллл  лллл     л" << endl;
	cout << "\n\t\t***************************************************************************************\n\n";
	
	cout << "\t\t\t лллл   лллл  лллллл лллллл лллллл лллллл     лллл  л    л  лллл  ллллл " << endl;
	cout << "\t\t\tл    л л    л л      л      л      л         л      л    л л    л л    л"<< endl;
	cout << "\t\t\tл      л    л ллллл  ллллл  ллллл  ллллл      лллл  лллллл л    л л    л" << endl;
	cout << "\t\t\tл      л    л л      л      л      л              л л    л л    л ллллл " << endl;
	cout << "\t\t\tл    л л    л л      л      л      л         л    л л    л л    л л " << endl;
	cout << "\t\t\t лллл   лллл  л      л      лллллл лллллл     лллл  л    л  лллл  л" << endl;
	cout << "\n\t\t***************************************************************************************\n\n";

	time_t now;	
	time (&now);
	cout << "\n\t\t\t\t Current Date & Time is: "<<ctime(&now) << endl << endl;
	
	string username, pass ="";
	cout << "\t\tPlease enter the username and Password to login to the coffee shop's management system:"<< endl;
	cout << "\n\t\t\tUsername: ";
	cin >> username;
	cout << "\n\t\t\tPassword: ";
	char ch=_getch();
	while (ch!=13) //character 13 is enter 
	{
		pass.push_back(ch);
		cout << '*';
		ch=_getch();
	}
	
	if (username=="fop" && pass=="fop")
	{
		cout << "\n\n\t\t\tAccess Granted.." << endl;
	}
	else 
	{
		int retry;
		cout << "\n\n\t\t\tUsername or Password incorrect!" << "\n\t\t\tEnter '1' to retry or '2' to exit the program..\n";
		cin >> retry;
		if (retry == 1)
		{
			system ("cls");
			startingInterface();
		}
		else 
			exit(0);
	}

	cout <<"\n\n\n\t\t\t\tPlease wait while loading\n\n";
 	char a=177, b=219;
 	cout<<"\t\t\t\t\t\t\t";
 	for (int i=0;i<=25;i++)
 		cout<<a;
 	cout<<"\r";
 	cout<<"\t\t\t\t\t\t\t";
 	for (int i=25;i>=0;i--)
 	{
  		cout<<b;
  		Sleep(i*10);
 	}
 	cout << endl;
	Sleep (250);	
}

void listingOptions()
{
	system("cls");
	cout << "1) Adding a new Product\t\t\t\t2) Adding a new Supplier" << endl;
	cout << "3) Updating a Product\t\t\t\t4) Updating a Supplier" << endl;
	cout << "5) Deleting a Product\t\t\t\t6) Deleting a Supplier" << endl;
	cout << "7) Listing all Products\t\t\t\t8) Listing all Suppliers" << endl;
	cout << "9) Searching a Product Details\t\t\t10) Searching a Supplier Details" << endl;

}

void addProduct()
{
	int repeat;
	system("cls");
	cout << "Enter the Name of the product: ";
	cin >> product[prodCtr].name;
	cout << "\n\nEnter the Price of the product: ";
	cin >> product[prodCtr].price;
	cout << "\n\nEnter the Type of the product: ";
	cin >> product[prodCtr].type;
	cout << "\n\nEnter the ID of the product: ";
	cin >> product[prodCtr].ID;
	assignSupplier();
	
	cout <<"\n\n\n\t\tProduct Added Successfully.." << endl << endl;
	
	prodCtr++;
	
	cout << "Do you want to add another product?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		addProduct();
	else if (repeat!=2)
		cout << "Invalid input! ";
}

void addSupplier()
{	 
	system("cls");
	cout << "Enter the Name of the Supplier: ";
	cin >> supplier[supCtr].name;
	cout << "\n\nEnter the ID of the Supplier: ";
	cin >> supplier[supCtr].ID;
	cout << "\n\nEnter the Phone of the Supplier: ";
	cin >> supplier[supCtr].phone;
	
	cout <<"\n\n\n\t\tSupplier Added Successfully.." << endl << endl;
	
	supCtr++;
}

void updateProduct()
{
	system("cls");
	string name;
	int update, z=-1, repeat;
	cout << "Enter the Name of the product that you want to update: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<prodCtr; i++)
	{
		if (name == product[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		cout << "\nWhich of the following do you want to update?" << endl;
		cout << "< 1-Name  2-Price  3-Type  4-ID 5-Supplier >\n\n";
		cin >> update;
		switch (update)
			{
				case 1:
					cout << "Updated Name:  ";
					cin >> product[z].name;
					break;
				case 2:
					cout << "Updated Price:  ";
					cin >> product[z].price;
					break;
				case 3:
					cout << "Updated Type:  ";
					cin >> product[z].type;
					break;
				case 4:
					cout << "Updated ID:  ";
					cin >> product[z].ID;
					break;
				case 5:
					UpdateAssignSupplier(z);
					break;
				default:
					cout << "Invalid Input!" << endl << endl;
			}
	}
	else 
		cout << "Product Name invalid!" << endl << endl;
		
	cout << "Do you want to update another product?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		updateProduct();
	else if (repeat!=2)
		cout << "Invalid input! ";
	
}

void updateSupplier()
{
	system("cls");
	string name;
	int update, z=-1, repeat;
	cout << "Enter the Name of the Supplier that you want to update: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;

	
	for (int i=0; i<supCtr; i++)
	{
		if (name == supplier[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		cout << "\nWhich of the following do you want to update?" << endl;
		cout << "< 1-Name  2-Phone  3-ID >\n\n";
		cin >> update;
		switch (update)
			{
				case 1:
					cout << "Updated Name:  ";
					cin >> supplier[z].name;
					for (int i=0; i<prodCtr; i++)
					{
						if (assignedSupplier[i]==name)
						{
							assignedSupplier[i]=supplier[z].name;
						}
					}
					break;
				case 2:
					cout << "Updated Phone Number:  ";
					cin >> supplier[z].phone;
					break;
				case 3:
					cout << "Updated ID:  ";
					cin >> supplier[z].ID;
					break;
				default:
					cout << "Invalid Input!" << endl << endl;
			}	
	}
	else 
		cout << "Supplier Name invalid!" << endl << endl;
		
	cout << "Do you want to update another supplier?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		updateSupplier();
	else if (repeat!=2)
		cout << "Invalid input! ";
}

void listProducts()
{
	system("cls");
	cout << "Product Name\tProduct Price\t   Product Type\t   Product ID\tAssigned Supplier\n";
	cout << "--------------------------------------------------------------------------------------------" << endl;

	for (int i=0; i<prodCtr; i++)
		cout << product[i].name << "\t\t\t" << product[i].price << "\t\t" << product[i].type << "\t\t" << product[i].ID << "\t\t" << assignedSupplier[i] <<endl;
}

void listSuppliers()
{
	system("cls");
	cout << "Supplier Name\t\t\tSupplier Phone\t\t\tSupplier ID\n";
	cout << "--------------------------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<supCtr; i++)
	{
		cout << supplier[i].name << "\t\t\t\t" << supplier[i].phone << "\t\t\t" << supplier[i].ID << endl;
		cout << "Product:\n";
		for (int j=0; j<prodCtr; j++)
		{
			if (assignedSupplier[j]==supplier[i].name)
				cout << product[j].name << ", ";
		}
		cout << endl << endl << endl;
	}
}

void deleteProduct()
{
	system("cls");
	string name;
	int z=-1, repeat;
	cout << "Enter the Name of the product that you want to delete: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<prodCtr; i++)
	{
		if (name == product[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		for (int i=z; i<prodCtr; i++)
		{
			product[i].name=product[i+1].name;
			product[i].type=product[i+1].type;
			product[i].price=product[i+1].price;
			product[i].ID=product[i+1].ID;
			
			assignedSupplier[i]=assignedSupplier[i+1];

		}
		cout <<"\n\n\n\t\tProduct Deleted Successfully.." << endl << endl;

		prodCtr--;
	}
	else 
		cout << "Product Name is Invalid! " << endl << endl;
		
	cout << "Do you want to delete another product?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		deleteProduct();
	else if (repeat!=2)
		cout << "Invalid input! ";
}

void deleteSupplier()
{
	system("cls");
	string name;
	int z=-1, repeat;
	cout << "Enter the Name of the Supplier that you want to delete: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<supCtr; i++)
	{
		if (name == supplier[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		for (int i=z; i<supCtr; i++)
		{
			supplier[i].name=supplier[i+1].name;
			supplier[i].phone=supplier[i+1].phone;
			supplier[i].ID=supplier[i+1].ID;
		}
		
		for (int j=0; j<prodCtr; j++)
		{
			if (name==assignedSupplier[j])
			{
				for (int i=j; i<prodCtr; i++)
				{
					product[i].name=product[i+1].name;
					product[i].type=product[i+1].type;
					product[i].price=product[i+1].price;
					product[i].ID=product[i+1].ID;
			
					assignedSupplier[i]=assignedSupplier[i+1];	
				}
				prodCtr--;
				j--;
			}
		}
		
		cout <<"\n\n\n\t\tSupplier Deleted Successfully.." << endl << endl;

		supCtr--;
	}
	else 
		cout << "Supplier Name is Invalid! " << endl << endl;
		
	
	cout << "Do you want to delete another supplier?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		deleteSupplier();
	else if (repeat!=2)
		cout << "Invalid input! ";
	
}

void assignSupplier()
{	
	int choice;

	cout << "\n\nSuppliers: " << endl;
	for (int i=0; i<=supCtr; i++)
	{
		if (i==supCtr)
		{
			cout << i+1 << "- " << "Assign to a new supplier\n";
		}
		else 
			cout << i+1 << "- "<< supplier[i].name << endl;	
	}
	
	cout << "Enter the number of the supplier that you want to assign to this product: ";
	cin >> choice;
	
	if (choice>supCtr+1 || choice<=0)
	{
		cout << "Invalid Input!" << endl;
		assignSupplier();
	}
	else if (choice==supCtr+1)
	{
		addSupplier();
		assignedSupplier[prodCtr]=supplier[supCtr-1].name;
	}
		else
			assignedSupplier[prodCtr]=supplier[choice-1].name;	
}


void UpdateAssignSupplier(int z)
{	
	int choice;

	cout << "\n\nSuppliers: " << endl;
	for (int i=0; i<=supCtr; i++)
	{
		if (i==supCtr)
		{
			cout << i+1 << "- " << "Assign to a new supplier\n";
		}
		else 
			cout << i+1 << "- "<< supplier[i].name << endl;	
	}
	
	cout << "Enter the number of the supplier that you want to assign to this product: ";
	cin >> choice;
	
	if (choice>supCtr+1 || choice<=0)
	{
		cout << "Invalid Input!" << endl;
		assignSupplier();
	}
	else if (choice==supCtr+1)
	{
		addSupplier();
		assignedSupplier[z]=supplier[supCtr-1].name;
	}
		else
			assignedSupplier[z]=supplier[choice-1].name;		
}

void searchSupplier()
{
	system("cls");
	
	string name;
	int z=-1, repeat;
	cout << "Enter the Name of the Supplier that you want to dispaly: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<supCtr; i++)
	{
		if (name == supplier[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		cout << "\nSupplier Name\t\t\tSupplier Phone\t\t\tSupplier ID\n\n";
		cout << "----------------------------------------------------------------------------" << endl;
		cout << supplier[z].name << "\t\t\t" << supplier[z].phone << "\t\t\t" << supplier[z].ID << endl;
			
		cout << "Product Assigned from this Supplier:\n";
		for (int j=0; j<prodCtr; j++)
		{
			if (assignedSupplier[j]==name)
					cout << product[j].name << ", ";
		}
		cout << endl << endl;
			
	}
	else
		cout << "Supplier Name invalid!" << endl << endl;
		
	cout << "Do you want to search another supplier?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		searchSupplier();
	else if (repeat!=2)
		cout << "Invalid input! ";
	
}

void searchProduct()
{
	system("cls");
	
	string name;
	int z=-1, repeat;
	cout << "Enter the Name of the product that you want to dispaly: " << endl;
	cin >> name;
	cout << "----------------------------------------------------------------------------" << endl;
	
	for (int i=0; i<prodCtr; i++)
	{
		if (name == product[i].name)
		{
			z=i;
			break;
		}
	}
	if (z>-1)
	{
		cout << "\nProduct Name\t\tProduct Price\tProduct Type\tProduct ID\tAssigned Supplier\n\n";
	
		cout << product[z].name << "\t\t\t" << product[z].price << "\t\t" << product[z].type << "\t\t" << product[z].ID << "\t\t" << assignedSupplier[z] <<endl;
	}
	else 
		cout << "Product Name invalid!" << endl << endl;
		
	cout << "Do you want to search another product?  <1-Yes ... 2-No>" << endl;
	cin >> repeat;
	if (repeat==1)
		searchProduct();
	else if (repeat!=2)
		cout << "Invalid input! ";
}




