// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XBELLMAN_FORD_H
#define XBELLMAN_FORD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xbellman_ford_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XBellman_ford_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XBellman_ford;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBellman_ford_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBellman_ford_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBellman_ford_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBellman_ford_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XBellman_ford_Initialize(XBellman_ford *InstancePtr, u16 DeviceId);
XBellman_ford_Config* XBellman_ford_LookupConfig(u16 DeviceId);
int XBellman_ford_CfgInitialize(XBellman_ford *InstancePtr, XBellman_ford_Config *ConfigPtr);
#else
int XBellman_ford_Initialize(XBellman_ford *InstancePtr, const char* InstanceName);
int XBellman_ford_Release(XBellman_ford *InstancePtr);
#endif

void XBellman_ford_Start(XBellman_ford *InstancePtr);
u32 XBellman_ford_IsDone(XBellman_ford *InstancePtr);
u32 XBellman_ford_IsIdle(XBellman_ford *InstancePtr);
u32 XBellman_ford_IsReady(XBellman_ford *InstancePtr);
void XBellman_ford_EnableAutoRestart(XBellman_ford *InstancePtr);
void XBellman_ford_DisableAutoRestart(XBellman_ford *InstancePtr);

void XBellman_ford_Set_source(XBellman_ford *InstancePtr, u32 Data);
u32 XBellman_ford_Get_source(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_0_BaseAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_0_HighAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_0_TotalBytes(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_0_BitWidth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_0_Depth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Write_dist_0_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Read_dist_0_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Write_dist_0_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Read_dist_0_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Get_dist_1_BaseAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_1_HighAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_1_TotalBytes(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_1_BitWidth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_1_Depth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Write_dist_1_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Read_dist_1_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Write_dist_1_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Read_dist_1_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Get_dist_2_BaseAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_2_HighAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_2_TotalBytes(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_2_BitWidth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_2_Depth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Write_dist_2_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Read_dist_2_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Write_dist_2_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Read_dist_2_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Get_dist_3_BaseAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_3_HighAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_3_TotalBytes(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_3_BitWidth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_dist_3_Depth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Write_dist_3_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Read_dist_3_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Write_dist_3_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Read_dist_3_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Get_edges_BaseAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_edges_HighAddress(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_edges_TotalBytes(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_edges_BitWidth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Get_edges_Depth(XBellman_ford *InstancePtr);
u32 XBellman_ford_Write_edges_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Read_edges_Words(XBellman_ford *InstancePtr, int offset, word_type *data, int length);
u32 XBellman_ford_Write_edges_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);
u32 XBellman_ford_Read_edges_Bytes(XBellman_ford *InstancePtr, int offset, char *data, int length);

void XBellman_ford_InterruptGlobalEnable(XBellman_ford *InstancePtr);
void XBellman_ford_InterruptGlobalDisable(XBellman_ford *InstancePtr);
void XBellman_ford_InterruptEnable(XBellman_ford *InstancePtr, u32 Mask);
void XBellman_ford_InterruptDisable(XBellman_ford *InstancePtr, u32 Mask);
void XBellman_ford_InterruptClear(XBellman_ford *InstancePtr, u32 Mask);
u32 XBellman_ford_InterruptGetEnabled(XBellman_ford *InstancePtr);
u32 XBellman_ford_InterruptGetStatus(XBellman_ford *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
