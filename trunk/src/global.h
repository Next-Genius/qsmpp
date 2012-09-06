#pragma once

#ifndef QSMPP_GLOBAL_H
#define QSMPP_GLOBAL_H

#include <QtCore/QtGlobal>


#if defined(QSMPP_LIBRARY)
#  define QSMPP_EXPORT Q_DECL_EXPORT
#else
#  define QSMPP_EXPORT Q_DECL_IMPORT
#endif

#endif // QSMPP_GLOBAL_H
