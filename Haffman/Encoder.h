#pragma once

#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <fstream>

class Encoder {
public:
	void encode(std::string);
	void read_table(std::string);
private:
	std::string text_;
	std::string text_encoded_;
	std::map<unsigned char, std::string> table_;
	std::ifstream input_;
	std::ofstream output_;
};