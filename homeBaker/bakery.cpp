#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct customer {
	string name;
	string hpno;
	string caketype;
	int weight;
	float price;
};

int main(){
	customer cust[5];
	ifstream f1; //declare input file name f1
	f1.open("customer.txt");//open input text file, shortcut = ifstream f1("customer.txt")
	
	for(int i=0;i<5;i++){
		
		f1 >> cust[i].name;
		f1 >> cust[i].hpno;
		f1 >> cust[i].caketype;
		f1 >> cust[i].weight;
		f1 >> cust[i].price;
	}
	
	ofstream f2; //declare output file named f2
	f2.open("summary.txt");
	int count5kg=0;
	
	//OUTPUT
	f2 << "Summary for Cheesecake\n" <<endl;
	f2 << "Name\tPhone Number\tCake Type\tPrice" <<endl;
	f2 << "=====================================================================" <<endl;
	
	for(int i=0;i<5;i++){
		
		//Output list more than 5kg
		if(cust[i].weight > 5){
			
			f2 << cust[i].name << "\t" << cust[i].hpno << "\t" << cust[i].caketype << "\t" << cust[i].price <<endl;
			
			count5kg++;
		}
	}
	
	f2 << "\nTotal number of cheesecake that weight more than 5 kg: " << count5kg <<endl;
	return 0;
}
