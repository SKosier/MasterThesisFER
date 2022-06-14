#include <iostream>
#include <string.h>

using namespace std;

const uint8_t no_conv_type = 0;
const uint8_t ct_conv_type = 1;
const uint8_t ga_conv_type = 2;

const char *rcsymbol = "TGCAN";
uint8_t code[256];

void make_code(void) {
    for (size_t i = 0; i < 256; i++)
        code[i] = 4;

    code['A'] = code['a'] = 0;
    code['C'] = code['c'] = 1;
    code['G'] = code['g'] = 2;
    code['T'] = code['t'] = 3;

    // we set N's also to 0. Shouldn't matter as index construction logic
    // doesn't consider kmers with Ns anyway
    code['N'] = code['n'] = 0;
}

void parse(char seq[], char fwd[], char rev[], char rev_str[], uint8_t conversion_type) {
    unsigned len = strlen(seq);

    for (size_t i = 0; i < len; i++) {
        uint8_t c = *(code + seq[i]);

        // check if we should convert sequence to ct
        if (conversion_type == ct_conv_type && c == 1) {
            // convert c to t
            c = 3;

            // else check if we need to convert to ga
        } else if (conversion_type == ga_conv_type && c == 2) {
            c = 0;
        }


        fwd[i] = c;
        rev[len - 1 - i] = c == 4 ? c : 3 - c;
        rev_str[len - 1 - i] = rcsymbol[c];
    }
    *(fwd + len) = '\0';
    *(rev + len) = '\0';
    *(rev_str + len) = '\0';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    make_code();
    char *fwd = static_cast<char *>(malloc(sizeof(char) * (512 + 1)));
    char *rev = static_cast<char *>(malloc(sizeof(char) * (512 + 1)));
    char *rev_str = static_cast<char *>(malloc(sizeof(char) * (512 + 1)));

































































    r

    parse("ATAAGAAAATCAAATATGCTTTATTTCACCCAATTAACATGGCTATCCCGGGAAAACCAA", fwd, rev, rev_str, ga_conv_type);

    cerr << "ATAAGAAAATCAAATATGCTTTATTTCACCCAATTAACATGGCTATCCCGGGAAAACCAA" << endl;
    cerr << fwd << endl;
    cerr << rev << endl;
    cerr << rev_str << endl;

    return 0;
}
