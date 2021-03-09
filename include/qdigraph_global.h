/*
==========================================================================
This confidential and proprietary software may be only used as authorized
by a licensing agreement from Caffrey.
(C) COPYRIGHT 2019 Caffrey. ALL RIGHTS RESERVED
Filename            :       qdigraph_global.cpp
Author              :       Caffrey
Data                :       2019-10-10
Version             :       1.0
Description         :       export for Qt library
Modification History    :   NONE
Data            By          Version         Change Description
===========================================================================
2019/10/10      Caffrey     1.0             Original
===========================================================================
*/

#ifndef QDIGRAPH_GLOBAL_H
#define QDIGRAPH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT5_DIGRAPH_LIBRARY)
#  define QDIGRAPHSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QDIGRAPHSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QDIGRAPH_GLOBAL_H
