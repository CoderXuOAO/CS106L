#include "realvector.h" // Change this to "realvector.h" if you want to use your solution!
#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::string; using std::endl;

// If you want your vector to hold a type other than int, be sure to change the type of the parameter
void printVec(const RealVector<int>& vec){
	cout << "My vector: {";
	for(auto it = vec.begin(); it != vec.end(); ++it){
		cout << " " << *it;
	}
	cout << " }" << endl;
}

// play around with RealVector here!
int main(){
	// //make an empty vector
	// RealVector<int> myVec;
	// //RealVector<std::string> myVec;
	// printVec(myVec);

	// cout << "Enter [ELEM] to add:" << endl;
	// //std::string to_add;
	// int to_add;
	// while(cin >> to_add){
	// 	myVec.push_back(to_add);
	// 	//print vector:
	// 	printVec(myVec);

	// 	//next prompt
	// 	cout << "Enter [ELEM] to add:" << endl;
	// }
	RealVector<int> myVec(3, 121);
	for(int i = 0; i < 10; ++i) {
		myVec.push_back(i);
		printVec(myVec);
	}
	
	myVec.insert(2, 131);
	printVec(myVec);
	
	for(int i = 0; i < 10; ++i) {
		myVec.pop_back();
		printVec(myVec);
	}
	cout << myVec[0] <<endl;
	return 0;
}