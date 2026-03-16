// NE_ModelLoadStaticMesh(Model, binfilename_bin);

// DS libraries
#include <NEMain.h>
#include <maxmod9.h>

// Normal libraries
#include <math.h>
#include <string>
#include <stdio.h>
#include <time.h>

// My libraries
#include "headers/debug.h"
#include "headers/player.h"
#include "headers/camera.h" // camera class is an extern so we get the class automatically
#include "headers/draw.h"
#include "headers/scene.h"

// Classes
player_class player;
debug_class debug;

// Models
#include "mario_bin.h"

// Textures
#include "mario.h"
#include "Walls/WhiteBrickWall.h"
#include "Floor/TileFloor.h"
#include "Ceiling/Ceiling.h"

void Draw3DScene(void* arg) // a reminder that this function is called every frame
{
    SceneData* Scene = (SceneData*)arg;
    debug.DebugInit();

    NE_CameraUse(Scene->Camera); // apply camera coordinates to next drawings

    //draw.DrawModel(Scene->MarioModel, 0,0,0, 0,0,0, 1);

    draw.DrawQuad(Scene->WallMaterial, 0,0,0, 0,90,0, 2);

    draw.DrawQuad(Scene->WallMaterial, 4,0,0, 0,-90,0, 2);

    draw.DrawQuad(Scene->CeilingMaterial, 2,2,0, 90,0,0, 2);

    draw.DrawQuad(Scene->FloorMaterial, 2,-2,0, -90,0,0, 2);

    printf("\x1b[13;0HTRI: %d", NE_GetPolygonCount());
}

int main(int argc, char *argv[])
{
    
    camera.CameraInit();

    SceneData Scene = { 0 };

    irqEnable(IRQ_HBLANK);
    irqSet(IRQ_VBLANK, NE_VBLFunc);
    irqSet(IRQ_HBLANK, NE_HBLFunc);

    NE_Init3D(); // Init Nitro Engine in normal 3D mode

    // libnds uses VRAM_C for the text console, reserve A and B only
    NE_TextureSystemReset(0, 0, NE_VRAM_AB);
    // Init console in non-3D screen
    consoleDemoInit();

    // Allocate space for the objects we'll use
    Scene.MarioModel = NE_ModelCreate(NE_Static);
    Scene.Camera = NE_CameraCreate();

    Scene.MarioMaterial = NE_MaterialCreate();

    NE_ModelLoadStaticMesh(Scene.MarioModel, mario_bin);
    // Load a RGB texture from RAM and assign it to "Material".
    NE_MaterialTexLoad(Scene.MarioMaterial, NE_A1RGB5, 128, 64,
        (NE_TextureFlags)(
            NE_TEXGEN_TEXCOORD |
            NE_TEXTURE_WRAP_S |
            NE_TEXTURE_WRAP_T
            ),
        marioBitmap);

    // Assign texture to model...
    NE_ModelSetMaterial(Scene.MarioModel, Scene.MarioMaterial);

    Scene.WallMaterial = NE_MaterialCreate();

    NE_MaterialTexLoad(Scene.WallMaterial, NE_A1RGB5, 128, 128,
        (NE_TextureFlags)(
            NE_TEXGEN_TEXCOORD |
            NE_TEXTURE_WRAP_S |
            NE_TEXTURE_WRAP_T
            ),
    WhiteBrickWallBitmap);

    Scene.CeilingMaterial = NE_MaterialCreate();

    NE_MaterialTexLoad(Scene.CeilingMaterial, NE_A1RGB5, 128, 128,
        (NE_TextureFlags)(
            NE_TEXGEN_TEXCOORD |
            NE_TEXTURE_WRAP_S |
            NE_TEXTURE_WRAP_T
            ),
    CeilingBitmap);

    Scene.FloorMaterial = NE_MaterialCreate();

    NE_MaterialTexLoad(Scene.FloorMaterial, NE_A1RGB5, 128, 128,
        (NE_TextureFlags)(
            NE_TEXGEN_TEXCOORD |
            NE_TEXTURE_WRAP_S |
            NE_TEXTURE_WRAP_T
            ),
    TileFloorBitmap);

    NE_LightSet(0, NE_White, 0, 0, 0); // We set up a light and its color

    while (1)
    {
        
        NE_WaitForVBL((NE_UpdateFlags)0); // Wait for next frame

        debug.GetFPS();

        // Get keys
        scanKeys();
        uint32_t keys = keysHeld();

        camera.GetForwardVector();
        player.HandleMovement(keys, KEY_LEFT, KEY_DOWN, KEY_UP, KEY_RIGHT);
        player.HandleRotation(keys, KEY_L, KEY_R);
        camera.GetLookVector();

        NE_CameraSet(
            Scene.Camera,
            camera.camX, camera.camY, camera.camZ,
            camera.lookX, camera.lookY, camera.lookZ,
            0, 1, 0
        );

        NE_ProcessArg(Draw3DScene, &Scene);

        debug.FramePassed();
        
        // Leave game
        if (keys & KEY_START) return 0;
    }

    return 0;
}