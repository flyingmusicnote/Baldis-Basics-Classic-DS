#include "headers/draw.h"
#include "headers/camera.h"

#include "NEMain.h"

#include <cmath>

draw_class draw; // this is for the extern to make model global

int distance_check(int x, int y, int z, int dist) {
    // change you chatgpt for this distance code i suckz
    int dx = x - camera.camX;
    int dy = y - camera.camY;
    int dz = z - camera.camZ;

    // squared distance (still in f32 space!)
    long long distSq = (long long)dx * dx +
                       (long long)dy * dy +
                       (long long)dz * dz;

    // convert dist to f32 BEFORE squaring
    int dist_f32 = dist << 12; // dist * 4096
    long long distSqLimit = (long long)dist_f32 * dist_f32;

    return (distSq > distSqLimit);
}

void draw_class::DrawModel(NE_Model* Model, int x, int y, int z, int rx, int ry, int rz, float size) {
    // What model it uses (Scene->Model)
    // (int) x, y, z
    // (int) rotation x, rotation y, rotation z
    // (float) Size [optional]

    if (distance_check(x, y, z, 30)) return;

    glPushMatrix();
    
    glTranslatef32(inttof32(x), inttof32(y), inttof32(z));
    glRotateX(rx);
    glRotateY(ry);
    glRotateZ(rz);
    glScalef32(inttof32(size), inttof32(size), inttof32(size));

    // Draw Mario model
    NE_ModelDraw(Model);

    glPopMatrix(1);
}

void draw_class::DrawQuad(NE_Material* Material, int x, int y, int z, int rx, int ry, int rz, float size, int tileWidth, int tileHeight) {
    
    // What material it uses (Scene->Material)
    // (int) x, y, z
    // (int) rotation x, rotation y, rotation z
    // (float) Size [optional]
    // (int) tile w, tile h [optional]

    if (distance_check(x, y, z, 50)) return;
    size += 0.003f;

    glPushMatrix();
    glTranslatef32(x, y, z);

    glRotateX(rx);
    glRotateY(ry);
    glRotateZ(rz);

    // Use the texture material
    NE_MaterialUse(Material);

    NE_PolyBegin(GL_QUAD);

    NE_PolyColor(NE_White);
    
    int texWidth  = NE_TextureGetSizeX(Material) * tileWidth;
    int texHeight = NE_TextureGetSizeY(Material) * tileHeight;

    NE_PolyTexCoord(0, 0);
    NE_PolyVertex(-1 * size, 1 * size, 0);

    NE_PolyTexCoord(0, texHeight);
    NE_PolyVertex(-1 * size, -1 * size, 0);

    NE_PolyTexCoord(texWidth, texHeight);
    NE_PolyVertex(1 * size, -1 * size, 0);

    NE_PolyTexCoord(texWidth, 0);
    NE_PolyVertex(1 * size, 1 * size, 0);

    NE_PolyEnd();
    glPopMatrix(1);
}