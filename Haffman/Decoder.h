#pragma once

#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>


struct Node2 {
	Node2() = default;
	Node2(Node2* left_, Node2* right_, unsigned char symbol) : left_(left_), right_(right_), symbol(symbol) {}

	Node2* left_ = nullptr;
	Node2* right_ = nullptr;
	Node2* parent_ = nullptr;
	bool used = 0;
	unsigned char symbol;

};

class Decoder {
public:
	void read_tree(std::string);

	void decode(std::string, std::string);

private:
	void lcr_read(Node2*);
	std::string text_encoded_;
	std::string text_;
	std::ifstream input_;
	std::ofstream output_;
	Node2* tree_;
};