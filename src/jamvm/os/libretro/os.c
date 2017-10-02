/*
 * Copyright (C) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2014
 * Robert Lougher <rob@jamvm.org.uk>.
 *
 * This file is part of JamVM.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "../../jam.h"
#include "../../../libretro/libretro_exports.h"

long long nativePhysicalMemory() {
   return system_memory_size;
}

void *nativeStackBase() {
    return NULL;
}

int nativeAvailableProcessors() {
    return 1;
}

char *nativeLibError() {
    //return dlerror();
   return "Dynamic librarys are not supported with the libretro port.\n";
}

char *nativeLibPath() {
    //return getenv("LD_LIBRARY_PATH");
   return system_path;
}

void *nativeLibOpen(char *path) {
    //return dlopen(path, RTLD_LAZY);
   return NULL;
}

void nativeLibClose(void *handle) {
    //dlclose(handle);
}

void *nativeLibSym(void *handle, char *symbol) {
    return dlsym(handle, symbol);
}

char *nativeLibMapName(char *name) {
   char *buff = sysMalloc(strlen(name) + sizeof("lib.so") + 1);

   sprintf(buff, "lib%s.so", name);
   return buff;
}

char *nativeJVMPath() {
   //Should return $(retroarchsysdir)/javame
   /*
    Dl_info info;
    char *path;

    if(dladdr(nativeJVMPath, &info) == 0) {
        printf("Error: dladdr failed.  Aborting VM\n");
        exitVM(1);
    }

    path = sysMalloc(strlen(info.dli_fname) + 1);
    strcpy(path, info.dli_fname);

    return path;
   */
   return system_path;
}

