#ifndef PlayerHandler_h
#define PlayerHandler_h

#include <NEMain.h> // This is for the uint32_t type

class player_class {
    public:
        void HandleMovement(uint32_t keys, int KEY_LEFT, int KEY_DOWN, int KEY_UP, int KEY_RIGHT);
        void HandleRotation(uint32_t keys, int KEY_L, int KEY_R);
};

#endif