#include "Generator.h"

void Generator::read_text(std::string file) {

	input_.open(file);

	std::string s;

	while (std::getline(input_, s)) {
		s.push_back('\n');
		text_ += s;
	}

}


void Generator::build_tree() {

	for (auto& i : text_) {
		++counter_[i];
	}
	auto cmp = [](std::pair<int, Node*> a, std::pair<int, Node*> b) {
		if (a.first == b.first) {
			return a.second->number < b.second->number;
		}
		return  a.first < b.first;
	};
	std::set<std::pair<int, Node*>, decltype(cmp)> se(cmp);
	int nb = 0;
	for (auto& [key, value] : counter_) {
		Node* tmp = new Node(nullptr, nullptr, unsigned char(key));
		tmp->flag = true;
		tmp->number = nb;
		++nb;
		se.insert(std::make_pair(counter_[key], tmp));
	}

	int cnt = counter_.size();
	while (se.size() > 1) {
		std::pair<int, Node*> left_ = *se.begin();
		se.erase(se.begin());
		std::pair<int, Node*> right_ = *se.begin();
		se.erase(se.begin());



		Node* tmp = new Node(left_.second, right_.second, ' ');
		tmp->number = nb;
		++nb;
		se.insert(std::make_pair(left_.first + right_.first, tmp));
	}
	tree_ = se.begin()->second;

}


void Generator::lcr(Node* cur, std::string s) {
	++size;
	if (cur->left_ != nullptr) {
		lcr(cur->left_, s + "0");
	}
	if (cur->right_ != nullptr) {
		lcr(cur->right_, s + "1");
	}
	if (cur->left_ == nullptr && cur->right_ == nullptr) {
		table_[cur->symbol] = s;
	}
}

void Generator::build_table() {
	lcr(tree_, "");
}

void Generator::encode() {
	for (auto& i : text_) {
		result_ += table_[i];
	}
}

void Generator::lcr_out(Node* cur) {

	if (cur->left_ != nullptr) {
		output_ << "l" << '\n';
		lcr_out(cur->left_);
		output_ << "r" << '\n';
		lcr_out(cur->right_);
	}
	else {
		output_ << int(cur->symbol) << '\n';
		return;
	}
}

void Generator::print_tree(std::string file) {
	output_.open(file);
	lcr_out(tree_);
	output_.close();

}

void Generator::print_table(std::string file) {
	output_.open(file);
	output_ << table_.size() << '\n';
	for (auto& [key, value] : table_) {
		output_ << int(key) << ' ' << value << '\n';
	}
	output_.close();
}