#ifndef IPC_SHARED_H
#define IPC_SHARED_H

#include <stdint.h>

typedef struct {
    float temp;
    float humi;
    uint8_t hour, min, sec;
    uint32_t update_cnt;
    uint8_t rtc_online;  // 1: 正常, 0: 斷線
} EnvData_t;

#endif
