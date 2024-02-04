#include "GAMEOBJ.H"
#include "RENDERER.H"

 void GameObject::draw(Renderer* renderer) {
        renderer->renderRect(pos.x, pos.y, width, height, m_color);
    }