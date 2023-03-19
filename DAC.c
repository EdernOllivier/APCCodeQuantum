//**************************************************************************
//* WARNING: This file was automatically generated.  Any changes you make  *
//*          to this file will be lost if you generate the file again.     *
//**************************************************************************
#include <ansi_c.h>
#include <NIDAQmx.h>

#define DAQmxErrChk(functionCall) {DAQmxError = (functionCall);  {if (DAQmxError < 0){goto Error;}}}

//**************************************************************************
//* This generated function configures your DAQmx task.                    *
//*                                                                        *
//* Follow these steps to use this generated function:                     *
//*   1) Define a task handle variable in your program.                    *
//*   2) Call the generated function.                                      *
//*   3) Use the returned task handle as a parameter to other DAQmx        *
//*      functions.                                                        *
//*   4) Clear the task handle when you finish.                            *
//*                                                                        *
//*         TaskHandle task = 0;                                           *
//*         CreateDAQTask(&task);                                          *
//*         <use the DAQmx task handle>                                    *
//*         DAQmxClearTask(task);                                          *
//*                                                                        *
//**************************************************************************
int32 CreateDAC(TaskHandle *taskOut1)
{
	int32 DAQmxError = DAQmxSuccess;
    TaskHandle taskOut;

	DAQmxErrChk(DAQmxCreateTask("DAC", &taskOut));

	DAQmxErrChk(DAQmxCreateDOChan(taskOut, "PXI1Slot2/port0/line0", 
		"DOUT", DAQmx_Val_ChanPerLine)); 


	DAQmxErrChk(DAQmxCreateDOChan(taskOut, "PXI1Slot2/port0/line7", 
		"SYNCB", DAQmx_Val_ChanPerLine)); 


	DAQmxErrChk(DAQmxCfgSampClkTiming(taskOut, "PFI0", 
		1000000, DAQmx_Val_Rising, 
		DAQmx_Val_ContSamps, 40));

	DAQmxErrChk(DAQmxSetWriteAttribute(taskOut, DAQmx_Write_RegenMode, DAQmx_Val_DoNotAllowRegen));

    *taskOut1 = taskOut;

Error:
	return DAQmxError;
}

