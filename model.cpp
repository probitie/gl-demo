#include "model.h"

void model::render()
{
    for (size_t i = 0; i < m_meshes.size(); ++i) {
        m_materials[i].enable();
        m_meshes[i].render();
        m_materials[i].disable();
    }

    // TODO maybe unbind all stuff
}
