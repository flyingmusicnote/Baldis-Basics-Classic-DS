#include "headers/Mapdata.h"
#include "headers/Draw3D.h"

void mapdata_class::createMap(SceneData* Scene) {
    draw.DrawQuad(Scene->WallMaterial, 0,0,73728, 0,-180,0, 2);
    draw.DrawQuad(Scene->WallMaterial, -8192,0,0, 0,90,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 0,8192,0, 90,0,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 0,-8192,0, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 8192,0,0, 0,-90,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 0,-8192,65536, -90,0,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 0,-8192,16384, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 8192,0,16384, 0,-90,0, 2);
    draw.DrawQuad(Scene->WallMaterial, -8192,0,16384, 0,90,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 0,8192,16384, 90,0,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 0,8192,65536, 90,0,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 0,-8192,32768, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 8192,0,32768, 0,-90,0, 2);
    draw.DrawQuad(Scene->WallMaterial, -8192,0,32768, 0,90,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 0,8192,32768, 90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, -8192,0,65536, 0,90,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 0,-8192,49152, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 8192,0,49152, 0,-90,0, 2);
    draw.DrawQuad(Scene->WallMaterial, -8192,0,49152, 0,90,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 0,8192,49152, 90,0,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 16384,-8192,65536, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 16384,0,73728, 0,-180,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 16384,8192,65536, 90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 16384,0,57344, 0,0,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 32768,-8192,65536, -90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 32768,0,73728, 0,-180,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 32768,8192,65536, 90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 32768,0,57344, 0,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 49152,0,57344, 0,0,0, 2);
    draw.DrawQuad(Scene->CeilingMaterial, 49152,8192,65536, 90,0,0, 2);
    draw.DrawQuad(Scene->WallMaterial, 49152,0,73728, 0,-180,0, 2);
    draw.DrawQuad(Scene->FloorMaterial, 49152,-8192,65536, -90,0,0, 2);
}

mapdata_class mapdata; // this is for the extern to make model global