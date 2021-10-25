#include <iostream>
#include <string>
#include "Map.hpp"

int main(){
	cout << "yo wassup" <<endl;
	//Map <int,string> m{{1,"poopoo"},{2,"peepee"}};
	Map <int, string> m1;
	const pair <int,string> input1 = {1,"peepee"};
	pair <Map<int,string>::Iterator,bool> iresults = m1.insert(input1);
	cout << iresults.second <<endl;
	cout<< "inited map" <<endl;
	//const int key = 1;
	cout << "plz print something" <<endl;
	//cout << m.find(key).itr->val <<endl;
	//m.~Map();
	return 0;
}
