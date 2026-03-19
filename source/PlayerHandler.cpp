#include "headers/PlayerHandler.h"
#include "headers/Camera.h" // camera class is an extern so we get the class automatically
#include <NEMain.h> // This is for the uint32_t type

float moveSpeed = 0.1f;

void player_class::HandleMovement(uint32_t keys, int KEY_LEFT, int KEY_DOWN, int KEY_UP, int KEY_RIGHT) {
    if (keys & KEY_UP) {
        camera.camX += camera.forwardX * moveSpeed;
        camera.camZ += camera.forwardZ * moveSpeed;
    }

    if (keys & KEY_DOWN) {
        camera.camX -= camera.forwardX * moveSpeed;
        camera.camZ -= camera.forwardZ * moveSpeed;
    }

    if (keys & KEY_RIGHT) {
        camera.camX -= camera.rightX * moveSpeed;
        camera.camZ -= camera.rightZ * moveSpeed;
        
    }

    if (keys & KEY_LEFT) {
        camera.camX += camera.rightX * moveSpeed;
        camera.camZ += camera.rightZ * moveSpeed;
    }
}

void player_class::HandleRotation(uint32_t keys, int KEY_L, int KEY_R) {
    if (keys & KEY_L) camera.camYaw += 0.05f;
    if (keys & KEY_R) camera.camYaw -= 0.05f;
}