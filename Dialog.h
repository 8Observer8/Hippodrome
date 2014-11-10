#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <memory>
#include <QDialog>
#include <QPushButton>
#include <QTimer>

class Horse;

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog( QWidget *parent = 0 );
    ~Dialog();

private slots:
    void slotUpdate();

private:
    Ui::Dialog *ui;
    std::vector< std::shared_ptr<Horse> > m_horses;
    QTimer m_timer;
    const size_t step;
    int angle;
    int m_r;
};

#endif // DIALOG_H
