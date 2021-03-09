/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic edge object
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QEDGEOBJECTMODEL_H
#define QEDGEOBJECTMODEL_H

#include <QObject>
#include <qdigraph_global.h>

class QEdgeObjectModelPrivate;
class QDIGRAPHSHARED_EXPORT QEdgeObjectModel : public QObject
{
    Q_OBJECT
public:
    explicit QEdgeObjectModel(const QString&pluginName,QObject *parent = 0);
    virtual ~QEdgeObjectModel();
    /**
     * @brief setData       Sending data to the model will trigger operations such as updating interface parameters
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
    QEdgeObjectModel(QEdgeObjectModelPrivate &pri, QObject *parent = 0);
private:
    QScopedPointer<QEdgeObjectModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QEdgeObjectModel)
    Q_DISABLE_COPY(QEdgeObjectModel)
};

#endif // QEDGEOBJECTMODEL_H
