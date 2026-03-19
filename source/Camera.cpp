#include "headers/Camera.h"
#include <math.h>

void camera_class::CameraInit() {
    camX = 0;
    camY = 0;
    camZ = 2;

    camYaw = -3.15;
    camPitch = 0;
}

void camera_class::GetForwardVector() {
    forwardX = sinf(camYaw);
    forwardZ = cosf(camYaw);

    rightX = cosf(camYaw);
    rightZ = -sinf(camYaw);
}

void camera_class::GetLookVector() {
    lookX = camX + cosf(camPitch) * sinf(camYaw);
    lookY = camY + sinf(camPitch);
    lookZ = camZ + cosf(camPitch) * cosf(camYaw);
}

camera_class camera;