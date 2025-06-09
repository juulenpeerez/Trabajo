/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2024
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>



#define  FT_UAH_PHOTSAT_SERV_129_0010
#define  FT_UAH_PHOTSAT_SERV_129_FDIR_0020

/*
//TODO 06 Complete FT_UAH_PHOTSAT_SERV_129_0010
//The aim of this test is to prove that the system works properly
#ifdef FT_UAH_PHOTSAT_SERV_129_0010

//Emulation of an observation with the inidcated values
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_0010_step0(
OBT_AFTER_POWER_ON ,
"FT_UAH_PHOTSAT_SERV_129_0010_STEP1: Simulation of an observation with the the next simulated values (ThetaPitch=30, ThetaYaw=45,num_samples=5)",1800, 2700, 5);
#endif

*/

//TODO 07 Complete FT_UAH_PHOTSAT_SERV_129_FDIR_0020
#ifdef FT_UAH_PHOTSAT_SERV_129_FDIR_0020


// Rest of the angles to zero
EmuGSS_TCProgram19_1_Action_129_3 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step0(
OBT_AFTER_POWER_ON + 0,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP0: Reset of the angles to cero with TC[129,3]",
0x4003);

//Add the monitoring of ThetaPitch
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step1(
OBT_AFTER_POWER_ON + 5,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP2 ,Define PMOIND 1 for monitoring PID 13",
1, 13, 1, 1, 0xFF, 0x00, 0x4003);

//Add the monitoring of ThetaYaw
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step2(
OBT_AFTER_POWER_ON + 10,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP3 ,Define PMOIND 2 for monitoring PID 14",
2, 14, 1, 1, 0xFF, 0x00, 0x4003);

//Activation of the monitoring of Thetapitch
EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step3(
OBT_AFTER_POWER_ON + 15,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP4, Monitoring PMONID 1", 1);

//Activation of the monitoring of ThetaYaw
EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step4(
OBT_AFTER_POWER_ON + 20,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP5, Monitoring PMONID 2", 2);

//Allowance of events-results
EmuGSS_TCProgram19_4 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step5(
OBT_AFTER_POWER_ON + 25,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP1: allowance of the event 0x4003",
0x4003);


// Set the values to high levels
EmuGSS_TCProgram129_2 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step6(
OBT_AFTER_POWER_ON + 30,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP6:Configuration PID with high values (Kp=0.5, Ki=0.5, Kd=0.5)",
0.5, 0.5, 0.5);

//try to make the pictures
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step7(
OBT_AFTER_POWER_ON + 35,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_STEP7: Simulation with forzed values (ThetaPitch=30, ThetaYaw=45, num_samples=3)",
45, 23, 3);


#endif



