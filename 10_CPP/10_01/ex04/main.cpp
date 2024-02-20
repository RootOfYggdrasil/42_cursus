
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string readFileToString(std::ifstream& fileStream) {
    std::ostringstream buffer;
    buffer << fileStream.rdbuf(); // Read the entire file into the stringstream buffer
    return buffer.str(); // Convert the stringstream buffer to a string and return
}

void replaceString(std::string& str, const std::string& s1, const std::string& s2) 
{
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos) {
		str.erase(pos, s1.length());
		str.insert(pos, s2);
	}
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) 
{
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}
	std::ofstream outFile(filename + ".replace");
	if (!outFile) {
		std::cerr << "Error: could not create file " << filename + ".replace" << std::endl;
		return;
	}
	std::string strFile = readFileToString(inFile);
	replaceString(strFile, s1, s2);
	outFile << strFile;
	inFile.close();
	outFile.close();
}

int main(int argc, char* argv[]) 
{
	if (argc != 4 || std::string(argv[2]).empty()){
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2> - <s1> must not be EMPTY" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replaceInFile(filename, s1, s2);
	return 0;
}