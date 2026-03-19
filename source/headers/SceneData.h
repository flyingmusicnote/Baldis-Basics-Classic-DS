#ifndef SceneData_h
#define SceneData_h

#include <NEMain.h>

typedef struct {
    NE_Camera* Camera;
    NE_Model* MarioModel;
    NE_Material* MarioMaterial;
    NE_Material* WallMaterial;
    NE_Material* CeilingMaterial;
    NE_Material* FloorMaterial;
    NE_Material* BaldiMaterial;
} SceneData;

#endif