#ifndef Draw3D_h
#define Draw3D_h

#include "NEMain.h"
#include "SceneData.h"

class draw_class {
    public:
        void DrawModel(NE_Model* Model, int x, int y, int z, int rx, int ry, int rz, float size = 1);
        void DrawQuad(NE_Material* Material, int x, int y, int z, int rx, int ry, int rz, float size = 1, int tileWidth = 1, int tileHeight = 1);
};

extern draw_class draw; // extern means scripts only have to define the .h to get the class

#endif