//Modified minimal Felker init to enable running in proot
#include <signal.h>
#include <unistd.h>

int proot_mode(int argc, char* argv[]);

int main(int argc,char* argv[])
{
        if(getpid()!=1) return proot_mode(argc,argv);
        return execve("/etc/rc", (char *[]){ "rc", 0 }, (char *[]){ 0 });
}

int proot_mode(int argc, char* argv[])
{
//proot-specific setup here
return execve("/etc/rc", (char *[]){ "rc", 0 }, (char *[]){ 0 });
}
