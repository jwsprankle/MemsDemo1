#ifndef BSP_LSM6DSL_H
#define BSP_LSM6DSL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <lsm6dsl.h>

#define GYRO_ACC_SAMPLES 10
#define GYRO_ACC_NUM_DEVICES 2 // 1:AYRO, 2:ACC
#define GYRO_ACC_NUM_AXIS 3    // X,Y,Z
#define GYRO_ACC_WATERMARK (GYRO_ACC_SAMPLES * GYRO_ACC_NUM_DEVICES * GYRO_ACC_NUM_AXIS) // Number of words to read from FIFO
#define GYRO_ACC_RATE 6 // 416Hz / GYRO_ACC_SAMPLES = 41.6hz update rate


int32_t bsp_lsm6dsl_init(void);
void bsp_lsm6dsl_enable(void);
void bsp_lsm6dsl_disable(void);


typedef struct {
	LSM6DSL_AxesRaw_t gyro_data;
	LSM6DSL_AxesRaw_t acc_data;
} GYRO_ACC_t;


#ifdef __cplusplus
}
#endif

#endif
