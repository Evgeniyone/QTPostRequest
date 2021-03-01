#include "postrequest.h"
#include <QString>
#include <QtNetwork>


PostRequest::PostRequest(QObject *root):QObject(root)
{
    accessManager=new QNetworkAccessManager(this);
    connect(
                accessManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(slotFinished(QNetworkReply*))
                );
}

void PostRequest::slotFinished(QNetworkReply *p)
{


    QString contents = QString::fromUtf8(p->readAll());
    emit done(contents);
}

void PostRequest::sendJson(const QUrl &url)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    accessManager->post(request,
                        "{\"id\":10,\"title\":\"2\",\"anons\":\"2\",\"full_text\":\"2\",\"views\":0}"
                       );


}
