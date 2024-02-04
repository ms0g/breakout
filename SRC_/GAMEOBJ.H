#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    int posX() { return m_pos.x; }

    int posY() { return m_pos.y; }
    
    int width() { return m_width; }

    int height() { return m_height; }

    int velocityX() { return m_velocity.x; }

    int velocityY() { return m_velocity.y; }

    struct {
        int x; 
        int y;
    } m_pos;

    int m_width; 
    int m_height;
        
    struct {
        int x;
        int y;
    } m_velocity;

    char m_color;
};


#endif