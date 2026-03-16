#ifndef camera_h
#define camera_h

class camera_class {
    public:
        void GetForwardVector();
        void CameraInit();
        void GetLookVector();

        // xyz
        float camX;
        float camY;
        float camZ;

        // roation
        float camYaw;
        float camPitch;

        // forwards
        float forwardX;
        float forwardZ;
        float rightX;
        float rightZ;
        float lookX;
        float lookY;
        float lookZ;
};

extern camera_class camera; // extern means scripts only have to define the .h to get the class

#endif