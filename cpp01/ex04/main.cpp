#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

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
	std::cout << str;
	return (0);
}