#include <string>
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	std::string	str;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (unsigned long j = 0; j < str.size(); j++)
		{
			std::cout << (char)toupper(str[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}