#include "headers/InitElements.h"
#include <NEMain.h>

#include "headers/SceneData.h" // the materials are stored in Scene->NameMaterial

// Models
#include "mario_bin.h"

// Textures
#include "mario.h"
#include "Walls/WhiteBrickWall.h"
#include "Floor/TileFloor.h"
#include "Ceiling/Ceiling.h"

auto wrapFlag = (NE_TextureFlags)(NE_TEXGEN_TEXCOORD | NE_TEXTURE_WRAP_S | NE_TEXTURE_WRAP_T);

void createTexture(SceneData& Scene, NE_Material*& material, int w, int h, const unsigned int* bitmap) {
    material = NE_MaterialCreate();
    NE_MaterialTexLoad(material, NE_A1RGB5, 128, 128, wrapFlag, bitmap);
}

void init_class::textures(SceneData& Scene) {
    createTexture(Scene, Scene.WallMaterial, 128, 128, WhiteBrickWallBitmap);
    createTexture(Scene, Scene.CeilingMaterial, 128, 128, CeilingBitmap);
    createTexture(Scene, Scene.FloorMaterial, 128, 128, TileFloorBitmap);
}

init_class init;

// Scene.MarioMaterial = NE_MaterialCreate();

    // NE_ModelLoadStaticMesh(Scene.MarioModel, mario_bin);
    // // Load a RGB texture from RAM and assign it to "Material".
    // NE_MaterialTexLoad(Scene.MarioMaterial, NE_A1RGB5, 128, 64,
    //     (NE_TextureFlags)(
    //         NE_TEXGEN_TEXCOORD |
    //         NE_TEXTURE_WRAP_S |
    //         NE_TEXTURE_WRAP_T
    //         ),
    //     marioBitmap);

    // // Assign texture to model...
    // NE_ModelSetMaterial(Scene.MarioModel, Scene.MarioMaterial);