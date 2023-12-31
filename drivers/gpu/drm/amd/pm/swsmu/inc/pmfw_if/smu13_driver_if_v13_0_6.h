/*
 * Copyright 2021 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef SMU_13_0_6_DRIVER_IF_H
#define SMU_13_0_6_DRIVER_IF_H

// *** IMPORTANT ***
// PMFW TEAM: Always increment the interface version if
// anything is changed in this file
#define SMU13_0_6_DRIVER_IF_VERSION 0x08042023

//I2C Interface
#define NUM_I2C_CONTROLLERS                8
#define I2C_CONTROLLER_ENABLED             1
#define I2C_CONTROLLER_DISABLED            0

#define MAX_SW_I2C_COMMANDS                24

typedef enum {
  I2C_CONTROLLER_PORT_0, //CKSVII2C0
  I2C_CONTROLLER_PORT_1, //CKSVII2C1
  I2C_CONTROLLER_PORT_COUNT,
} I2cControllerPort_e;

typedef enum {
  UNSUPPORTED_1,              //50  Kbits/s not supported anymore!
  I2C_SPEED_STANDARD_100K,    //100 Kbits/s
  I2C_SPEED_FAST_400K,        //400 Kbits/s
  I2C_SPEED_FAST_PLUS_1M,     //1   Mbits/s (in fast mode)
  UNSUPPORTED_2,              //1   Mbits/s (in high speed mode)  not supported anymore!
  UNSUPPORTED_3,              //2.3 Mbits/s  not supported anymore!
  I2C_SPEED_COUNT,
} I2cSpeed_e;

typedef enum {
  I2C_CMD_READ,
  I2C_CMD_WRITE,
  I2C_CMD_COUNT,
} I2cCmdType_e;

#define CMDCONFIG_STOP_BIT             0
#define CMDCONFIG_RESTART_BIT          1
#define CMDCONFIG_READWRITE_BIT        2 //bit should be 0 for read, 1 for write

#define CMDCONFIG_STOP_MASK           (1 << CMDCONFIG_STOP_BIT)
#define CMDCONFIG_RESTART_MASK        (1 << CMDCONFIG_RESTART_BIT)
#define CMDCONFIG_READWRITE_MASK      (1 << CMDCONFIG_READWRITE_BIT)

typedef struct {
  uint8_t ReadWriteData;  //Return data for read. Data to send for write
  uint8_t CmdConfig; //Includes whether associated command should have a stop or restart command, and is a read or write
} SwI2cCmd_t; //SW I2C Command Table

typedef struct {
  uint8_t    I2CcontrollerPort; //CKSVII2C0(0) or //CKSVII2C1(1)
  uint8_t    I2CSpeed;          //Use I2cSpeed_e to indicate speed to select
  uint8_t    SlaveAddress;      //Slave address of device
  uint8_t    NumCmds;           //Number of commands
  SwI2cCmd_t SwI2cCmds[MAX_SW_I2C_COMMANDS];
} SwI2cRequest_t; // SW I2C Request Table

typedef struct {
  SwI2cRequest_t SwI2cRequest;
  uint32_t       Spare[8];
  uint32_t       MmHubPadding[8]; // SMU internal use
} SwI2cRequestExternal_t;

typedef enum {
  PPCLK_VCLK,
  PPCLK_DCLK,
  PPCLK_SOCCLK,
  PPCLK_UCLK,
  PPCLK_FCLK,
  PPCLK_LCLK,
  PPCLK_COUNT,
} PPCLK_e;

typedef enum {
  GPIO_INT_POLARITY_ACTIVE_LOW,
  GPIO_INT_POLARITY_ACTIVE_HIGH,
} GpioIntPolarity_e;

//TODO confirm if this is used in SMU_13_0_6 PPSMC_MSG_SetUclkDpmMode
typedef enum {
  UCLK_DPM_MODE_BANDWIDTH,
  UCLK_DPM_MODE_LATENCY,
} UCLK_DPM_MODE_e;

typedef struct {
  //0-23 SOC, 24-26 SOCIO, 27-29 SOC
  uint16_t avgPsmCount[30];
  uint16_t minPsmCount[30];
  float    avgPsmVoltage[30];
  float    minPsmVoltage[30];
} AvfsDebugTableAid_t;

typedef struct {
  //0-27 GFX, 28-29 SOC
  uint16_t avgPsmCount[30];
  uint16_t minPsmCount[30];
  float    avgPsmVoltage[30];
  float    minPsmVoltage[30];
} AvfsDebugTableXcd_t;

// Defines used for IH-based thermal interrupts to GFX driver - A/X only
#define IH_INTERRUPT_ID_TO_DRIVER                   0xFE
#define IH_INTERRUPT_CONTEXT_ID_THERMAL_THROTTLING  0x7

//thermal over-temp mask defines
#define THROTTLER_TEMP_CCD_BIT     5
#define THROTTLER_TEMP_XCD_BIT     6
#define THROTTLER_TEMP_HBM_BIT     7
#define THROTTLER_TEMP_AID_BIT     8
#define THROTTLER_VRHOT_BIT        9

#endif
