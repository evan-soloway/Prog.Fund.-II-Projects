// HEADING AT TOP OF PROGRAM REQUIRED

# include <iostream>
# include <math.h> 
# include <string>

using namespace std;

int main(){
	
	// Function prototypes
	void openingPrompt(double &);
	void checkFunction(double &, double &, double &, double &, double &, double &);
	void depositFunction(double &, double &, double &);
	double amntDecoder(string);
	
	// Loop qualifiers
	bool running = true;
	string input;
	char delim = 'Z';
	
	// Variables
	double balance;
	double taAmount;
	double serviceCharges1 = 0.35;
	double serviceCharges2 = 15.00;
	double serviceCharges3 = 35.00;
	double totalServiceCharges = 0;

	openingPrompt(balance);
	
	while (running) {
		
	// Series of prompts
	cout << "\n------------------------------------------------" << endl;
	cout << "Select transaction type:" << endl;
	cout << "C - Process a check" << endl;
	cout << "D - Process a deposit" << endl;
	cout << "E - Exit" << endl;
	
	cout << "\nEnter transaction type and amount (formatted with no spaces and with transaction type" << endl <<
	"as first character. End input line with 'Z' immediately following last number in amount [Ex: c50Z]): "; 
	getline(cin,input, delim);
	
	taAmount = amntDecoder(input);
	
	// Breaks from program if "e" or "E" is entered 
	if (input[1] == 'e' || input[1] == 'E') {
		running = false; 
		}
		
	// Begins check transaction process
	else if (input[1] == 'c' || input[1] == 'C') {
		
		checkFunction(balance, serviceCharges1, serviceCharges2, taAmount, 
		totalServiceCharges, serviceCharges3);
		}
		
	// Begins deposit transaction process
	else if (input[1] == 'd' || input[1] == 'D') {
		
		depositFunction(balance, totalServiceCharges, taAmount);
		
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

void checkFunction(double & balance, double & serviceCharges1, double & serviceCharges2, 
double & taAmount, double & totalServiceCharges, double & serviceCharges3){
	
		int minimum = 500;
		
		cout << "\nProcessing check for $" << taAmount << endl;
		
		// Input validation
		if (taAmount < 0){
			
			cout << "\nYou entered an invalid, negative number. Please try again.\n";
			
			cout << "Enter new amount: ";
			cin >> taAmount;
			
			checkFunction(balance, serviceCharges1, serviceCharges2, taAmount, 
			totalServiceCharges, serviceCharges3);
		}
		
		if (taAmount > balance){
			
			cout << "\nYou entered an invalid number in an attempt to withdraw more money than you currently have. Please try again.\n";
			totalServiceCharges += serviceCharges3;
			
			cout << "Enter new amount: ";
			cin >> taAmount;
			
			checkFunction(balance, serviceCharges1, serviceCharges2, taAmount, 
			totalServiceCharges, serviceCharges3);
		}
		
		// Calculations
		balance -= (taAmount + serviceCharges1);
		
		totalServiceCharges += serviceCharges1;
		if(balance < minimum){
			totalServiceCharges = totalServiceCharges + serviceCharges2;
			balance -= serviceCharges2;
		}
		
		cout << "\nProcessed..." << endl;
		cout << "Balance: $" << balance << endl;  
		cout << "Service charge: $" << serviceCharges1 << " for a check" << endl;
		if(balance < minimum){
			cout << "Service Charge: $" << serviceCharges2 << " balance below $" << minimum << endl;
		}
		if (taAmount < 0){
			cout << "Service Charge: $" << serviceCharges3 << " attempted to overdraw" << endl;
		}
		cout << "Total service charges: $" << totalServiceCharges << endl;
}

void depositFunction(double & balance, double & totalServiceCharges, double & taAmount){
		
		cout << "\nProcessing deposit for $" << taAmount << endl;
		
		// Input validation
		if (taAmount < 0){
			
			cout << "\nYou entered an invalid, negative number. Please try again.\n";
			
			cout << "Enter new amount: ";
			cin >> taAmount;
			
			depositFunction(balance, totalServiceCharges, taAmount);
		}
		
		
		if (taAmount > 10000000){
			
			cout << "\nThe IRS has been notified of this transaction. Please try again.\n";
			
			cout << "Enter new amount: ";
			cin >> taAmount;
			
			depositFunction(balance, totalServiceCharges, taAmount);
		}
		
		// Calculations
		balance += taAmount;
		
		cout << "\nProcessed..." << endl;
		cout << "Balance: $" << balance << endl;  
		cout << "Total service charges: $" << totalServiceCharges << endl;

}

// Receives string input and translates to double taAmount. Max taAmount is (x * 10^13)-1
double amntDecoder(string input){
	
	double taAmount;
	int target;
	int max = 0;
	int i;
	int power;
	int illustration = 0;
	string taAmountChar = "";
	bool negative = false;
	
	if ((illustration += input[2]) == 45){
		negative = true;
		cout << "number is negative" << endl;
	}
	
	for (target = 2;target <= 14;target++){
		
		illustration = 0;
		illustration += input[target];
		
		if (illustration == 0){
			break;
		}
		
		if (illustration >= 48 & illustration < 58){
			taAmountChar += input[target];
			max += 1;
		}
		
	} 
	
	for (i=0;i<max;i++){
		
		illustration = 0;
		illustration += taAmountChar[i];
		
		if (illustration >= 48 & illustration < 58){
			power = pow(10, ((max-1)-i));
			taAmount += (taAmountChar[i] - 48) * power;
		}
		
	}
	
	if (negative == true){
		taAmount *= -1;
	}
	
	return taAmount;
	
}
