/* 
Programmer: Evan Soloway
Date: 5/12/2020
Assignment: Exam 3 Lab Section
Professor: Murtaza Ally
Description: This program is an index card tool to help students
study foreign vocab. The program reads--at the user's behest--one or several
.txt files containing enlgish-to-foreign vocab then reads the english word back
to the user and asks for a translation to a corresponding foreign language. The student's
attempt is graded at the end of the program depending on their answers.
*/

// NOTE TO TEACHER: DIRECTORY ADDRESS ON LINE 267 (arg passed to opendir) must be changed to accomodate indiviaual's system. Please take not if compiling and running program on your own machine.

using namespace std;

# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>

class Language{
	
	public:
		
		// Variables and arrays
		string words[20][6]; // number of words in each dict is hard-wired to 20. First element of each array is english word, subsequent 1-5 elements are Spanish equivalents
		string* answers; // number of answers will vary based on instance of class.
		
		// Member functions
		void dictCreate(string words[20][6], char file[20]){ // Creates iterable english and spanish dict array
			
			// Local variables and Arrays
			int numWhitespaces=0; // words in dictionary are delimited by whitespaces, therefore number of whitespaces is equal to number of dict words - 1, making it a perfect index to iterate over.
			int index=0;
			ifstream object;
			
			object.open(file);
			
			while (numWhitespaces < 20){
				
				getline(object,words[numWhitespaces][index]);
				
				if (!words[numWhitespaces][index][0]){ // increment whitespace count when whitespace occurs in reading dict
					numWhitespaces++;
					index = 0;
				}
				
				else{
					index++;
				}
				
			}
			
			object.close();
			
		};
	
};

int main(){
	
	// variable declarations and objects
	string name;
	char fileName[20];
	string* englishWords;
	string* spanishWords;
	bool result;
	Language dict;
	int x=0;
	int y=0;
	int z=0;
	int variations=0;
	int index=0;
	int numQs;
	double QsWrong=0;
	double QsRight=0;
	double gradePercent;
	
	// File handling
	ifstream inFile;
	ofstream outFile;
	
	// Function prototypes
	void fileDisplay();
	bool test(string, string);
	
	// Program
	cout << "Welcome to AllyBaba Vocab Quiz Program." << endl << endl;
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl;
	
	fileDisplay();
	
	try{
	cout << endl;
	cout << "Please select the quiz file: ";
	cin >> fileName;
	inFile.open(fileName);
	if (!inFile.good()) {throw 10;} // tests if file is found in directory via boolean return value
	}
	
	catch(int x){
		cout << "No file found named " << fileName << ". Please try again." << endl;
		cout << endl;
		main(); // Program restarts
	}
	
	dict.dictCreate(dict.words, fileName); // Dict is created
	
	cout << endl;
	cout << "NOTE: All spaces in answers must be rendered with underscore '_'." << endl;
	cout << "Answers should be in lower case." << endl;
	cout << "There is no credit for partially-correct answers." << "\n\n";
	
	cout << "Maximum available words: " << 20 << endl;
	cout << "How many words would you like to be quizzed on? ";
	cin >> numQs;
	
	if (numQs < 1 || numQs > 10){
		cout << "That number is invalid. Please try again." << "\n";
		main();
	}
	
	dict.answers = new string [numQs]; // initializes answers variable member of dict with array size in memory
	englishWords = new string [numQs];
	spanishWords = new string [numQs];
	
	srand(time(NULL)); // seed for random word selection
	
	for(index=0;index<numQs;index++){ // Quiz loop
		
		variations=0;
		y=0;
		x = rand() % 20; // randomly selects word
		
		// Copying to arrays for putput file
		englishWords [index] = dict.words[x][y];
		spanishWords [index] = dict.words[x][y+1];
		
		cout << endl;
		cout << "English word: " << dict.words[x][y] << endl;
		 
		while (dict.words[x][y][z]){ // loop dynamically finds number of alternative spanish translations
			variations++;
			y++;
		}
		
		cout << "Enter " << variations-1 << " equivalent Spanish word(s)." << endl;
		
		for (y=1;y<variations;y++){ // receive input from user over this loop
			cout << "Word[" << y << "]: ";
			
			cin >> dict.answers[index];
		
			if(test(dict.words[x][y], dict.answers[index])){ // Tests for truthfulness of answer
				result = true;
			}
			else{
				result = false;
				cout << "Correct word was " << "\"" <<dict.words[x][y] << "\"" << endl;
			}
			

		}
		
		if (result){
			cout << "CORRECT!" << endl;
			QsRight++;
		}
		else{
			cout << "incorrect." << endl;
			QsWrong++;
		}
		
		cout << endl;
		cout << "----------------------------------------\n";
		
	}
	
	gradePercent = (QsRight/numQs) * 100;
	
	cout << "Allybaba Grade Sheet" << endl;
	
	if (gradePercent < 80){
	cout << "Grade: " << gradePercent << "% (Failed - You have scored below 80%)" << endl; 
	}
	
	else{
	cout << "Grade: " << gradePercent << "% (Passed - You have succeeded 80%. Congrats " << name << "!)" << endl; 
	}
	
	 cout << "If you want a copy of your quiz, enter an output file (or press enter to quit): ";
	 
	 cin >> fileName;
	 
	if (fileName[0]){ // Writing test to output file
		
	outFile.open(fileName);
	
	outFile << "Below are " + name + "'s test answers:" << "\n\n";
	
	for (x=0;x<numQs;x++){
		
		outFile << "English word was: " << englishWords[x] << endl;
		outFile << "Spanish word was: " << spanishWords[x] << endl;
		outFile << "You answer: " << dict.answers[x] << endl;	
		outFile << "\n";
	}
	
	outFile << "\n";
	
	if (gradePercent < 80){
	outFile << "Grade: " << gradePercent << "% (Failed - You have scored below 80%)" << endl; 
	}
	
	else{
	outFile << "Grade: " << gradePercent << "% (Passed - You have succeeded 80%. Congrats " << name << "!)" << endl; 
	}
	
	exit(0);
		
	}
	
	else{
		exit(0);
	}
	
	return 0;
}

bool test(string answer, string input){
	
	int x=0;
	bool result = true;
	
	while(answer[x]){
		
		if (answer[x] != input[x]){
			result = false;
		}
		
		x++;
		
	}
	
	return result;
}

void fileDisplay(){ // reads from directory using dirent.h header
	
	// variable declarations and objects
	int numTxtFiles=0;
	int index1;
	int index2=0;
	
	DIR *dir;
	struct dirent *ent;
	dir = opendir("c:\\Users\\evan1\\Desktop\\Prog. Fund. II\\Exam 3\\"); // directory must be altered by programmer to accomodate new system
	
	cout << "Select one of the following word lists:" << endl;
	
	if (dir != NULL){
		while ((ent=readdir(dir)) != NULL) { // iterates over each file
		
		index1=0;
	
		while (ent->d_name[index1]){ // iterates over each character in file name
		
		if (ent->d_name[index1+1] == 'x' && ent->d_name[index1] == 't' && ent->d_name[index1-1] == '.'){ // test for whether file is .txt
			
			numTxtFiles++; // increment number of relevant files
			
			cout << ent->d_name << endl;
			
		}
		
		index1++; // increment character in file name
		
		}
		
		index2++; // increment file
		
		}
		
		if (!numTxtFiles){
			cout << "There are no .txt files in this directory.";
			exit(0);
		}
		
		closedir(dir);
	}
	
	else{
		perror("");
		cout << "File/Directory could not be found.";
		exit(0);
	}
	
}
