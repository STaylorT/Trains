//author: Taylor Thomas 2/21
#include <string>
#include <iostream>
#include "LinkedList.h"
using namespace std;
#include <stdlib.h>
#include<cstdlib>


int main(int argc, char* argv[]){
	// 
	int n = stoi(argv[1]);
	int c = stoi(argv[2]);
	int t = stoi(argv[3]);
	LinkedList trains[n];
	
	// quit program if the inputs are bad
	if (n<=0 || c <= 0 || t <= 0){
		cout << "Bad parameters. Try again." << endl;
		return 0;
	}
	// initialize the trains and cars!
	for (int i = 0; i < n;i++){
		for (int j = c ; j > 0;j--){
			Car newCar = Car(j,j);
			Node* new_node = new Node(newCar);
			trains[i].insertFront(new_node);
		}
	}
	// variables to check if we need to end program
	// checks to see if a train is empty or we've met the count limit
	bool isEmpty = false;
	int count = 0;
	// iterating through each step
	while (!isEmpty && count < t){
		int donor = rand() % n ;
		int side = rand() % 2;
		int recipient = rand() % n;
		string frntBack = "";
		// set to take from front
		if (side == 1){
			trains[recipient].insertFront(trains[donor].removeFront());
			frntBack = "Front";
		}
		//set to take from back
		else{
			trains[recipient].insertFront(trains[donor].removeEnd());
			frntBack = "Back";
		}
		// check if any train is empty
		for (int i = 0; i < n; i++){
			if (trains[i].isEmpty()){
				isEmpty = true;
				break;
			}
		}
		// increment count, signifying end of iteration
		count++;
		
		// output desired information after each iteration
		cout << "Turn " << count << ":" << endl;
		cout << "Donor Train: Train " << donor+1 << " from " << frntBack << endl;
		cout << "Recipient Train: Train " << recipient+1 << endl << endl;
		for (int i = 0 ; i < n ; i++){
			cout << "Train " << i+1 << " Value: " << trains[i].getValue() << endl;
			}
		cout << "--------------------------------------------------------" << endl << endl;
		/**
		printf("Donor Train: Train %d from Car %s\n", donor+1,frntBack);
		printf("Recipient Train: Train %d\n",recipient+1);
		*/
		
	}
		// find max train value and set values
		int i =0;
		int trainNum=0;
		int maxValue = trains[i].getValue();
		for (i = 1 ; i < n;i++){
			if (maxValue < trains[i].getValue()){
				maxValue = trains[i].getValue();
				trainNum = i;
			}
		}
	// at the end of program, output which train has the largest value
	cout << "Train " << trainNum+1 << " has the largest value("<<maxValue << ")" << endl << endl;
	
		
		return 0;

}
