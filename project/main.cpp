#include <iostream>
#include "bioparser/fasta_parser.hpp"
#include "bioparser/fastq_parser.hpp"

struct Sequence {  // or any other name
public:
    Sequence(  // required arguments
            const char*, std::uint32_t,
            const char*, std::uint32_t) {
        // implementation
    }
};

int main() {
    auto p = bioparser::Parser<Sequence>::Create<bioparser::FastaParser>("/home/vagabundo/Documents/genome/Homo_sapiens.GRCh38.dna.chromosome.1.fa.gz");
    // parse whole file
    auto s = p->Parse(-1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
