#ifndef SigpolyLUTWORKS_H
#define SigpolyLUTWORKS_H
#include "functions.h"
#include <spec/sp_lut.h>
#include <istream>
#include <ostream>
#include <cinttypes>

using spec::SigpolyLUT;

void write_header(std::ostream &dst);
void write_lut(std::ostream &dst, const SigpolyLUT &lut);

SigpolyLUT generate_lut(int zeroed_idx, int step = 4, int stable_val = 24);

#endif