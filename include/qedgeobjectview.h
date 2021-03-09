/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic edge object view
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QEDGEOBJECTVIEW_H
#define QEDGEOBJECTVIEW_H

#include "qdigraph_global.h"
#include <QObject>
#include <QStyleOptionGraphicsItem>


class QEdgeObjectModel;
class QEdgeObjectViewPrivate;
class QDIGRAPHSHARED_EXPORT QEdgeObjectView : public QObject
{
    Q_OBJECT
public:
    QEdgeObjectView();
    virtual ~QEdgeObjectView();
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget,QLineF line);
    /**
     * @brief update        Update the interface, triggered when the data model changes or the model is set
     */
    virtual void update();

    void setModel(QEdgeObjectModel*);
    QEdgeObjectModel* model();
public slots:
    void slot_modelDataUpdate();
protected:
    QEdgeObjectView(QEdgeObjectViewPrivate&pri);
private:
    /**
     * @brief init 
     */
    void init();
private:
    QScopedPointer<QEdgeObjectViewPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QEdgeObjectView)
    Q_DISABLE_COPY(QEdgeObjectView)
};
#endif // QEDGEOBJECTVIEW_H
