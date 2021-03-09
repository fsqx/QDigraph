/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic vertex object view
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QVERTEXOBJECTVIEW_H
#define QVERTEXOBJECTVIEW_H

#include "qdigraph_global.h"
#include <qwidget.h>

class QVertexObjectViewPrivate;
class QVertexObjectModel;
class QDIGRAPHSHARED_EXPORT QVertexObjectView: public QWidget
{
    Q_OBJECT
public:
    QVertexObjectView();
    virtual ~QVertexObjectView();
public:
    /**
     * @brief setReadonly   Set read-only mode
     */
    virtual void setReadonly(bool);

    /**
     * @brief setModel      Set model
     */
    void setModel(QVertexObjectModel*);
    /**
     * @brief model 
     * @return
     */
    QPointer<QVertexObjectModel> model();
    /**
     * @brief dataUpdate
     */
    virtual void dataUpdate();
    /**
     * @brief setScore      Show score
     * @param score         Score
     */
    virtual void setScore(const QString &score);
private:
    /**
     * @brief init
     */
    void init();
public slots:
    void slot_modelDataUpdate();
protected:
    QVertexObjectView(QVertexObjectViewPrivate&pri);
private:
    QScopedPointer<QVertexObjectViewPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QVertexObjectView)
    Q_DISABLE_COPY(QVertexObjectView)
};


#endif // QVERTEXOBJECTVIEW_H
