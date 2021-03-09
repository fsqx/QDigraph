/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic class for graph.
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey         1.0             Original
===========================================================================
*/

#ifndef QDIGRAPHVIEW_H
#define QDIGRAPHVIEW_H

#include "qdigraph_global.h"
#include <QMap>
#include <QWidget>
#include <QVariant>
#include <QGraphicsWidget>
#include <qvertexobjectview.h>
#include <qedgeobjectview.h>
#include <QString>
#include <functional>



class QDigraphViewPrivate;
class QDigraphModel;
class QDIGRAPHSHARED_EXPORT QDigraphView: public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief QDigraphView  Simple graph constructed func
     * @param parent        Parent widget
     * @param f             Interface display mode
     */
    QDigraphView(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    /**
     * @brief ~QDigraphView Distructed func
     */
    virtual ~QDigraphView();
    /**
     * @brief setScale      Set display scale
     */
    void setScale(qreal);
    /**
     * @brief scale         Get display scale in this time
     * @return              Qreal for scale
     */
    qreal scale() const;
    /**
     * @brief exporpictures Export praph to picture
     * @param path          Picture's path
     * @return              True for success
     */
    bool exporpictures(const QString &path);
    /**
     * @brief setModel      Set graph model
     */
    void setModel(QDigraphModel *);
    /**
     * @brief model         Get graph model
     * @return              Point for graph model
     */
    QDigraphModel* model() const;
    /**
     * @brief getSelectedVertexs  Get vertex which has been selected
     * @return                    Vertex selected list
     */
    QList<QString> getSelectedVertexs() const;
    /**
     * @brief getAllVertexs       Get all vertexs from graph
     * @return                    Vertex selected list
     */
    QList<QString> getAllVertexs();
    /**
     * @brief getAllEdges         Get all edge from graph
     * @return                    Edge selected list
     */
    QList<QString> getAllEdges();
    /**
     * @brief getVertexPosAt      Get pos from vertex which has been selected
     * @param id                  Vertex's id
     * @return                    Double pos for vertex
     */
    QPointF getVertexPosAt(const QString &id);
    /**
     * @brief getVertexSizeAt     Get size from vertex which has been selected
     * @param id                  Vertex's id
     * @return                    Double size for vertex
     */
    QSizeF getVertexSizeAt(const QString& id);
    /**
     * @brief setVertexPos        Set vertex's pos
     * @param id                  Vertex's id
     * @param p                   New pos for vertex
     */
    void setVertexPos(const QString &id, QPointF p);
    /**
     * @brief setVertexSize       Set vertex's size
     * @param id                  Vertex's id
     * @param s                   New size for vertex
     */
    void setVertexSize(const QString &id, QSizeF s);
    /**
     * @brief setVertexFlags      Set vertex's flag
     * @param vertexid            Vertex's id
     * @param flag                New flag for vertex
     * @param enabled             True if vertex is enable
     */
    void setVertexFlags(const QString &vertexid, QGraphicsWidget::GraphicsItemFlag flag, bool enabled = true);
    /**
     * @brief setEdgeFlags        Set edge's flag
     * @param edgeid              Edge's id
     * @param flag                New flag for edge
     * @param enabled             True if edge is enable
     */
    void setEdgeFlags(const QString &edgeid, QGraphicsWidget::GraphicsItemFlag flag, bool enabled = true);
    /**
     * @brief rotate              Rotate a angle, zero angle is face to top
     * @param angle               QReal for angle
     */
    void rotate(qreal angle);
    /**
     * @brief vertexAt            Determine whether it is a vertex
     * @param viewPos             Vertex's pos
     * @return                    QString for vertex's id
     */
    QString vertexAt(QPoint viewPos);
    /**
     * @brief edgeAt              Determine whether it is a vertex
     * @param viewPos             edge's pos
     * @return id                 QString for edge's id
     */
    QString edgeAt(QPoint viewPos);
    /**
     * @brief setVertexStyleSheet Set display style sheet
     * @param vertexid            Vertex's id
     * @param sheet               QString sheet
     */
    void setVertexStyleSheet(const QString &vertexid, const QString & sheet);
    /**
     * @brief setVertexScore      Set vertex's score
     * @param vertexid            Vertex's id
     * @param score               QString score
     */
    void setVertexScore(const QString &vertexid, const QString & score);
    /**
     * @brief setReadOnly
     */
    void setReadOnly(bool);
    /**
     * @brief readOnly
     * @return                  True if read only
     */
    bool readOnly();
    /**
     * @brief setDelegate 
     * @param customCreateVertexView 
     * @param customCreateEdgeView 
     */
    void setDelegate(std::function<QVertexObjectView*(const QString &pluginName)> customCreateVertexView, std::function<QEdgeObjectView*(const QString &pluginName)> customCreateEdgeView);


protected:
    virtual void layout(const QString &vertexid) = 0;
private slots:
    void slot_model_registerVertex(QString vertexid, QString pluginName);
    void slot_model_registerEdge(QString edgeid, QString pluginName);
    void slot_model_unregisterVertex(QString vertexid);
    void slot_model_unregisterEdge(QString Edgeid);
    void slot_model_connect(QString vertexbid, QString vertexeid, QString edgeid);
    void slot_model_disconnect(QString vertexbid, QString vertexeid, QString edgeid);
private:
    /**
     * @brief reloadModel         Reload model
     */
    void reloadModel(QDigraphModel *m);
    /**
     * @brief getVertexPluginMap  Get all the plugins based on QVertexObject of the graph
     * @return                    All the plugins
     */
    QMap<QString, QPointer<QVertexObjectView>> getVertexPluginMap() const;
    /**
     * @brief getEdgePluginMap    Get all the plugins based on QEdgeObject of the graph
     * @param graphName           Graph name
     * @return                    All the plugins
     */
    QMap<QString, QPointer<QEdgeObjectView>> getEdgePluginMap() const;
    /**
     * @brief getSelectedEdges    Get selected edge
     * @return
     */
    QList<QString> getSelectedEdges();
    /**
     * @brief getVertexAt         Get vertices
     * @return                    Vertex
     */
    QPointer<QVertexObjectView> getVertexAt(QString id);
    /**
     * @brief getEdgeAt           Get edge
     * @return  
     */
    QPointer<QEdgeObjectView> getEdgeAt(QString id);

    /** Operation type starts here **/
    /**
     * @brief createVertex        Create one vertex
     * @param pluginName          Node plugin name (dynamic library name)
     */
    bool createVertex(const QString &id, QVertexObjectView *vp);
    /**
     * @brief createEdge          Create one edge
     * @param pluginName          Node plugin name (dynamic library name)
     */
    bool createEdge(const QString &id, QEdgeObjectView *e);
    /**
      * @brief connectVertexes    connect Vertex
      * @param beginVertexID      
      * @param endVertexID 
      * @param edgeID
      */
    void connectVertexes(const QString &beginVertexID, const QString &endVertexID, const QString &edgeID);
    /**
      * @brief disconnectVertexes Disconnect Vertex
      * @param beginVertexID
      * @param endVertexID
      * @param edgeID
      */
    void disconnectVertexes(const QString &beginVertexID, const QString &endVertexID, const QString &edgeID);
    /**
      * @brief deleteVertexAt     Delete the specified vertices of the specified graph
      * @param id       
      */
    void deleteVertexAt(const QString& id);
    /**
      * @brief deleteEdgeAt       Delete the specified vertices of the specified graph
      * @param id    
      */
    void deleteEdgeAt(const QString& id);
    /**
      * @brief clear  Clear all
      */
    void clear();
    /**
     * @brief init
     */
    void init();
signals:
    /**
     * @brief selectionChanged  Vertex selection change signal
     * @param idlist
     */
    void selectionChanged(QStringList  idlist);
public slots:
    /**
     * @brief setVertexSelected Set vertices to be selected
     * @param id
     */
    void setVertexSelected(QString id);
private slots:
    void slot_selectionChanged();
protected:
    QDigraphView(QDigraphViewPrivate&pri, QWidget *parent, Qt::WindowFlags f);
private:
    QScopedPointer<QDigraphViewPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QDigraphView)
    Q_DISABLE_COPY(QDigraphView)
};

#endif // QDigraphVIEW_H
