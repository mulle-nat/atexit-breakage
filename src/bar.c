#include <stdio.h>
#include <stdlib.h>


static void  bar_exit( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);
}


void  bar( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);

   fprintf( stderr, "-- install bar_atexit\n");
   atexit( bar_exit);
}

