#include<iostream>
#include "hexdump.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **args ){
	if( argc<2){
		cout<<"Usage: hexdump file_name"<<endl;
		return 1;
	}
	string file = args[1];
	HexDump h(file);
	cout<<h;
	return 0;
}
