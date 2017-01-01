#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdio.h> 


extern int alphasort();
char pathname[MAXPATHLEN];   


int main(void)   { 

    int count, i;
    struct direct **files;
    int file_select();   

    if (getwd(pathname) == NULL) {
        printf("Error getting path\n");
        exit(0);
    } 

    printf("Current Working Directory = %s\n",pathname); 

    count = scandir(pathname, &files, file_select, alphasort);

    if (count <= 0) {
        printf("No files in this directory\n");
        exit(0);
    } 

    printf("Number of files = %d\n",count); 

    for (i=1; i < count + 1; ++i)
        printf("%s  ", files[i-1]->d_name); 

    printf("\n");

} 


int file_select(struct direct   *entry) {

    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
        return (FALSE);
    else
        return (TRUE);
}