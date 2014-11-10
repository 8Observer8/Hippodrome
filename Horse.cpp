#include "Horse.h"
#include <QPushButton>

Horse::Horse( QWidget *parent, int angle, int r ) :
    m_angle( angle ),
    m_r( r )
{
    m_horse = new QPushButton( parent );
}

Horse::~Horse()
{
    delete m_horse;
}

void Horse::draw()
{
    m_horse->show();
}

void Horse::move( int x, int y )
{
    m_horse->setGeometry( x, y, 50, 50 );
}

void Horse::setAngle( int angle )
{
    m_angle = angle;
}

void Horse::setR( int r )
{
    m_r = r;
}

int Horse::angle() const
{
    return m_angle;
}

int Horse::r() const
{
    return m_r;
}
