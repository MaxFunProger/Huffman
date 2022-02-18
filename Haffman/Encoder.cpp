#include "Encoder.h"

void Encoder::read_table(std::string file) {
	input_.open(file);
	int n, flag = 0;
	//input_ >> n;
	int symbol;
	std::string tmp, s, tmp2;
	while (std::getline(input_, s)){
		for (auto& i : s) {
			if (i != ' ' && !flag) {
				tmp.push_back(i);
			}
			else {
				flag = 1;
				if (i == ' ')
					continue;
				tmp2.push_back(i);
			}
		}
		table_[unsigned char(stoi(tmp))] = tmp2;
		tmp = "";
		tmp2 = "";
		flag = 0;
	}
	/*for (int i = 0; i < n; ++i) {
		input_ >> symbol >> tmp;
		table_[unsigned char(symbol)] = tmp;
	}*/
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