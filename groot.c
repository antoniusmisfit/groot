//Modified minimal Felker init to enable running in proot
#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>

int proot_mode(int argc, char* argv[]);

int main(int argc,char* argv[])
{
        sigset_t set;
        int status;
        //If we're not PID-1, then we're in proot
        if (getpid() != 1) return proot_mode(argc,argv);;

        sigfillset(&set);
        sigprocmask(SIG_BLOCK, &set, 0);

        if (fork()) for (;;) wait(&status);

        sigprocmask(SIG_UNBLOCK, &set, 0);

        setsid();
        setpgid(0, 0);
        return execve("/etc/rc", (char *[]){ "rc", 0 }, (char *[]){ 0 }
}

int proot_mode(int argc, char* argv[])
{
//proot-specific setup here
return execve("/etc/rc", (char* []){"rc",0}, (char* []){0});
}
