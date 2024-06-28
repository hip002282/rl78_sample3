/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : panel.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "panel.h"
#include "meck.h"

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
#if defined DTC_USED || defined STANDBY_USED
#pragma address dtc_vectortable = VECTOR_ADDRESS
UCHAR __near dtc_vectortable[40];
#pragma address dtc_controldata = CONTROLDATA_ADDRESS
ST_DTC_DATA __near dtc_controldata[24];
#endif /*DTC_USED || STANDBY_USED*/
/*--- Variable declaration ---*/
	UCHAR I_07;
	UCHAR I_09;
	UCHAR I_11;
	UCHAR I_13;
	UCHAR I_15;
	UCHAR I_17;
	UCHAR I_19;
	UCHAR I_21;
	UCHAR F1407 = 0;
	UCHAR F1409 = 0;
	UCHAR F1411 = 0;

/*----------------------------*/

void panel_init0(void)
{

	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
	DGIN_INIT0(0);
}

void panel(void)
{
	DGIN_INIT;

	DGIN_PROC( I_07,20, LOW,10,fTrg10ms);
	DGIN_PROC( I_09,21, LOW,10,fTrg10ms);
	DGIN_PROC( I_11,22, LOW,10,fTrg10ms);
	DGIN_PROC( I_13,51, LOW,10,fTrg10ms);
	DGIN_PROC( I_15,52, LOW,10,fTrg10ms);
	DGIN_PROC( I_17,53, LOW,10,fTrg10ms);
	DGIN_PROC( I_19,54, LOW,10,fTrg10ms);
	DGIN_PROC( I_21,55, LOW,10,fTrg10ms);

	CONFIGURE_OUTPUTS( I_07,I_09,I_11,I_13,I_15,I_17,I_19,I_21,F1409,F1411,F1407 );
	
	DGOUT_PROC( 30, F1407, LOW );
	DGOUT_PROC( 31, F1409, LOW );
	DGOUT_PROC( 32, F1411, LOW );
}