/*
* The HexDump class
* Author: satanic-devil
* Date: May-2021
*
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<iterator>
#include<stdexcept>
#include<cctype>

using std::cout;
using std::endl;
using std::string;

class HexDump{
public:
	HexDump(string file):file_name(file){
		read_file();
	}

	friend std::ostream& operator<<(std::ostream&, const HexDump&);
private:
	static const int BUFFER_SIZE = 8192;
	std::ifstream in_file;
	int file_size = 0;
	char buffer[BUFFER_SIZE];
	
	string file_name, content = "";

	void read_file();
};

void HexDump::read_file(){
	int bytes_read = 0;
	in_file.open( file_name, std::ios::binary );
	if( in_file.is_open() ){
		while( !in_file.eof() ){
			in_file.read(buffer,  BUFFER_SIZE);
			bytes_read = in_file.gcount();
			file_size += bytes_read;
			content += string(std::begin(buffer), std::begin(buffer)+bytes_read);
		}
		cout<<"File Size: "<<file_size<<endl;
		in_file.close();
	} else 
		throw std::runtime_error("File not found: " + file_name);
}

std::ostream& operator<<(std::ostream &os, const HexDump &dump){
	char c;
	string raw_hex;
	
	for( int i=0, j=0; i<dump.file_size; i+=16){
		j=0;
		os<<std::setw(16)<<std::setfill('0')<<std::hex<<i;
		os<<"\t";
		while( j<16 && (i+j)<dump.file_size){ 
			c = dump.content[i+j];
			os<<std::setw(3)<<std::hex<<std::setfill(' ')<<((int)c & 255);
			j++;
		}
		if( j != 16 ) 
			while(j<16){
				os<<"   ";
				j++;
			} 

		j=0;
		os<<"\t";
		while( j<16 && (i+j)<dump.file_size){
			c = dump.content[i+j];
			if( std::isprint(c)) 
				os<<c;
			else
				os<<".";
			j++;
		}
		os<<endl;
		
	}
	return os;
}
