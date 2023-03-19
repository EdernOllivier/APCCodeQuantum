#include <NIDAQmx.h>
#include <ansi_c.h>
//==============================================================================
//
// Title:       main.c
// Purpose:     A short description of the implementation.
//
// Created on:  09/04/2009 at 14:50:00 by edern ollivier.
// Copyright:   APC. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "dac.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

void main (void)
{
	int i;
	
	for(i = 0; i < 10; i++)
		printf("hello ...\n");

	TaskHandle task;

	CreateDAC(&task);
	
	int8 data[200];

	//DOUT = [x][x][0][0][D7][D6][D5][D4][D3][D2][D1][D0][x][x][x][x]
	for(i = 0; i < 6; i++)
		data[i] = 0;
	data[6] = 1;
	data[7] = 1;
	data[8] = 1;
	data[9] = 0;
	data[10] = 1;
	data[11] = 1;
	data[12] = 1;
	data[13] = 1;
	for(i = 14; i < 18; i++)
		data[i] = 0;
	for(i = 18; i < 100; i++)
		data[i] = 0;

	//SYNCB
	for(i = 100; i < 102; i++)
		data[i] = 1;
	for(i = 102; i < 200; i++)
		data[i] = 0;
	
	int nb = 0;
	
	DAQmxWriteDigitalLines(task, 100, 1, 10, DAQmx_Val_GroupByChannel, data, &nb, NULL);
	
	printf("%i echantillons écrits\n", nb);
	
	DAQmxClearTask(task);

	for(i = 0; i < 10; i++)
		printf("bye ...\n");
}
