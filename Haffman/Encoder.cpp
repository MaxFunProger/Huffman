#include "Encoder.h"

void Encoder::read_table() {
	input_.open("gen_out_table.txt");
	int n;
	input_ >> n;
	int symbol;
	std::string tmp;
	for (int i = 0; i < n; ++i) {
		input_ >> symbol >> tmp;
		table_[unsigned char(symbol)] = tmp;
	}
	input_.close();
}


void Encoder::encode() {
	input_.open("input.txt");
	std::string tmp;

	while (std::getline(input_, tmp)) {
		tmp.push_back('\n');
		text_ += tmp;
	}

	for (auto& i : text_) {
		text_encoded_ += table_[i];
	}
	output_.open("enc_out.txt");
	output_ << text_encoded_;
	output_.close();
}