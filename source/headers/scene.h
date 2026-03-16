#ifndef SCENE_H
#define SCENE_H

#include <NEMain.h>

typedef struct {
    NE_Camera *Camera;
    NE_Model *MarioModel;
    NE_Material *MarioMaterial;
    NE_Material *WallMaterial;
    NE_Material *CeilingMaterial;
    NE_Material *FloorMaterial;
} SceneData;

#endif