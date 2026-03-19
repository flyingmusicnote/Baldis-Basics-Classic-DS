#ifndef Debug_h
#define Debug_h

class debug_class {
    public:
        int GetFPS(); 
        void FramePassed();
        int currentQuads;
        void DebugInit();
        int seconds;
};

extern debug_class debug;

#endif