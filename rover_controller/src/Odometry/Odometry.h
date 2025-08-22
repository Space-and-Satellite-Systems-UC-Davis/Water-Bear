#pragma once

typedef struct POSE_STRUCT {
    int x;
    int y;
    int yaw;
    int pitch;
    int roll;
} pose_t;

void reset_odometry(pose_t new_pose);

