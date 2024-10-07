// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read/COR)
//         bit 7  - auto_restart (Read/Write)
//         bit 9  - interrupt (Read)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0 - enable ap_done interrupt (Read/Write)
//         bit 1 - enable ap_ready interrupt (Read/Write)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0 - ap_done (Read/TOW)
//         bit 1 - ap_ready (Read/TOW)
//         others - reserved
// 0x010 : Data signal of source
//         bit 7~0 - source[7:0] (Read/Write)
//         others  - reserved
// 0x014 : reserved
// 0x080 ~
// 0x0ff : Memory 'dist_0' (32 * 32b)
//         Word n : bit [31:0] - dist_0[n]
// 0x100 ~
// 0x17f : Memory 'dist_1' (32 * 32b)
//         Word n : bit [31:0] - dist_1[n]
// 0x180 ~
// 0x1ff : Memory 'dist_2' (32 * 32b)
//         Word n : bit [31:0] - dist_2[n]
// 0x200 ~
// 0x27f : Memory 'dist_3' (32 * 32b)
//         Word n : bit [31:0] - dist_3[n]
// 0x800 ~
// 0xfff : Memory 'edges' (160 * 64b)
//         Word 2n   : bit [31:0] - edges[n][31: 0]
//         Word 2n+1 : bit [31:0] - edges[n][63:32]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBELLMAN_FORD_CONTROL_ADDR_AP_CTRL     0x000
#define XBELLMAN_FORD_CONTROL_ADDR_GIE         0x004
#define XBELLMAN_FORD_CONTROL_ADDR_IER         0x008
#define XBELLMAN_FORD_CONTROL_ADDR_ISR         0x00c
#define XBELLMAN_FORD_CONTROL_ADDR_SOURCE_DATA 0x010
#define XBELLMAN_FORD_CONTROL_BITS_SOURCE_DATA 8
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_0_BASE 0x080
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_0_HIGH 0x0ff
#define XBELLMAN_FORD_CONTROL_WIDTH_DIST_0     32
#define XBELLMAN_FORD_CONTROL_DEPTH_DIST_0     32
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_1_BASE 0x100
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_1_HIGH 0x17f
#define XBELLMAN_FORD_CONTROL_WIDTH_DIST_1     32
#define XBELLMAN_FORD_CONTROL_DEPTH_DIST_1     32
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_2_BASE 0x180
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_2_HIGH 0x1ff
#define XBELLMAN_FORD_CONTROL_WIDTH_DIST_2     32
#define XBELLMAN_FORD_CONTROL_DEPTH_DIST_2     32
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_3_BASE 0x200
#define XBELLMAN_FORD_CONTROL_ADDR_DIST_3_HIGH 0x27f
#define XBELLMAN_FORD_CONTROL_WIDTH_DIST_3     32
#define XBELLMAN_FORD_CONTROL_DEPTH_DIST_3     32
#define XBELLMAN_FORD_CONTROL_ADDR_EDGES_BASE  0x800
#define XBELLMAN_FORD_CONTROL_ADDR_EDGES_HIGH  0xfff
#define XBELLMAN_FORD_CONTROL_WIDTH_EDGES      64
#define XBELLMAN_FORD_CONTROL_DEPTH_EDGES      160

