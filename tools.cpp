#include "tools.h"
#include <QDataStream>
#include <QFileInfo>
#include <QFileSystemModel>
#include <QJsonParseError>
#include <QLayout>
#include <QMessageBox>
#include <QMimeData>

Tools::Tools(QWidget *parent)
    : QMainWindow(parent)
{
    // UI
    Container = new QWidget();
    Container->setAcceptDrops(true);
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QWidget *MainWidget = new QWidget();
    MainWidget->setLayout(MainLayout);
    setCentralWidget(MainWidget);
    setAcceptDrops(true);
    // Connect signals and slots.
}

void Tools::dragEnterEvent(QDragEnterEvent *event)
{
    //if (event->mimeData()->hasFormat("")) {
        event->acceptProposedAction();
    //}
}

void Tools::dropEvent(QDropEvent *event)
{
    // Get files urls.
    QList<QUrl> Urls = event->mimeData()->urls();
    QFileSystemModel *Model = new QFileSystemModel();
    QStringList *FileList = new QStringList();

    if (Urls.isEmpty()) return;

    QList<QUrl>::iterator i;
    for (i = Urls.begin(); i != Urls.end(); i++) {
        QString FileName = (*i).toLocalFile();
        if (FileName.isEmpty()) return;

        // Read files or folders.
        QFileInfo FileInfo(FileName);
        if (FileInfo.isDir()) {
            //
            ReadFile(FIleName);
        } else if (FileInfo.isFile()) {
            FileList->append(FileName);
        } else {
            return;
        }
    }
}

void Tools::ReadFile(QString *FileName)
{
    // Decrypt or encrypt selected file.
    QFile File(FileName);
    if (!File.open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this, "Error", "Cannot open " + FileName + "!", QMessageBox::Ok);
        return;
    }

    QDataStream Input(&File);

    qint32 Magic;
    Input >> Magic;

    qDebug("Magic = %i", Magic);

    switch (Magic) {
        case -1991225785:  // png

            break;
        case 1279872587:  // imag

            break;
        case 1413830722:  // texb

            break;
        case 1332176723:  // ogg

            break;
        case 1397836905:  // db

            break;
        default:
            break;
    }
}
