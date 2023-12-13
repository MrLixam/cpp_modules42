#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>

void replace(std::string filename, std::string s1, std::string s2){
	std::string newFile = filename + ".replace";
	
	std::ofstream outfile(newFile);
	outfile.close();
}

int main(int argc, char **argv){	
	if (argc != 4){
		std::cerr << "Invalid number of arguments!" << std::endl;
		return (1);
	}

	std::ifstream infile(argv[1]);

	if (infile.fail()){
		std::cerr << "Error: " << argv[1] << ": File Error" << std::endl; 
		return (1);
	}
	std::string str;
	std::stringstream buffer;
	buffer << infile.rdbuf();
	str = buffer.str();
	replace(argv[1], argv[2], argv[3]);
	return (0);
}