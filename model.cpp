#include "model.h"

void model::render() const
{
    for (size_t i = 0; i < m_meshes.size(); ++i) {
        m_materials[i].enable();
        m_meshes[i].render();
    }

    // TODO maybe unbind all stuff
}
