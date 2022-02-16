#include "Encoder.h"

void Encoder::read_table(std::string file) {
	input_.open(file);
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


void Encoder::encode(std::string file) {
	input_.open(file);
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