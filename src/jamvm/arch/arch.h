#if defined(__arm__)
#include "arm.h"
#elif defined(__x86_64__)
#include "x86_64.h"
#elif defined(__i386__)
#include "i386.h"
#elif defined(__mips__)
#include "mips.h"
#elif defined(__powerpc__)
#include "powerpc.h"
#elif defined(__sparc__)
#include "sparc.h"
#else
#error "Your CPU architecture is not defined, please check arch.h"
#endif
