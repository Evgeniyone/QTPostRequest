#ifndef POSTREQUEST_H
#define POSTREQUEST_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

class PostRequest:public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *accessManager;



public:
    PostRequest(QObject *root);
    void sendJson(const QUrl &url);
signals:
    void done(QString &);
private slots:
    void slotFinished(QNetworkReply*);
};

#endif // POSTREQUEST_H
