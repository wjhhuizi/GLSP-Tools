#ifndef TOOLS_H
#define TOOLS_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QListWidget>
#include <QMenu>
#include <QPushButton>

class Tools : public QMainWindow
{
    Q_OBJECT

public:
    Tools(QWidget *parent = 0);

private:
    QWidget *Container;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void ReadFile(QString *FileName);
};

#endif // TOOLS_H
