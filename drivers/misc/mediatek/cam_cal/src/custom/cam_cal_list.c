// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"

#define MAX_EEPROM_SIZE_32K 0x8000
#define MAX_EEPROM_SIZE_16K 0x4000

#ifndef OPLUS_FEATURE_CAMERA_COMMON
#define OPLUS_FEATURE_CAMERA_COMMON
#endif /* OPLUS_FEATURE_CAMERA_COMMON */

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
	/*Below is commom sensor */
	{OV48B12M_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV48B_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX766_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_32K},
	{IMX766DUAL_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC8054_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3P9SP_SENSOR_ID, 0xA0, Common_read_region},
	{IMX481_SENSOR_ID, 0xA2, Common_read_region},
	{GC02M0_SENSOR_ID, 0xA8, Common_read_region},
	{IMX586_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX576_SENSOR_ID, 0xA2, Common_read_region},
	{IMX519_SENSOR_ID, 0xA0, Common_read_region},
	{IMX319_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3M5SX_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX686SPEC25M_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX686_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{HI846_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KGD1SP_SENSOR_ID, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX350_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	/*chongqing*/
	{S5KJN1_SENSOR_ID_CHONGQING, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV64B_SENSOR_ID_CHONGQING, 0xA0, Common_read_region},
	{HI1336_SENSOR_ID_CHONGQING, 0xA0, Common_read_region},
	{S5KHM6S_SENSOR_ID_CHONGQING, 0xA0, Common_read_region},
	{S5K3P9SP_SENSOR_ID_CHONGQING, 0xA8, Common_read_region},
	{OV08D10_SENSOR_ID_CHONGQING, 0xA0, Common_read_region},
	/*barley*/
	{S5KHM6S_SENSOR_ID_BARLEY, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KJN1_SENSOR_ID_BARLEY, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV13B10_SENSOR_ID_BARLEY, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{SC1300CS_SENSOR_ID_BARLEY, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV50C40_SENSOR_ID_BARLEY, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV08D10_SENSOR_ID_BARLEY, 0xA2, Common_read_region},
	{SC820CS_SENSOR_ID_BARLEY, 0xA8, Common_read_region},
#ifdef OPLUS_FEATURE_CAMERA_COMMON
	{IMX709LUNA_SENSOR_ID, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX766LUNA_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_32K},
	{IMX800LUNA_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_32K},
	{S5KJN1LUNA_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_32K},
#endif /* OPLUS_FEATURE_CAMERA_COMMON */
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


