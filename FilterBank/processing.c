/*
 * processing.c
 *
 *  Created on: 29.02.2016.
 *      Author: Dejan Bokan (dejan.bokan@rt-rk.com)
 */

#include "processing.h"
#include "fir.h"
#include "filter_coeff.h"

Int16 history[N_COEFF];
int i = 0;
int j = 0;


void downsample(Int16 *input, Int16 *output, int M, int N)
{
	/* your code here... */

	//int len = N/M;

	for (i = 0, j = 0; i < N; i += M, j++) {
		output[j] = input[i];
	}
}

void decimate(Int16 *input, Int16 *output, int M, int N, Int16* filter, Int16* history)
{
	/* your code here... */

	for (i = 0; i < 1024; i++) {
		input[i] = fir_basic(input[i], filter, history, N_COEFF);
	}

	downsample(input, output, M, N);

}

void upsample(Int16 *input, Int16 *output, int L, int N)
{
	/* your code here... */

	for (i = 0; i < L*N; i++) {
		output[i] = 0;
	}

	for(i = 0, j = 0; i < N; i++, j += L) {
		output[j] = input[i];
	}
}

void interpolate(Int16 *input, Int16 *output, int L, int N, Int16* filter, Int16* history)
{
	/* your code here... */

	upsample(input, output, L, N);

	for (i = 0; i < 1024; i++) {
		output[i] = fir_basic(output[i], filter, history, N_COEFF);
	}

}

void resample(Int16 *input, Int16 *output, int L, int M, int N, Int16* filter, Int16* history)
{
	/* your code here... */

	upsample(input, output, L, N);

	for (i = 0; i < L*N; i++) {
		input[i] = fir_basic(output[i], filter, history, N_COEFF);
	}

	downsample(input, output, M, L*N);
}
