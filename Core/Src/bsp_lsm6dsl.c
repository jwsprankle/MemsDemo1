//#include "sensor_bus1.h"
#include "bsp_Lsm6dsl.h"
#include <lsm6dsl.h>
#include <lsm6dsl_reg.h>
#include <b_l475e_iot01a1_bus.h>

static LSM6DSL_Object_t bsp_lsm6dsl_Obj = { 0 };

/**
 * @brief  Initialize the LSM6DSL sensor
 * @param  pObj the device pObj
 * @retval 0 in case of success, an error code otherwise
 */

int32_t bsp_lsm6dsl_init() {
	LSM6DSL_IO_t io_ctx;
	lsm6dsl_ctrl3_c_t ctrl3_c;
	uint8_t id;

	io_ctx.BusType = LSM6DSL_I2C_BUS;
	io_ctx.Address = LSM6DSL_I2C_ADD_L;
	io_ctx.Init = BSP_I2C2_Init;
	io_ctx.DeInit = BSP_I2C2_DeInit;
	io_ctx.ReadReg = BSP_I2C2_ReadReg;
	io_ctx.WriteReg = BSP_I2C2_WriteReg;
	io_ctx.GetTick = BSP_GetTick;

	if (LSM6DSL_RegisterBusIO(&bsp_lsm6dsl_Obj, &io_ctx) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	// Vefify sensor ID
	if (LSM6DSL_ReadID(&bsp_lsm6dsl_Obj, &id) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	if (id != LSM6DSL_ID) {
		return LSM6DSL_ERROR;
	}

	// Reset device
	if (lsm6dsl_reset_set(&bsp_lsm6dsl_Obj.Ctx, 1) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	// Wait for reset to complete
	do {
		if (lsm6dsl_read_reg(&bsp_lsm6dsl_Obj.Ctx, LSM6DSL_CTRL3_C,
				(uint8_t*) &ctrl3_c, 1) != LSM6DSL_OK) {
			return LSM6DSL_ERROR;
		}
	} while (ctrl3_c.sw_reset == 1);


	// Init using default settings
	if (LSM6DSL_Init(&bsp_lsm6dsl_Obj) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	// Override default data rate for acc and gyro
	bsp_lsm6dsl_Obj.acc_odr = (lsm6dsl_odr_xl_t) GYRO_ACC_RATE;
	bsp_lsm6dsl_Obj.gyro_odr = (lsm6dsl_odr_g_t) GYRO_ACC_RATE;


	if (lsm6dsl_fifo_data_rate_set(&(bsp_lsm6dsl_Obj.Ctx),
			(lsm6dsl_odr_fifo_t) GYRO_ACC_RATE) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}


	if (LSM6DSL_FIFO_Set_Mode(&bsp_lsm6dsl_Obj,
			LSM6DSL_FIFO_MODE) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}


	if (LSM6DSL_FIFO_ACC_Set_Decimation(&bsp_lsm6dsl_Obj,
			LSM6DSL_FIFO_XL_NO_DEC) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	if (LSM6DSL_FIFO_GYRO_Set_Decimation(&bsp_lsm6dsl_Obj,
			LSM6DSL_FIFO_GY_NO_DEC) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	if (LSM6DSL_FIFO_Set_Watermark_Level(&bsp_lsm6dsl_Obj,
			GYRO_ACC_WATERMARK) != LSM6DSL_OK) {
		return LSM6DSL_ERROR;
	}

	// Setup watermark interrupt
	lsm6dsl_int1_route_t fth_route = { 0 };
	fth_route.int1_fth = 1;
	lsm6dsl_pin_int1_route_set(&(bsp_lsm6dsl_Obj.Ctx), fth_route);

	bsp_lsm6dsl_Obj.is_initialized = 1;

	return LSM6DSL_OK;
}

void bsp_lsm6dsl_enable(void) {
	LSM6DSL_ACC_Enable(&bsp_lsm6dsl_Obj);
	LSM6DSL_GYRO_Enable(&bsp_lsm6dsl_Obj);
}

void bsp_lsm6dsl_disable(void) {
	LSM6DSL_ACC_Disable(&bsp_lsm6dsl_Obj);
	LSM6DSL_GYRO_Disable(&bsp_lsm6dsl_Obj);
}

