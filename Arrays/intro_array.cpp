//To store multiple value in one variable we use array
//Array is a collection of similar data type
#include <stdlib.h>
#include <iostream>
using namespace std;
int number[3] = {5,7,11};

int main() {
	cout << number[2]<< endl;
	int third[15]={4,7,9};
	for(int i=0;i<15;i++){
		cout << third[i]<< " ";
	}
	cout<<endl<<"Everything is Fine"<<endl;
	return 0;
}