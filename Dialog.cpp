#include <cmath>
#include "Dialog.h"
#include "ui_Dialog.h"
#include "Horse.h"

// Useful constants
#define GLT_PI_DIV_180 0.017453292519943296
#define gltDegToRad(x)	((x)*GLT_PI_DIV_180)

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    step( 5 ),
    angle( 0 ),
    m_r( 200 )
{
    ui->setupUi(this);

    m_horses.push_back( std::make_shared<Horse>( this, 180, m_r ) );
    m_horses.push_back( std::make_shared<Horse>( this, 90, m_r ) );
    m_horses.push_back( std::make_shared<Horse>( this, 0, m_r ) );

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
    m_timer.start( 50 );
    //this->setStyleSheet( "background-color: rgb(177, 177, 177);" "color: black;" );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slotUpdate()
{
    //horse1->setGeometry( x0 + x, y0 + y, 50, 50 );
    //horse1->setStyleSheet("background-color: rgb(177, 177, 177);" "color: black;");

    //m_horses.push_back( horse1 );

    static const int offsetX = this->width()/2;
    static const int offsetY = this->height()/2;

    int angle, r, x, y;
    for( size_t i = 0; i < m_horses.size(); ++i ) {
        angle = m_horses[i]->angle();
        r = m_horses[i]->r();
        x = r * std::cos( gltDegToRad( angle ) );
        y = r * std::sin( gltDegToRad( angle ) );
        m_horses[i]->move( x + offsetX, y + offsetY );
        m_horses[i]->draw();

        ++angle;
        angle = angle % 360;
        m_horses[i]->setAngle( angle );
    }

    //horse1->show();

    //this->setStyleSheet( "background-color: rgb(177, 177, 177);" "color: black;" );
    update();
}
