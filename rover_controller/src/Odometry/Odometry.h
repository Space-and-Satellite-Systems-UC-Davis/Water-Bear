#pragma once

typedef struct POSE_STRUCT {
    int x;
    int y;
    int yaw;
    int pitch;
    int roll;
} pose_t;

void vOdometryTask(void* pvParameters);