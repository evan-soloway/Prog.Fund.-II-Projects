// FORMATTING OF DATA TABLE REQUIRED
// HEADING AT TOP OF PROGRAM REQUIRED
// INPUT VALIDATION MUST BE ADDED

# include <iostream>
# include <iomanip>
# include <string>
# include <stdio.h>
# include <stdlib.h>

using namespace std;
			
int main(){
	
	int transactionNum = 0;
	double allPacksCost = 0;
	bool continuing;
	
	void program(int,double);
	
	cout << "Welcome to Allybaba Shipping Service!" << endl;
	cout << endl;
	
	program(transactionNum, allPacksCost);

	return 0;
}

void costAndWeightCalc(int weightOptions [15], int inchPackData [3], double & totalPackCost, int & weight, double destCharge, \
double shipCharges [15], bool & accepted, int largestSide, int & numRejectedPacks, int & numAcceptedPacks){
	
	double shipCharge = 0;
	int tier;

	for (tier=0;shipCharge==0;tier++){
		
		if (weightOptions[tier] >= weight){
			shipCharge = shipCharges[tier];
		}
	}
	
	totalPackCost = shipCharge + destCharge;
	
	double girth = 2 * (inchPackData[0] + inchPackData[1] + inchPackData[2] - largestSide);
	
	if (girth > 10){
		accepted = false;
		totalPackCost = 0;
		numRejectedPacks += 1;
	}
	else{
		accepted = true;
		numAcceptedPacks += 1;
	}
	
}

void promptDisplay(){
	
	cout << "Menu" << endl;
	cout << "-------------------------------------------------" << endl; 
	cout << "Enter Location - (T)exas; (O)ut of state; (F)oreign; E(X)it" << endl;
	cout << "Enter package weight and 3 dimensions" << endl;
	
}

string destinationFind(double & destCharge, int numAcceptedPacks, \
int numRejectedPacks, double allPacksCost){
	
		string destination;
		char transactionType;
		
		cout << "\nEnter Location: ";
		cin >> transactionType;
		
		if (transactionType == 'x' || transactionType == 'X'){
			
			cout << "\n";
			cout << "Number of accepted packages:  " << numAcceptedPacks << endl;
			cout << "Number of rejected packages:  " << numRejectedPacks << endl;
			cout << "Total Cost:                   $" << allPacksCost << endl;
			
			exit(0);
		}
		
		else if (transactionType == 't' || transactionType == 'T'){
			destination = "Texas";
			destCharge = 0;
		}
		
		else if (transactionType == 'o' || transactionType == 'O'){
			destination = "Out of state";
			destCharge = 35.00;
		}
		
		else if (transactionType == 'f' || transactionType == 'F'){
			destination = "Foreign";
			destCharge = 40.00;
		}
		
		else{
			cout << "Invalid input. Please try again." << endl;
			destinationFind(destCharge, numAcceptedPacks, \
			numRejectedPacks, allPacksCost);
		}
		
		return destination;
}

void destChargeTest(double destCharge){
	
	if (destCharge > 0){
		cout << "Shipping Cost: $" << destCharge << endl;
	}
	
}

void acceptTest(bool accepted){
	if (accepted){
		cout << "Accepted" << endl;
	}
	else{
		cout << "Rejected" << endl;
	}
}

int receivePackageData(int inchPackData[3], int & largestSide, int & weight){
	
	int sideNum;
	largestSide = 0;
	
	cout << "Enter package weight in Pounds: ";
	cin >> weight;
	
	if (weight < 0){
		cout << "\nNumber less than zero; please try again." << endl;
		cout << endl;
		receivePackageData(inchPackData, largestSide, weight);
	}
	
	cout << endl;
	
	for (sideNum=0;sideNum<3;sideNum++){
	cout << "Enter Side " << sideNum << ": ";
	cin >> inchPackData[sideNum];
	
		if (inchPackData[sideNum] < 0){
			cout << "\nNumber less than zero; please try again." << endl;
			cout << endl;
			receivePackageData(inchPackData, largestSide, weight);
	}
	
		if  (inchPackData[sideNum] > largestSide){
			largestSide = inchPackData[sideNum];
			}
	
	}
	
	return inchPackData[3];
}

void program(int transactionNum, double allPacksCost){
	
	transactionNum++;
	
	// Function prototypes
	void promptDisplay();
	void destChargeTest(double);
	void acceptTest(bool);
	void costAndWeightCalc(int [15], int [3], double &, int &, double, double [15], bool &, int, int &, int &);
	int receivePackageData(int [3], int &, int &);
	string destinationFind(double &, int, int, double);	
	
	// Variables and Arrays
	int inchPackData [3];
	int weight, largestSide, numRejectedPacks = 0, numAcceptedPacks = 0;
	string destination;
	bool accepted;
	double totalPackCost = 0, destCharge = 0;
	double shipCharges [15] = {1.50,2.10,4.00,6.75,9.90,14.95,19.40,24.20, \
	27.30,31.90,38.50,43.50,44.80,47.40,55.20};
	int weightOptions [15] = {1,2,3,5,7,10,13,16,20,25,30,35,40,45,50};
	
	// Start of program
	
	promptDisplay();
	
	destination = destinationFind(destCharge, numAcceptedPacks, \
	numRejectedPacks, allPacksCost);
	
	inchPackData [3] = receivePackageData(inchPackData, largestSide, weight);
	
	costAndWeightCalc(weightOptions, inchPackData, totalPackCost, weight, destCharge, shipCharges, \
	accepted, largestSide, numRejectedPacks, numAcceptedPacks);
	
	allPacksCost += totalPackCost;
	
	// Final Display
	cout << "\nTransaction #" << transactionNum << endl;
	cout << "Location:      " << destination << endl;
	cout << "Status         ";
	acceptTest(accepted);
	cout << "Weight:        " << weight << " Pounds" << endl;
	destChargeTest(destCharge);
	cout << "Cost:          $" << totalPackCost << endl;
	cout << endl;
	
	program(transactionNum, allPacksCost);
	
}
