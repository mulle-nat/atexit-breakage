#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>


static void  main_atexit( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);
}


int  main( int argc, char *argv[])
{
   void   *handle;
   void   (*bar)( void);

   fprintf( stderr, "-> dlopen\n");
   handle = dlopen( argv[ 1], RTLD_NOW);
   bar    = dlsym( handle, "bar");
   (*bar)();
   fprintf( stderr, "<- dlclose\n");
   dlclose( handle);

   fprintf( stderr, "-- install main_atexit\n");
   atexit( main_atexit);
   fprintf( stderr, "exit\n");

   exit( 0);
}
