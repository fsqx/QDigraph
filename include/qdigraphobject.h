/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraphobject.h
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       basic class for graph.
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2021/3/8      Caffrey         1.0             Original
===========================================================================
*/
#ifndef QDIGRAPHOBJECT_H
#define QDIGRAPHOBJECT_H

#include <QObject>

#include "qdigraph_global.h"

class QDIGRAPHSHARED_EXPORT QDigraphObject : public QObject
{
    Q_OBJECT
public:
    explicit QDigraphObject(QObject* parent = nullptr);

    void init();

signals:
};

#endif // QDIGRAPHOBJECT_H
