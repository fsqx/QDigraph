/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       tree model header
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QDIGRAPHMODEL_H
#define QDIGRAPHMODEL_H

#include "qobject.h"
#include <QString>
#include <qedgeobjectmodel.h>
#include <qvertexobjectmodel.h>
#include <qdigraph_global.h>
#include <qpointer.h>
#include "qjsonobject.h"

class QDigraphModelPrivate;
class QDIGRAPHSHARED_EXPORT QDigraphModel:public QObject
{
    Q_OBJECT
public:
    QDigraphModel(const QString& graphName);
    ~QDigraphModel();
public:
    /**
     * @brief registerVertex    Regist one vertex
     * @param vertexid          Vertex'd id
     * @param pluginName        Plugin'd name
     * @return                  Is success
     */
    bool registerVertex(const QString& vertexid,const QString& pluginName);
    /**
     * @brief registerEdge      Regist one edge
     * @param edgeid            Edge's id
     * @param pluginName        Plugin's name
     * @return                  Is success
     */
    bool registerEdge(const QString& edgeid,const QString& pluginName);
    /**
     * @brief findVertex        Find vertex and return vertex's id, prohibit for delete
     * @param vertexid          Get vertex's id
     * @return                  Point of vertex model obj
     */
    QPointer<QVertexObjectModel>  findVertex(const QString& vertexid) const;
    /**
     * @brief findEdge          Find edge and return edge's id, prohibit for delete
     * @param edgeid            Get edge's id
     * @return                  Point of edge model obj
     */
    QPointer<QEdgeObjectModel> findEdge(const QString& edgeid) const;
    /**
     * @brief containsVertex    Determine if there is a vertex
     * @param vertexid          Vertex's id
     * @return                  True if contains this vertex
     */
    bool containsVertex(const QString& vertexid);
    /**
     * @brief containsEdge      Determine if there is a edge
     * @param edgeid            Edge's id
     * @return                  True if contains this edge
     */
    bool containsEdge(const QString& edgeid);
    /**
     * @brief unregisterVertex  Unregist vertex
     * @param vertexid          Vertex's id
     * @return                  All connected edge's id 
     */
    QList<QString> unregisterVertex(const QString& vertexid);
    /**
     * @brief unregisterEdge    Unregist edge
     * @param edgeid            Edge's id
     */
    void unregisterEdge(const QString& edgeid);
    /**
     * @brief connect           Connect double vertex
     * @param vertexbid         Begin of vertex's id
     * @param vertexeid         End of vertex's id
     * @param edgeid            Edge's id
     * @return                  True if connected success
     */
    bool connect(const QString &vertexbid, const QString &vertexeid,const QString &edgeid);
    /**
     * @brief disconnect        Disconnect double vertex
     * @param vertexbid         Begin of vertex's id
     * @param vertexeid         End of vertex's id
     * @return                  Edge's id
     */
    QString disconnect(const QString &vertexbid, const QString &vertexeid);
    /**
     * @brief isConnected       Determine if there connected
     * @param vertexbid         Begin of vertex's id
     * @param vertexeid         End of vertex's id
     * @return                  True if disconnected success
     */
    bool isConnected(const QString &vertexbid, const QString &vertexeid);
    /**
     * @brief getGraphName      Get graph name
     * @return                  QString for graph's name
     */
    QString getGraphName() const;
    /**
     * @brief setGraphName      Set graph name
     * @param name              QString for graph's name
     */
    void setGraphName(const QString &name);
    /**
     * @brief getGroup          Get group name
     * @return                  QString for group's name
     */
    QString getGroup() const;
    /**
     * @brief setGroup          Set group name
     * @param group             QString for group's name
     */
    void setGroup(const QString &group);
    /**
     * @brief getConnectedEdge  Get connect edge's name
     * @param vertexbid         Begin of vertex's id
     * @param vertexeid         End of vertex's id
     * @return                  QString for edge's name
     */
    QString getConnectedEdge(const QString &vertexbid, const QString &vertexeid) const;
    /**
     * @brief getNeighborhoodEntirelyOutgoingArcAt  Get neighborhood entirely outgoing arc at
     * @param from                                  From id
     * @return                                      QList for all from's id
     */
    QList<QString> getNeighborhoodEntirelyOutgoingArcAt(const QString& from) const;
    /**
     * @brief getNeighborhoodEntirelyInwardArcAt    Get neighborhood entirely inward arc at
     * @param to                                    From id
     * @return                                      QList for all from's id
     */
    QList<QString> getNeighborhoodEntirelyInwardArcAt(const QString& to) const;
    /**
     * @brief getVertexSet      Get vertex set
     * @return                  Set for vertex
     */
    QList<QString> getVertexSet() const;
    /**
     * @brief getEdgeSet        Get edge set
     * @return                  Set for edge
     */
    QList<QString> getEdgeSet() const;
    /**
     * @brief adjacencyList
     * @return 
     */
    QHash<QString,QHash<QString,QString>> adjacencyList() const;
    /**
     * @brief toJson            Convert graph information to json
     * @return                  Json object info
     */
    QJsonObject toJson() const;
    /**
     * @brief fromJson          Convert json object information to graph
     * @return                  True for success
     */
    bool fromJson(QJsonObject);
protected:
    virtual QVertexObjectModel *customCreateVertexModel(const QString &pluginName);
    virtual QEdgeObjectModel *customCreateEdgeModel(const QString &pluginName);
signals:
    void signal_registerVertex(QString vertexid,QString pluginName);
    void signal_registerEdge(QString edgeid,QString pluginName);
    void signal_unregisterVertex(QString vertexid);
    void signal_unregisterEdge(QString edgeid);
    void signal_connect(QString vertexbid,QString vertexeid,QString edgeid);
    void signal_disconnect(QString vertexbid,QString vertexeid,QString edgeid);
private:
    /**
     * @brief init Init graph model
     */
    void init();
protected:
    QDigraphModel(QDigraphModelPrivate &pri);
private:
    QScopedPointer<QDigraphModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QDigraphModel)
    Q_DISABLE_COPY(QDigraphModel)
};

#endif // QDigraphModel_H
