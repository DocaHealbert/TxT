#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct pizzaOrder{
	string name;
	string phoneNumber;
	string pizzaType;
	string pizzaSize;
	float price;
};

int main(){
	
	pizzaOrder orders[150];
	
	ifstream inData("customer.txt");
	
	for(int i=0;i<150;i++){
		getline(inData,orders[i].name, ',');
		getline(inData,orders[i].phoneNumber, ',');
		getline(inData,orders[i].pizzaType, ',');
		getline(inData,orders[i].pizzaSize, ',');
		inData >> orders[i].price;
	}
	
	ofstream outData;
	outData.open("summary.txt");
	 int countLarge =0;
	 
	 outData << "Summary of Pizza Orders: " <<endl;
	 outData << "\nName\t\t\tPhone Number\t\tPizza Type\tSize\tPrice(RM)" <<endl;
	 outData << "---------------------------------------------------------------------------------------------------------------------" <<endl;
	 
	 for(int i=0;i<150;i++){
	 	if(orders[i].pizzaSize == "Large"){
	 		countLarge++;
	 		outData << orders[i].name << "\t\t" << orders[i].phoneNumber << "\t\t" << orders[i].pizzaType << "\t" << orders[i].pizzaSize << "\t" << orders[i].price <<endl;
		 }
	 }
	 outData << "\nTotal number of large pizzas ordered: " << countLarge <<endl;
	 return 0;
}
