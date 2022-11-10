#include "bsp_lis3mdl.h"
#include "main.h"
#include <lis3mdl.h>
#include <lis3mdl_reg.h>
#include <b_l475e_iot01a1_bus.h>

static LIS3MDL_Object_t bsp_lis3mdl_Obj = { 0 };

int32_t bsp_lis3mdl_init() {
	LIS3MDL_IO_t mag_io_ctx;
	lis3mdl_ctrl_reg2_t ctrl2_c;
	uint8_t id;

	mag_io_ctx.BusType = LIS3MDL_I2C_BUS;
	mag_io_ctx.Address = LIS3MDL_I2C_ADD_H;
	mag_io_ctx.Init = BSP_I2C2_Init;
	mag_io_ctx.DeInit = BSP_I2C2_DeInit;
	mag_io_ctx.ReadReg = BSP_I2C2_ReadReg;
	mag_io_ctx.WriteReg = BSP_I2C2_WriteReg;
	mag_io_ctx.GetTick = BSP_GetTick;

	if (LIS3MDL_RegisterBusIO(&bsp_lis3mdl_Obj,	&mag_io_ctx) != LIS3MDL_OK) {
		return LIS3MDL_ERROR;
	}

	// Vefify we're connected to correct sensor
	if (LIS3MDL_ReadID(&bsp_lis3mdl_Obj, &id) != LIS3MDL_OK) {
		return LIS3MDL_ERROR;
	} else {
		if (id != LIS3MDL_ID) {
			return LIS3MDL_ERROR;
		}
	}

	// Reset device
	if (lis3mdl_reset_set(&bsp_lis3mdl_Obj.Ctx, 1 ) != LIS3MDL_OK) {
		return LIS3MDL_ERROR;
	}

	// Wait for reset to complete
	do {
		if (lis3mdl_read_reg(&bsp_lis3mdl_Obj.Ctx, LIS3MDL_CTRL_REG2, (uint8_t*) &ctrl2_c, 1) != LIS3MDL_OK) {
			return LIS3MDL_ERROR;
		}
	} while (ctrl2_c.soft_rst == 1);

	// Output data rate selection
	if (lis3mdl_data_rate_set(&(bsp_lis3mdl_Obj.Ctx), LIS3MDL_UHP_40Hz) != LIS3MDL_OK)
	{
		return LIS3MDL_ERROR;
	}

	if (lis3mdl_block_data_update_set(&(bsp_lis3mdl_Obj.Ctx), PROPERTY_ENABLE) != LIS3MDL_OK)
	{
		return LIS3MDL_ERROR;
	}

	/* Set Output data rate. */
	if (LIS3MDL_MAG_SetOutputDataRate(&bsp_lis3mdl_Obj, 40.0f) != LIS3MDL_OK)
	{
		return LIS3MDL_ERROR;
	}

	/* Full scale selection. */
	if (LIS3MDL_MAG_SetFullScale(&bsp_lis3mdl_Obj, LIS3MDL_16_GAUSS) != LIS3MDL_OK)
	{
		return LIS3MDL_ERROR;
	}

	bsp_lis3mdl_Obj.is_initialized = 1;

	return LIS3MDL_OK;
}


int32_t bsp_lis3mdl_enable(void) {

	// Clear any pending data
	while (HAL_GPIO_ReadPin(LSM3DSL_DRDY_EXTI8_GPIO_Port, LSM3DSL_DRDY_EXTI8_Pin) == GPIO_PIN_SET) {
		LIS3MDL_AxesRaw_t Value;

		if (LIS3MDL_MAG_GetAxesRaw(&bsp_lis3mdl_Obj, &Value) != LIS3MDL_OK) {
			return LIS3MDL_ERROR;
		}
	}


	// Startup mag
	if (LIS3MDL_MAG_Enable(&bsp_lis3mdl_Obj) != LIS3MDL_OK) {
		return LIS3MDL_ERROR;
	}

	return LIS3MDL_OK;
}


int32_t lis3mdl_disable(void) {

	// Stop mag
	if (LIS3MDL_MAG_Disable(&bsp_lis3mdl_Obj) != LIS3MDL_OK) {
		return LIS3MDL_ERROR;
	}

	return LIS3MDL_OK;
}

