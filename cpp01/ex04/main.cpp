#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>

std::string replace(std::string content, std::string s1, std::string s2){
	if (s1.empty())
		return (content);
	size_t nextfind = content.find(s1);

	while (nextfind != std::string::npos){
		content.erase(nextfind, s1.size());
		content.insert(nextfind, s2);
		nextfind += s2.size();
		nextfind = content.find(s1, nextfind);
	}
	return (content);
}

int main(int argc, char **argv){	
	if (argc != 4){
		std::cerr << "Invalid number of arguments!" << std::endl;
		return (1);
	}
	struct stat buf;
	stat(argv[1], &buf);
	if (S_ISDIR(buf.st_mode)){
		std::cerr << "Error: " << argv[1] << ": Path is a directory" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (infile.fail()){
		std::cerr << "Error: " << argv[1] << ": incorrect path or missing permissions" << std::endl; 
		return (1);
	}
	std::string str;
	std::stringstream buffer;
	buffer << infile.rdbuf();
	str = buffer.str();
	str = replace(str, argv[2], argv[3]);
	std::string name = argv[1];
	name += ".replace";
	std::ofstream outfile(name.c_str());
	if (outfile.fail()){
		std::cerr << "Error: " << name << ": output file failed" << std::endl;
		return (1);
	}
	outfile << str;
	infile.close();
	outfile.close();
	return (0);
}
