//////////////////////////////////////////////////////////////////////////////
// * File name: main.c
// *
// * Description:  Vezba 1 - Interpolacija i decimacija
// *
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *
//////////////////////////////////////////////////////////////////////////////

#include "tistdtypes.h"
#include <cstdio>
#include "ezdsp5535.h"
#include "math.h"
#include "signal.h"
#include "filter_coeff.h"
#include "processing.h"


Int16 output_buffer[1024];
Int16 input_buffer[1024];
/*
 *
 *  main( )
 *
 */
void main( void )
{

	//Int16 input[1024];
	Int16 output[1024];

	int i = 0;

	printf("\n Vezba 1 - Interpolacija i decimacija \n");
	
	/* Your code here */

	//downsample(signal1, output, 4, 1024);

	//decimate(signal1, output, 4, 1024);

	//upsample(signal1, output, 4, 1024);

	//interpolate(signal1, output, 4, 1024);

	resample(signal1, output, 3, 4, 256);

	for (i = 0; i < 1024; i++) {
		output_buffer[i] = output[i];
		input_buffer[i] = signal1[i];
	}

	printf( "\n***Program has Terminated***\n" );
	SW_BREAKPOINT;
}

