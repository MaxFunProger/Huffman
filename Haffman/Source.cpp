#include "Generator.h"
#include "Decoder.h"
#include "Encoder.h"


int main() {
	Generator* gen = new Generator();
	Encoder* enc = new Encoder();
	Decoder* dec = new Decoder();

	gen->read_text();
	gen->build_tree();
	gen->build_table();
	gen->print_tree();
	gen->print_table();

	enc->read_table();
	enc->encode();

	dec->read_tree();
	dec->decode();
	return 0;
}