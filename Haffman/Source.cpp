#include "Generator.h"
#include "Decoder.h"
#include "Encoder.h"


int main() {
	Generator* gen = new Generator();
	Encoder* enc = new Encoder();
	Decoder* dec = new Decoder();

	gen->read_text("input.txt");
	gen->build_tree();
	gen->build_table();
	gen->print_tree("gen_out.txt");
	gen->print_table("gen_out_table.txt");

	enc->read_table("gen_out_table.txt");
	enc->encode("input.txt");

	dec->read_tree("gen_out.txt");
	dec->decode("enc_out.txt", "dec_out.txt");
	return 0;
}