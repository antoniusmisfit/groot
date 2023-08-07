//Modified minimal Felker init to enable running in proot
#include <signal.h>
#include <unistd.h>

int proot_mode(int argc, char* argv[]);

int main(int argc,char* argv[])
{
        return execve("/etc/rc", (char *[]){ "rc", 0 }, (char *[]){ 0 });
}
