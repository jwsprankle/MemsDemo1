#ifndef BSP_LIS3MDL_H
#define BSP_LIS3MDL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <lis3mdl.h>

#define MAG_ACC_AVG_SAMPLES 10
#define MAG_ACC_TOTAL_SAMPLES (MAG_ACC_AVG_SAMPLES * 2)
#define Mag_ACC_COMM_QUEUE_SIZE 3
#define Mag_ACC_RATE 6 // 416Hz


int32_t bsp_lis3mdl_init(void);
void bsp_lis3mdl_int_callback(void);
int32_t bsp_lis3mdl_enable(void);
int32_t lis3mdl_disable(void);


#ifdef __cplusplus
}
#endif

#endif
