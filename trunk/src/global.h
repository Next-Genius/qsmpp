#ifndef SMPP_GLOBAL_H
#define SMPP_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(SMPP_LIBRARY)
#  define SMPP_EXPORT Q_DECL_EXPORT
#else
#  define SMPP_EXPORT Q_DECL_IMPORT
#endif

#endif // SMPP_GLOBAL_H
