#include<iostream>
using namespace std;
#include<fstream>

int main(){
	int *maximum, *sum;
	int tempNum, tempMax=0, tempSum=0;
	maximum=&tempMax;
	sum=&tempSum;
	
	ifstream infile("number.txt");
	ofstream outfile("result.txt");
	
	int i=0;
	while(!infile.eof()){ //while not end of file
		//read numbers from input file
		infile >> tempNum;
		//identify the maximum value
		if(tempNum > tempMax){
			tempMax = tempNum;
		}
		//sum all the numbers from the input file
		tempSum += tempNum;
		i++;//continue loop until end of file
	}
	//display max and sum on the output file
	outfile << "Result" <<endl;
	outfile << "\nMaximum number is " << *maximum <<endl;
	outfile << "Sum is " << *sum <<endl;
	infile.close();
	outfile.close();
	return 0;
}
