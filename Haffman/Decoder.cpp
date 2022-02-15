#include "Decoder.h"

void Decoder::read_tree() {
	input_.open("gen_out.txt");
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

void Decoder::decode() {
	input_.open("enc_out.txt");
	output_.open("dec_out.txt");
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
