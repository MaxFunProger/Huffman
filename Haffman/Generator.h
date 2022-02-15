#pragma once

#include <set>
#include <iostream>
#include <time.h>
#include <random>
#include <string>
#include <string.h>
#include <map>
#include <fstream>

struct Node {
	Node(Node* left_, Node* right_, unsigned char symbol) : left_(left_), right_(right_), symbol(symbol) {}

	Node* left_;
	Node* right_;
	unsigned char symbol;
	int number;
	bool flag = false;
};

class Generator {
public:

	void read_text();

	void build_tree();

	void print_tree();

	void build_table();

	void print_table();

	void encode();

private:


	void lcr(Node*, std::string);
	void lcr_out(Node*);
	std::string text_;
	std::map<unsigned char, int> counter_;
	Node* tree_;
	std::map<unsigned char, std::string> table_;
	std::string result_;
	std::ofstream output_;
	std::ifstream input_;
	int number_ = 0;
	int size = 0;
};