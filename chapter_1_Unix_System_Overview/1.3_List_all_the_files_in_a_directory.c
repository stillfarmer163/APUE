#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#define TEST_COMMENT 0

int
main( int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *dirp = NULL;

    if ( 2 != argc)
    {
        printf("usage: ls directory_name\n");

        /* exit included in <stdlib.h> 
         * EXIT_FAILURE is 1 in <stdlib.h>
         * EXIT_SUCCESS is 0 in <stdlib.h> */

        exit(EXIT_FAILURE);
    }

    if ( NULL == (dp = opendir(argv[1])))
    {
        printf("can not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while( NULL != (dirp = readdir(dp)))
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(EXIT_SUCCESS);
}

#if TEST_COMMENT
/* exit included in <stdlib.h> 
 * EXIT_FAILURE is 1 in <stdlib.h>
 * EXIT_SUCCESS is 0 in <stdlib.h> 
 * */

/* DIR *opendir(const char *__name); included in <dirent.h>
*  struct dirent *readdir(DIR *dp); included in <dirent.h>
*  int closedir(DIR *dp); included in <dirent.h>
*/
#endif
