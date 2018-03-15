/*
 * processing.h
 *
 *  Created on: 29.02.2016.
 *       Author: Dejan Bokan (dejan.bokan@rt-rk.com)
 */
#include "tistdtypes.h"

#ifndef PROCESSING_H_
#define PROCESSING_H_

void downsample(Int16 *input, Int16 *output, int M, int N);

void decimate(Int16 *input, Int16 *output, int M, int N, Int16* filter, Int16* history);

void upsample(Int16 *input, Int16 *output, int L, int N);

void interpolate(Int16 *input, Int16 *output, int L, int N, Int16* filter, Int16* history);

void resample(Int16 *input, Int16 *output, int L, int M, int N, Int16* filter, Int16* history);

#endif /* PROCESSING_H_ */
