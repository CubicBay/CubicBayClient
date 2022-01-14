#pragma once

#include <QList>
#include <QMetaType>
#include <QString>
#include <QVector>
#include <QNetworkAccessManager>
#include <QObjectPtr.h>
#include "net/NetJob.h"

namespace Modrinth {

struct ModpackAuthor {
    QString name;
    QString url;
};

struct IndexedVersion {
    QString addonId;
    QString fileId;
    QString version;
    QString mcVersion;
    QString downloadUrl;
    QString date;
};

struct IndexedPack
{
    QString addonId;
    QString name;
    QString description;
    QList<ModpackAuthor> authors;
    QString logoName;
    QString logoUrl;
    QString websiteUrl;

    bool versionsLoaded = false;
    QVector<IndexedVersion> versions;
};

void loadIndexedPack(IndexedPack & m, QJsonObject & obj);
void loadIndexedPackVersions(IndexedPack & m, QJsonArray & arr, const shared_qobject_ptr<QNetworkAccessManager>& network);
void versionJobFinished();
}

Q_DECLARE_METATYPE(Modrinth::IndexedPack)
