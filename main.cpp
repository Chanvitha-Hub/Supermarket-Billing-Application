#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Devlare variables
	const int itemOne = 750, itemTwo = 375;
	const float VATPercentage = 0.05; 
	float grandTotal, discountPercentage, discount, VAT, finalPrice, payAmount;
	char cashPayment, memberCard;
	int cardNumber, rewardPoints, availablePoints=100, currentPoints, temporaryQuantityOne, temporaryQuantityTwo, itemQuantity;
	cout << setprecision(2) << fixed;
		
	cout << "**********************************************************************" << endl; // Welcome tag
	cout << "\t\tWelcome To CoolMart Supermarket !\n" << endl;
	
	//Get cashier inputs about quantities
	cout << "Enter number of 'Item One quantity' : ";
	cin >> temporaryQuantityOne;
	cout << "Enter number of 'Item Two quantity' : ";
	cin >> temporaryQuantityTwo;
	
	// Display the list and quantities of bought items
	cout << "\n* Here is the List of items.\n";
	cout << "\t Item One = Rs.750.00 x " << temporaryQuantityOne << endl;
	cout << "\t Item Two = Rs.375.00 x " << temporaryQuantityTwo << endl;
	
	// Processing equations
	itemQuantity = temporaryQuantityOne+temporaryQuantityTwo; // Temporary quantity means the corresponding quantity of each item 
	grandTotal = (itemOne*temporaryQuantityOne+itemTwo*temporaryQuantityTwo);
	
	// Declare the discount limits
	if(grandTotal>=50000)
	{
		discountPercentage=2.5/100;
	}else if(grandTotal>=37500)
	{
		discountPercentage=2.0/100;
	}else if(grandTotal>=25000)
	{
		discountPercentage=1.75/100;
	}else if(grandTotal>=10000)
	{
		discountPercentage=1.25/100;
	}else
	{
		discountPercentage=0;
	}
	
	// Asking from customer whether has a store membership card or not
	cout << "\nIs there any CoolMart Membership card? (Press 'Y' or 'N') : ";
	cin >> memberCard; // Cashier should press euither 'Y' or 'N'
	
	if(memberCard=='Y' || memberCard=='y') // If customer has a member card execute this
	{	
		// Ask customer details
		cout << "Enter the card number: ";
		cin >> cardNumber;
		cout << "\tName\t\t : xxxx xxxx \n\tAddress\t\t : xxxx xxxx \n\tAvailable Points : 100" << endl;	
		
		cout << "\nPay by Cash? (Press 'Y' or 'N') : ";
		cin >> cashPayment;
		cout << "Enter customer given value : ";
		cin >> payAmount; // Pay Amount = The amount that given by the cunstomer at that moment
		
		// Point declare equations
		rewardPoints = grandTotal/100;
		currentPoints = availablePoints + rewardPoints;
		
		if(itemQuantity<50) // If number of quantity less than 50 execute this
		{
			if(cashPayment=='Y' || cashPayment=='y')
			{
				cout << "\n*Reward Points were added. Now you have " << currentPoints+1 << " points." << endl;	
			}
			else if(cashPayment=='N' || cashPayment=='n')
			{
				cout << "\n*Reward Points were added. Now you have " << currentPoints << " points." << endl;	
			}		
		}
		else if(itemQuantity>50) // If number of quantity higher than 50 execute this
		{
			if(cashPayment=='Y' || cashPayment=='y')
			{
				cout << "\n*Reward Points were added. Now you have " << currentPoints+2 << " points." << endl;	
			}
			else if(cashPayment=='N' || cashPayment=='n')
			{
				cout << "\n*Reward Points were added. Now you have " << currentPoints+1 << " points." << endl;	
			}
		}	
	}else if(memberCard=='N' || memberCard=='n') // If customer has not a member card execute this
	{
		cout << "Customer does not have a membership card. You can request a card." << endl;
		cout << "\nPay by cash? (Press 'Y' or 'N') : ";
		cin >> cashPayment;	
		cout << "Enter customer given value : ";
		cin >> payAmount;
	}
	
	// Final bill display requirement's functions
	discount = grandTotal*discountPercentage; 
	VAT = grandTotal*(1-discountPercentage)*VATPercentage;
	finalPrice = grandTotal-discount+VAT;
	
	// Display of the summery
	cout << "\n\tGrand Total \t\t: " << grandTotal << endl;
	cout << "\tNo Of Quantity \t\t: " << itemQuantity << endl;
	cout << "\tDiscount \t\t: " << discount << endl;
	cout << "\tVAT \t\t\t: " << VAT << endl;
	cout << "\tFinal Price \t\t: " << finalPrice << endl;
	if(cashPayment=='Y' || cashPayment=='y')
	{
		cout << "\tPayment By \t\t: Cash" << endl;
	}
	else if(cashPayment=='N' || cashPayment=='n')
	{
		cout << "\tPayment By \t\t: Card or Other" << endl;
	}
	cout << "\tBalance \t\t: " << payAmount-finalPrice << endl;
	
	cout << "\n\t\tThank You Come Again!\n" << endl;
	cout << "**********************************************************************" << endl;
	
		
	return 0; // End of the programme
}
