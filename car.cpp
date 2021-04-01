#include "Car.h"

Car::Car(){
	pos =0;
	size =0;
}

Car::Car(int myPos, int mySize){
	pos = myPos;
	size = mySize;
}
//get functions
int Car::getPosition(){
	return pos;
}

int Car::getSize(){
	return size;
}

int Car::getValue(){
	return pos*size;
}

//set functions to update when positions are changed
void Car::setPosition(int newPos){
	pos = newPos;
}

void Car::setSize(int newSize){
	size = newSize;
}
	
