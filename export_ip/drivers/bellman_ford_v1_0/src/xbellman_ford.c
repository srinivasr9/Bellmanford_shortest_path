// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xbellman_ford.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XBellman_ford_CfgInitialize(XBellman_ford *InstancePtr, XBellman_ford_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XBellman_ford_Start(XBellman_ford *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL) & 0x80;
    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XBellman_ford_IsDone(XBellman_ford *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XBellman_ford_IsIdle(XBellman_ford *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XBellman_ford_IsReady(XBellman_ford *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XBellman_ford_EnableAutoRestart(XBellman_ford *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XBellman_ford_DisableAutoRestart(XBellman_ford *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL, 0);
}

void XBellman_ford_Set_source(XBellman_ford *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_SOURCE_DATA, Data);
}

u32 XBellman_ford_Get_source(XBellman_ford *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_SOURCE_DATA);
    return Data;
}

u32 XBellman_ford_Get_dist_0_BaseAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE);
}

u32 XBellman_ford_Get_dist_0_HighAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH);
}

u32 XBellman_ford_Get_dist_0_TotalBytes(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + 1);
}

u32 XBellman_ford_Get_dist_0_BitWidth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_WIDTH_DIST_0;
}

u32 XBellman_ford_Get_dist_0_Depth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_DEPTH_DIST_0;
}

u32 XBellman_ford_Write_dist_0_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_0_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XBellman_ford_Write_dist_0_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_0_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE + offset + i);
    }
    return length;
}

u32 XBellman_ford_Get_dist_1_BaseAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE);
}

u32 XBellman_ford_Get_dist_1_HighAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH);
}

u32 XBellman_ford_Get_dist_1_TotalBytes(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + 1);
}

u32 XBellman_ford_Get_dist_1_BitWidth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_WIDTH_DIST_1;
}

u32 XBellman_ford_Get_dist_1_Depth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_DEPTH_DIST_1;
}

u32 XBellman_ford_Write_dist_1_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_1_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XBellman_ford_Write_dist_1_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_1_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE + offset + i);
    }
    return length;
}

u32 XBellman_ford_Get_dist_2_BaseAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE);
}

u32 XBellman_ford_Get_dist_2_HighAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH);
}

u32 XBellman_ford_Get_dist_2_TotalBytes(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + 1);
}

u32 XBellman_ford_Get_dist_2_BitWidth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_WIDTH_DIST_2;
}

u32 XBellman_ford_Get_dist_2_Depth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_DEPTH_DIST_2;
}

u32 XBellman_ford_Write_dist_2_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_2_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XBellman_ford_Write_dist_2_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_2_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE + offset + i);
    }
    return length;
}

u32 XBellman_ford_Get_dist_3_BaseAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE);
}

u32 XBellman_ford_Get_dist_3_HighAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH);
}

u32 XBellman_ford_Get_dist_3_TotalBytes(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + 1);
}

u32 XBellman_ford_Get_dist_3_BitWidth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_WIDTH_DIST_3;
}

u32 XBellman_ford_Get_dist_3_Depth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_DEPTH_DIST_3;
}

u32 XBellman_ford_Write_dist_3_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_3_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XBellman_ford_Write_dist_3_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_dist_3_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH - XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE + offset + i);
    }
    return length;
}

u32 XBellman_ford_Get_edges_BaseAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE);
}

u32 XBellman_ford_Get_edges_HighAddress(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH);
}

u32 XBellman_ford_Get_edges_TotalBytes(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH - XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + 1);
}

u32 XBellman_ford_Get_edges_BitWidth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_WIDTH_EDGES;
}

u32 XBellman_ford_Get_edges_Depth(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBELLMAN_FORD_CONTROL_DEPTH_EDGES;
}

u32 XBellman_ford_Write_edges_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH - XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_edges_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH - XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + (offset + i)*4);
    }
    return length;
}

u32 XBellman_ford_Write_edges_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH - XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XBellman_ford_Read_edges_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH - XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE + offset + i);
    }
    return length;
}

void XBellman_ford_InterruptGlobalEnable(XBellman_ford *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_GIE, 1);
}

void XBellman_ford_InterruptGlobalDisable(XBellman_ford *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_GIE, 0);
}

void XBellman_ford_InterruptEnable(XBellman_ford *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_IER);
    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_IER, Register | Mask);
}

void XBellman_ford_InterruptDisable(XBellman_ford *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_IER);
    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_IER, Register & (~Mask));
}

void XBellman_ford_InterruptClear(XBellman_ford *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBellman_ford_WriteReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_ISR, Mask);
}

u32 XBellman_ford_InterruptGetEnabled(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_IER);
}

u32 XBellman_ford_InterruptGetStatus(XBellman_ford *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBellman_ford_ReadReg(InstancePtr->Control_BaseAddress, XBELLMAN_FORD_CONTROL_ADDR_ISR);
}

