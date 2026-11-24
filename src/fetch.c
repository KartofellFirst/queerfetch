#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define global char
#define globall long
#define gl short
#define ball bool

global *KVER = "unavailable";
global *UNAME = "unavailable";
global *OSNAME = "unavailable";
global *SHELLNAME = "unavailable";
globall UPTIME_H, UPTIME_M;


// -39 to 61, gives total of 100 points of gayness :3
// tho i dont know if it saves any RAM, but it looks cute and makes me happy so im keeping it
// (wow VScode autocomplete just sugggested "it looks cute and makes me happy" and i lwk agree to that)
gl GAYNESS = -39; 


/* -39 is 0, 61 is 100 ->
100 Secure
85 Anxious-Preoccupied
70 Ambivalent
55 Avoidant
40 Insecure
25 Unresolved
10 Fearful-Avoidant
0 Disorganized
*/
gl ATTACHMENT_SECURITY = -39;
global *ATTACHMENT_STYLE = "Disorganized";


// Giving a bottom license by default,
// 50/100 will be the split. Higher than 50 will be a top license
gl BOTTOM_LICENSE_POINTS = -39;
ball up = false;


// what do we have left to discover about user system? 
// shell + 
// uptime + 
// kernel + 
// username - 
// max disk space - 
// used/max ram -
// cpu usage -
// gpu usage -
// battery availability -
// local time -
// current hour - 
// sound volume - 


void get_shell(void)
{
    char *shell = getenv("SHELL"); if (shell != NULL) {
        char *slash = strrchr(shell, '/');
        SHELLNAME = (slash != NULL) ? slash + 1 : shell;
    }
}

void get_uptime(void)
{
    struct timespec time = {0};

    #if defined(CLOCK_BOOTTIME)
        clock_gettime(CLOCK_BOOTTIME, &time);
    #elif defined(CLOCK_UPTIME)
        clock_gettime(CLOCK_UPTIME, &time);
    #elif defined(__APPLE__)
        clock_gettime(CLOCK_MONOTONIC, &time);
    #else
        return;
    #endif

    UPTIME_H = time.tv_sec / 3600;
    UPTIME_M = (time.tv_sec % 3600) / 60;
}

void get_kernel(void)
{
    static struct utsname data;
    if (uname(&data) == 0) {
        KVER = data.release;
        OSNAME = data.sysname; 
    }
}

void get_user(void)
{
    char *user = getenv("USER");
    if (user == NULL) UNAME = getlogin() || "unavailable";
}


int main() {

    get_kernel();
    get_uptime();
    get_user();
    get_shell();

    printf("Hello, World!\n");
    printf("Kernel Version: %s\n", KVER);
    printf("OS Name: %s\n", OSNAME);    
    printf("Shell Name: %s\n", SHELLNAME);
    printf("Username: %s\n", UNAME);
    printf("Uptime: %ld hours, %ld minutes\n", UPTIME_H, UPTIME_M);
    return 0;
}