#include <iostream>
#include <string>
#include "Map.hpp"

int main(){
	initializer_list<pair<int,string>> il = {{1, "poopoo"}, {2, "peepee"}};
	Map <int,string> m{{1,"poopoo"},{2,"peepee"}};
	m.~Map();
	return 0;
}
