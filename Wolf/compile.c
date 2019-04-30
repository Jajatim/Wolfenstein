#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define NO_TARGET -1
#define WIN_TARGET 1
#define OSX_TARGET 2
#define LIN_TARGET 3

#ifdef _WIN32 //_WIN64 will work too
    #define COMPILE_TARGET WIN_TARGET
#elif __APPLE__
    #define COMPILE_TARGET OSX_TARGET
#elif __linux__
    #define COMPILE_TARGET LIN_TARGET
/*
#elif __unix__
    // Unix
*/
#else
    #define COMPILE_TARGET NO_TARGET
#endif


#define CC "gcc "
#define SRC_PATH "./src_list.txt"
#define WIN_LIB "-L lib -lmingw32 -lSDL2main -lSDL2.dll" //Todo, not sure what to add...
#define OSX_LIB "-F . -framework SDL2 -rpath ." //Paths needs to be updated
#define LIN_LIB "" //Todo

int main() {
    //Main string, start as "gcc "
    char scompil[4096] = CC;

    //Exit if the OS is not known
    if (COMPILE_TARGET == NO_TARGET) {
        printf("Target OS has not been found\n");
        exit(1);
    }

    //Opening the sources file
    int fd = open(SRC_PATH, O_RDONLY);
    if (fd < 0) {
        printf("Failed to open %s\n", SRC_PATH);
        perror(NULL);
        exit(1);
    }

    //Fills the string with the sources (replaces \n with spaces)
    // After here, scompil looks like : "gcc main.c utils.c "
    char buf[1] = "a";
    int res = read(fd, buf, 1);
    int i = 0;
    while (scompil[i] != '\0')
        i++;
    while (res > 0) {
        if (buf[0] == '\n')
            buf[0] = ' ';
        scompil[i++] = buf[0];
        res = read(fd, buf, 1);
    }
    if (res == -1) {
        perror("Failed to read");
        exit(1);
    }

    //Adds a space after the sources
    scompil[i++] = ' ';
    scompil[i] = '\0';

    //Including the libraries, depending on the OS detected
    switch (COMPILE_TARGET) {
        case WIN_TARGET:
            strcat(scompil, WIN_LIB);
            break;
        case OSX_TARGET:
            strcat(scompil, OSX_LIB);
            break;
        case LIN_TARGET:
            strcat(scompil, LIN_LIB);
            break;
    }

    //Using the created string to launch the compilation
    printf("compil str is |%s|\n", scompil);
    system(scompil);
    system("pause");

    return 0;
}
