class Car{
	
public: 
	Car();
	Car(int myPos, int mySize);
	//get functions
	int getPosition();
	int getSize();
	int getValue();
	//set functions
	void setPosition(int myPosition);
	void setSize(int mySize);

private:
	int pos;
	int size;

};
	
