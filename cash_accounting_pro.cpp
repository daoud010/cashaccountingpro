/* 
 * 
 * Author: Daoud Nsangou
 * Date: June 1, 2017
 *FileName:   Module 04 assignment
 * Purpose: Course Project
 * 
 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
int menu();
int submenu_Invoice();
int submenu_Expenses();
void addInvoice(vector<string>&names, vector<string>&dates, vector<double>&invoiceAmount);
void searchInvoice(vector<string>names, vector<string>dates, vector<double>invoiceAmount);
void printInvoice(vector<string>names, vector<string>dates, vector<double>invoiceAmount);
void addExpense(vector<string>&names, vector<string>&dates, vector<double>&billAmount);
void searchExpense(vector<string>names, vector<string>dates, vector<double>billAmount);
void printExpense(vector<string>names, vector<string>dates, vector<double>billAmount);
void cashFlow(vector<double>total_invoiceAmount, vector<double>total_billAmount);


int main() {
	int answer = menu();
	int option =0;
	int response =0;
	
	vector<string> invoiceName;
	vector<string> invoiceDate;
	vector<double> invoiceAmount;

	vector<string>	expenseName;
	vector<string> 	expenseDate;
	vector<double> 	expenseAmount;

	while (answer!= 4) 	{

if (answer == 1) {

		
		option = submenu_Invoice();


		if (option ==1) {			

			cout<< "how many invoices to you want to add?"<<endl;
			cin>>response;
			for (int a=1; a<=response;a++){
					addInvoice(invoiceName, invoiceDate, invoiceAmount);

			}
		}

		else if (option ==2) {

			searchInvoice(invoiceName, invoiceDate, invoiceAmount);		
		}

		else if (option==3) {

			printInvoice(invoiceName, invoiceDate, invoiceAmount);
		}


}

else if (answer== 2) {

	int option =0;

		
		option = submenu_Expenses();


		if (option ==1) {			

			cout<< "how many expenses to you want to add?"<<endl;
			cin>>response;
			for (int a=1; a<=response;a++){
					
				addExpense(expenseName, expenseDate, expenseAmount);

			}
		}

		else if (option ==2) {

			searchExpense(expenseName, expenseDate, expenseAmount);		
		}

		else if (option ==3) {

			printExpense(expenseName, expenseDate, expenseAmount);
		}

}

		else if(answer== 3) {

		cashFlow(invoiceAmount, expenseAmount);
}

 answer = menu();
}
return 0;	
}

//Menu function

int menu() {
int answer =0;

cout<< "Cash Accounting Pro"<<endl;
cout <<"-------------------------------------"<<endl;
cout<<" Enter 1 for Invoice for this month"<<endl;
cout<<" Enter 2 for Expenses for this month"<<endl;
cout<<" Enter 3 for CashFlow for this month" <<endl;
cout<<" Enter 4 to Quit the program "<<endl;
cout <<"-------------------------------------"<<endl;
cin>> answer;

while (answer < 1 || answer > 4) {


	cout<<"Invalid Option. Please enter 1-4:" << endl; //infinite loop if an integer is not typed in
	cin>> answer;


}

return answer;

}

//submenu for invoice 

int submenu_Invoice() {

	int option = 0;
	cout<< "Invoice Submenu"<<endl;
	cout<<"Enter 1 to addInvoice"<<endl;
	cout<<"Enter 2 to searchInvoice"<<endl;
	cout<<"Enter 3 to printInvoice\n"<<endl;
	cin>>option;

while (option < 1 || option> 4) {


	cout<<"Invalid Option. Please enter 1-4:" << endl;
	cin>> option;
}

return option;
} 

int submenu_Expenses() {


	int option = 0;
	cout<< "Invoice Submenu"<<endl;
	cout<<"Enter 1 to addExpense"<<endl;
	cout<<"Enter 2 to searchExpense"<<endl;
	cout<<"Enter 3 to printExpense\n"<<endl;
	cin>>option;

while (option < 1 || option > 4) {


	cout<<"Invalid Option. Please enter 1-4:" << endl;
	cin>> option;
}

return option;
} 


// invoice function
void addInvoice(vector<string>&names, vector<string>&dates, vector<double> &amounts) {
	string name;
	string date;
	double amount;
	int i = 0;


cout<<"Enter the name:"<<endl;
cin>> name;
names.push_back(name);

cout <<"Enter the date(mm/dd/yy):"<<endl;
cin>> date;
dates.push_back(date);

cout<<"Enter the amount:"<<endl;
cin>> amount;
amounts.push_back(amount);


}

void searchInvoice(vector<string>names, vector<string>dates, vector<double>invoiceAmount) {
string username;

cout << "Search for a user's name? Remember inputs are case-sensitive\n"<<endl;
cin>>username;

bool found = false;
int m = 0;
		cout<< "Here is the Invoice: \n"<<endl;
		cout<<"Names:"<<"        "<<"Date(mm/dd/yy):"<<"       "<<"invoiceAmount($):"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
while(found == false && m<5) {
	
		if (names[m] == username) {

		found = true;
		cout<<names[m]<<"            "<<dates[m]<<"               "<<invoiceAmount[m]<<"\n"<<endl;
	}

	m++;
}
		cout<<"---------------------------------------------------------------"<<endl;

}

void printInvoice(vector<string>names, vector<string>dates, vector<double>invoiceAmount) {
	cout<< "Here is the most updated info for this month's invoice: \n"<<endl;
	cout<<"Names:"<<"               "<<"Date(mm/dd/yy):"<<"                "<<"invoiceAmount($):"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;

	for (int j=0; j<names.size(); j++) {
	 
    cout<<names[j]<<"                "<<	dates[j]<<"                        "<< invoiceAmount[j]<<endl;
    
}
	cout<<"---------------------------------------------------------------"<<endl;
}

void addExpense(vector<string>&names, vector<string>&dates, vector<double>&billAmount) {
	string name;
	string date;
	double amount;
	int i = 0;

cout<<"Enter the name"<<endl;
cin>> name;
names.push_back(name);

cout <<"Enter the date(mm/dd/yy)"<<endl;
cin>> date;
dates.push_back(date);

cout<<"Enter the amount"<<endl;
cin>> amount;
billAmount.push_back(amount);


}

void searchExpense(vector<string>names, vector<string>dates, vector<double>billAmount) {
string username;

cout << "Search for a expense name? Remember inputs are case-sensitive\n"<<endl;
cin>>username;

bool found = false;
int m = 0;

cout<< "Here is the Expense: \n"<<endl;
		cout<<"Names:"<<"        "<<"Date(mm/dd/yy):"<<"       "<<"invoiceAmount($):"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
while(found == false && m<5) {
	
		if (names[m] == username) {

		found = true;
		
		cout<<names[m]<<"            "<<dates[m]<<"               "<<billAmount[m]<<"\n"<<endl;
		
	}
	
	m++;
	
}
	cout<<"---------------------------------------------------------------"<<endl;
}

void printExpense(vector<string>names, vector<string>dates, vector<double>billAmount) {

	cout<< "Here is the most updated info for this month's invoice: \n"<<endl;
	cout<<"Names:"<<"                      "<<"Date(mm/dd/yy):"<<"                 "<<"invoiceAmount($):"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	for (int j=0; j<names.size(); j++) {
	
  cout<<names[j]  <<"                       "<<dates[j]<<"                         "<< billAmount[j]<<endl;  
}

	cout<<"---------------------------------------------------------------"<<endl;
}

void cashFlow(vector<double>invoiceAmount, vector<double>billAmount) {

int cashFlow = 0;
int totalExpense =0, totalInvoiceAmount= 0;

for (int i = 0; i<invoiceAmount.size();i++)

{
	totalInvoiceAmount = totalInvoiceAmount + invoiceAmount[i];

}


for (int i = 0; i<billAmount.size();i++)

{
	totalExpense= totalExpense + billAmount[i];

}

	cashFlow = totalInvoiceAmount- totalExpense;

	cout<< "Here is your cash flow:"<< "    "<< "|"<<"$ "<<cashFlow<< "|"<<endl;

}










