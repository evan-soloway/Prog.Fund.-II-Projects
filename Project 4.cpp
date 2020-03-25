// FORMATTING OF DATA TABLE REQUIRED
// HEADING AT TOP OF PROGRAM REQUIRED

# include <iostream>
# include <iomanip>
# include <string>
# include <math.h>

using namespace std;

int main(){
	
	// array marker variables
	const int monkeys = 3;
	const int days = 7;
	
	// Arrays for graphic
	double amntFood [monkeys] [days];
	string daysOfWeek[days] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	
	// Variables for graphic
	double average;
	double greatest;
	double least;
	string unit = "pounds";
	
	// Monkey arrays (just in case)
	double monkey1 [days];
	double monkey2 [days];
	double monkey3 [days];
	
	// Function prototypes
	void dataDisplay(int, int, double [monkeys][days], string[days], double, double,double, string);
	double receiveInput2(int, int, double [monkeys][days], double [days], double [days], double [days]);
	double calcAverage(int, int, double, double [monkeys][days]);
	double greatAmount(int, int, double, double [monkeys][days]);
	double leastAmount(int, int, double, double [monkeys][days]);
	
	// Function Calls
	amntFood [monkeys] [days] = receiveInput2(monkeys, days, amntFood, monkey1, \
	monkey2, monkey3);
	average = calcAverage(monkeys, days, average, amntFood);
	greatest = greatAmount(monkeys, days, greatest, amntFood);
	least = leastAmount(monkeys, days, least, amntFood);
	dataDisplay(monkeys, days, amntFood, daysOfWeek, average, greatest, least, unit);
	
	return 0;
}

void dataDisplay(int monkeys, int days, double amntFood[3][7], string daysOfWeek[7], \
double average, double greatest, double least, string unit){
	
	// loop qualifiers
	int x;
	int y;
	
	cout << "Pounds of Food Eaten by Monkey and Day of Week" << "\n\n";
	
	cout << " ";
	
	for (y=0;y<days;y++){
		cout << daysOfWeek[y];
		cout << " ";
	}
	
	cout << endl;
	
	for (x=0;x<monkeys;x++){
		
		cout << x + 1;
		
		for (y=0;y<days;y++){
			cout << " ";
			cout << amntFood[x][y];
		}
		cout << endl;
	}
	
	cout << "\n\n";
	cout << "The average food eaten per day by all monkeys: " << average << endl;
	cout << "The least amount of food eaten by any monkey: " << least << endl;
	cout << "The largest amount of food eaten per day by any monkey: " << greatest << endl; 
	
}

double calcAverage(int monkeys, int days, double average, double amntFood[3][7]){
	
	// loop qualifiers
	int x;
	int y;
	
	double accumulator = 0;
	
	for (x = 0; x < monkeys; x++){
		
		for (y = 0; y < days; y++){
	
			accumulator += amntFood[x][y];
			
		}
		
	}
	
	average = accumulator / 7;
	
	return average;
}

double greatAmount(int monkeys, int days, double greatest, double amntFood[3][7]){
	
	// loop qualifiers
	int x;
	int y;
	
	greatest = 0;
	
	for (x = 0; x < monkeys; x++){
		
		for (y = 0; y < days; y++){
	
			if (amntFood[x][y] > greatest){
				greatest = amntFood[x][y];
			}
		
		}
	
	
	}

	return greatest;
	
}

double leastAmount(int monkeys, int days, double least, double amntFood[3][7]){
	
	// loop qualifiers
	int x;
	int y;
	
	least = 100;
	
	for (x = 0; x < monkeys; x++){
		
		for (y = 0; y < days; y++){
	
			if (amntFood[x][y] < least){
				least = amntFood[x][y];
			}
		
		}
	
	}
	
	return least;	

}	

double receiveInput2(int monkeys, int days, double amntFood[3][7], double monkey1 [7], \
double monkey2 [7], double monkey3 [7]){
	
	// Function prototypes
	void dayOfWeek(int);
	
	// loop qualifiers
	int x;
	int y;
	
	// Loop receiving data
	for (x = 0; x < monkeys; x++){
		
		cout << "Enter pounds of food eaten by Monkey #" << x + 1 << " for each day of the week" << endl;
		cout << "-----------------------------------------------------------------------------\n";
		
		for (y = 0; y < days; y++){
	
			dayOfWeek(y);
			cin >> amntFood[x][y];
			
			if (x==0){
				monkey1 [y] = amntFood[x][y];
			}
			else if (x==1){
				monkey2 [y] = amntFood[x][y];
			}
			else if (x==2){
				monkey3 [y] = amntFood[x][y];
			}
				
		}
		
		cout << "\n";
	}
	
	return amntFood[monkeys][days];
}

void dayOfWeek(int y){
	
	// If statements deciding day

	if (y == 0) {
		cout << "Monday: ";
	}
	
	if (y == 1) {
		cout << "Tuesday: ";
	}
	
	if (y == 2) {
		cout << "Wednesday: ";
	}
	
	if (y == 3) {
		cout << "Thursday: ";
	}
	
	if (y == 4) {
		cout << "Friday: ";
	}
	
	if (y == 5) {
		cout << "Saturday: ";
	}
	
	if (y == 6) {
		cout << "Sunday: ";
	}
	
}
