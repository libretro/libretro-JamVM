#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "jam.h"
#include "excep.h"
#include "reflect.h"
#include "natives.h"

uintptr_t *is_squirrel_jme_jvm(Class *class, MethodBlock *mb, uintptr_t *ostack){
   *ostack++ = 0;//false
   return ostack;
}

uintptr_t *map_service(Class *class, MethodBlock *mb, uintptr_t *ostack){
   Object *string   = (Object *)ostack[1];
   
   char *service_name = string ? String2Utf8(string) : NULL;
   char service_class[100];
   bool return_null = false;
   
   if(strcmp(service_name, "net.multiphasicapps.squirreljme.lcdui.DisplayManager") == 0){
      strcpy(service_class, "libretro.DisplayManager");
   }
   else if(strcmp(service_name, "net.multiphasicapps.squirreljme.rms.RecordClusterManager") == 0){
      strcpy(service_class, "libretro.FileRecordClusterManager");
   }
   else{
      return_null = true;
   }
   
   sysFree(service_name);
   
   if(!return_null){
      *ostack++ = (uintptr_t)createString(service_class);
   }
   else{
      *ostack++ = (uintptr_t)NULL;
   }
   return ostack;
}

VMMethod ext_systemvm_methods[] = {
   {"isSquirrelJMEJVM",           "()Z", is_squirrel_jme_jvm},
   {NULL,                         NULL, NULL}
};

VMMethod ext_systemenvironment_methods[] = {
   {"mapService",                 "(Ljava/lang/String;)Ljava/lang/String;", map_service},
   {NULL,                         NULL, NULL}
};

VMClass native_methods[] = {
   {"net/multiphasicapps/squirreljme/unsafe/__Ext_systemvm__",             ext_systemvm_methods},
   {"net/multiphasicapps/squirreljme/unsafe/__Ext_systemenvironment__",    ext_systemenvironment_methods},
   {NULL,                                                                  NULL}
};
