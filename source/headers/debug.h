#ifndef debug_h
#define debug_h

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