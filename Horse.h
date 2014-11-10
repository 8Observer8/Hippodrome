#ifndef HORSE_H
#define HORSE_H

#include <QWidget>

class QPushButton;

class Horse
{
public:
    Horse( QWidget *parent = 0, int angle = 0, int r = 0 );
    ~Horse();

    void draw();
    void move( int x, int y );

    void setAngle( int angle );
    void setR( int r );
    int angle() const;
    int r() const;

private:
    QPushButton *m_horse;
    int m_angle;
    int m_r;
};

#endif // HORSE_H
