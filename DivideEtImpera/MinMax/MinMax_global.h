#ifndef MINMAX_GLOBAL_H
#define MINMAX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MINMAX_LIBRARY)
#  define MINMAXSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MINMAXSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MINMAX_GLOBAL_H
