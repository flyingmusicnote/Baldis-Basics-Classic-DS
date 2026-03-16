#include "headers/draw.h"

#include "NEMain.h"

draw_class draw; // this is for the extern to make model global

void draw_class::DrawModel(NE_Model* Model, int x, int y, int z, int rx, int ry, int rz, float size) {
    // What model it uses (Scene->Model)
    // (int) x, y, z
    // (int) rotation x, rotation y, rotation z
    // (float) Size

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

void draw_class::DrawQuad(NE_Material* Material, int x, int y, int z, int rx, int ry, int rz, float size) {
    // What material it uses (Scene->Material)
    // (int) x, y, z
    // (int) rotation x, rotation y, rotation z
    // (float) Size

    glPushMatrix();
    glTranslatef32(inttof32(x), inttof32(y), inttof32(z));

    glRotateX(rx);
    glRotateY(ry);
    glRotateZ(rz);

    // Use the texture material
    NE_MaterialUse(Material);

    NE_PolyBegin(GL_QUAD);

    NE_PolyColor(NE_White);

    NE_PolyTexCoord(0, 0);
    NE_PolyVertex(-1 * size, 1 * size, 0);

    NE_PolyTexCoord(0, 128);
    NE_PolyVertex(-1 * size, -1 * size, 0);

    NE_PolyTexCoord(128, 128);
    NE_PolyVertex(1 * size, -1 * size, 0);

    NE_PolyTexCoord(128, 0);
    NE_PolyVertex(1 * size, 1 * size, 0);

    NE_PolyEnd();
    glPopMatrix(1);
}