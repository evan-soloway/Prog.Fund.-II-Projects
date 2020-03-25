# include <iostream>
# include <iomanip>
using namespace std;

int main(){
	
	// Function prototypes
	void openingPrompt(double &);
	void checkFunction(double &, double &, double &, double &);
	void depositFunction(double &, double &, double &);
	
	// Loop qualifiers
	bool running = true;
	char input;
	
	// Variables
	double taAmount;
	double balance;
	double staticServiceCharges = 0.25;
	double serviceCharges = 0;

	openingPrompt(balance);
	
	while (running) {
		
	// Series of prompts
	cout << "\n------------------------------------------------" << endl;
	cout << "Select transaction type:" << endl;
	cout << "C - Process a check" << endl;
	cout << "D - Process a deposit" << endl;
	cout << "E - Exit" << endl;
	
	cout << "\nEnter a transaction type: ";
	cin >> input; 
	
	// Breaks from program if "e" or "E" is entered 
	if (input == 'e' || input == 'E') {
		running = false; 
		}
		
	// Begins check transaction process
	else if (input == 'c' || input == 'C') {
		
		checkFunction(balance, serviceCharges, staticServiceCharges, taAmount);
		
		}
		
	// Begins deposit transaction process
	else if (input == 'd' || input == 'D') {
		
		depositFunction(balance, serviceCharges, taAmount);
		
		}
		
	}
	
	cout << "Processing end of month" << endl;
	cout << "Final balance: $" << balance << endl;
	
	system("pause");
	
	return 0;
}

void openingPrompt(double & balance){

cout << "Ally Baba Checkbook Balancing Program" << "\n\n";
	cout << "Enter the beginning balance: ";
	cin >> balance;	
}

void checkFunction(double & balance, double & serviceCharges, double & staticServiceCharges, double & taAmount){
	
	cout << "Enter transaction amount: ";
		cin >> taAmount;
		
		cout << "Processing check for $" << taAmount << endl;
		
		// Input validation
		if (taAmount < 0){
			
			cout << "\nYou entered an invalid, negative number. Please try again.\n";
			
			checkFunction(balance, serviceCharges, staticServiceCharges, taAmount);
		}
		
		if (taAmount > balance){
			
			cout << "\nYou entered an invalid number in an attempt to withdraw more money than you currently have. Please try again.\n";
			
			checkFunction(balance, serviceCharges, staticServiceCharges, taAmount);
		}
		
		// Calculations
		serviceCharges += 0.25;
		balance -= (taAmount + staticServiceCharges);
		
		cout << "\nProcessed..." << endl;
		cout << "Balance: $" << balance << endl;  
		cout << "Service charge: $" << staticServiceCharges << endl;
		cout << "Total service charges: $" << serviceCharges << endl;

}

void depositFunction(double & balance, double & serviceCharges, double & taAmount){
	
	cout << "Enter transaction amount: ";
		cin >> taAmount;
		
		cout << "Processing deposit for $" << taAmount << endl;
		
		// Input validation
		if (taAmount < 0){
			
			cout << "\nYou entered an invalid, negative number. Please try again.\n";
			
			depositFunction(balance, serviceCharges, taAmount);
		}
		
		if (taAmount > 10000000){
			
			cout << "\nThe IRS has been notified of this transaction. Please try again.\n";
			
			depositFunction(balance, serviceCharges, taAmount);
		}
		
		// Calculations
		balance += taAmount;
		
		cout << "\nProcessed..." << endl;
		cout << "Balance: $" << balance << endl;  
		cout << "Total service charges: $" << serviceCharges << endl;

}
