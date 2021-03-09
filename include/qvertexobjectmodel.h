/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic vertex object model
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QVERTEXOBJECTMODEL_H
#define QVERTEXOBJECTMODEL_H

#include <QObject>
#include <qdigraph_global.h>

class QVertexObjectModelPrivate;
class QDIGRAPHSHARED_EXPORT QVertexObjectModel : public QObject
{
    Q_OBJECT
public:
    explicit QVertexObjectModel(const QString &pluginName,QObject *parent = 0);

    virtual ~QVertexObjectModel();
    /**
     * @brief setData       Sending data to the model will trigger operations such as updating interface parameters, and will verify
     */
    void setData(QJsonObject);
    /**
     * @brief data          Get the json format of model data
     * @return
     */
    const QJsonObject& data() const;
    /**
     * @brief pluginName    Get the plugin name
     * @return
     */
    QString pluginName() const;

signals:
    void signal_modelDataUpdate();
private:
    /**
     * @brief init
     */
    void init();
protected:
    QVertexObjectModel(QVertexObjectModelPrivate &pri, QObject *parent = 0);
private:
    QScopedPointer<QVertexObjectModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QVertexObjectModel)
    Q_DISABLE_COPY(QVertexObjectModel)
};

#endif // QVERTEXOBJECTMODEL_H
