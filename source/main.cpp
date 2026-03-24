// DS libraries
#include <stdbool.h>
#include <stdio.h>
#include <nds.h>

#include <NEMain.h>

#include <math.h>
#include <string>
#include <stdio.h>
#include <time.h>

// My headers
#include "headers/Debug.h" // Debug stuff
#include "headers/PlayerHandler.h" // Control the camera
#include "headers/Camera.h" // Get camera data
#include "headers/SceneData.h" // Get scene data
#include "headers/Mapdata.h" // Get map data
#include "headers/InitElements.h" // Init textures

#include "nintendo.h"
#include "audio/music/schoolhouse_bin.h"
#include "audio/sounds/disfelb_nintendo1_bin.h"

// Classes
player_class player;
debug_class debug;

void Draw3DScene(void* arg) // a reminder that this function is called every frame
{
    SceneData* Scene = (SceneData*)arg;
    debug.DebugInit();

    NE_CameraUse(Scene->Camera); // apply camera coordinates to next drawings

    mapdata.createMap(Scene);
}

SceneData haeoj() {
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

    init.textures(Scene);

    NE_LightSet(0, NE_White, 0, 0, 0); // We set up a light and its color
    return Scene;
}

void dpay(SceneData Scene, uint32_t keys) {
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
}
 
int main(int argc, char *argv[])
{
    soundEnable();
    SceneData Scene = haeoj();
    
    int schoolhouse_music;

    schoolhouse_music = soundPlaySample(schoolhouse_bin, // Pointer to sample
                        SoundFormat_16Bit,           // Format: Signed 16 bits
                        schoolhouse_bin_size,         // Size in bytes of the sample
                        22050, // Frequency in Hz
                        127,   // Volume: Max
                        64,    // Panning: Center
                        true, 
                        0);    // Loop start point (not used here)

                        soundPlaySample(disfelb_nintendo1_bin, // Pointer to sample
                        SoundFormat_16Bit,           // Format: Signed 16 bits
                        disfelb_nintendo1_bin_size,         // Size in bytes of the sample
                        22050, // Frequency in Hz
                        127,   // Volume: Max
                        64,    // Panning: Center
                        false, 
                        0);    // Loop start point (not used here)

    while (1)
    {
        

        NE_WaitForVBL((NE_UpdateFlags)0); // Wait for next frame
        NE_ClearColorSet(RGB15(5, 25, 30), 31, 0);
        oamUpdate(&oamMain);

        debug.GetFPS();

        // Get keys
        scanKeys();
        uint32_t keys = keysHeld();

        dpay(Scene, keys);

        debug.FramePassed();
        
        // Leave game
        if (keys & KEY_SELECT) return 0;
    }

    return 0;
}