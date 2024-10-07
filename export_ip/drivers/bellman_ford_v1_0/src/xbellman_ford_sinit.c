// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xbellman_ford.h"

extern XBellman_ford_Config XBellman_ford_ConfigTable[];

XBellman_ford_Config *XBellman_ford_LookupConfig(u16 DeviceId) {
	XBellman_ford_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XBELLMAN_FORD_NUM_INSTANCES; Index++) {
		if (XBellman_ford_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XBellman_ford_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBellman_ford_Initialize(XBellman_ford *InstancePtr, u16 DeviceId) {
	XBellman_ford_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBellman_ford_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBellman_ford_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

