#include "Decoder.h"

void Decoder::read_tree(std::string file) {
	input_.open(file);
	std::string s;
	tree_ = new Node2(nullptr, nullptr, ' ');
	lcr_read(tree_);
	input_.close();
}

void Decoder::lcr_read(Node2* cur) {
	std::string s;
	if (std::getline(input_, s)) {
		if (s == "l") {
			cur->left_ = new Node2();
			lcr_read(cur->left_);
			std::getline(input_, s);
			cur->right_ = new Node2();
			lcr_read(cur->right_);
		}
		else {
			cur->left_ = nullptr;
			cur->right_ = nullptr;
			cur->symbol = unsigned char(stoi(s));
			return;
		}
	}
	else {
		return;
	}
	return;
}

void Decoder::decode(std::string file_in, std::string file_out) {
	input_.open(file_in);
	output_.open(file_out);
	input_ >> text_encoded_;
	Node2* pointer;
	pointer = tree_;
	std::string text;
	for (auto& i : text_encoded_) {
		if (i == '0') {
			if (pointer->left_ != nullptr) {
				pointer = pointer->left_;
			}
			else {
				output_ << pointer->symbol;
				text.push_back(pointer->symbol);
				pointer = tree_->left_;
			}
		}
		else {
			if (pointer->right_ != nullptr) {
				pointer = pointer->right_;
			}
			else {
				output_ << pointer->symbol;
				text.push_back(pointer->symbol);

				pointer = tree_->right_;
			}
		}
	}
	output_.close();
}
