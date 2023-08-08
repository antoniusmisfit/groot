# groot
A minimal init for prooted Linux distributions
## Building
Groot can be built within a prooted distro by running the build.sh script included.
## Installing
After building, groot can be installed by copying it to /usr/bin/groot within your prooted distro.
## Why is it named "groot"?
As proot is a user space implementation of chroot, I couldn't pass up the obvious tongue-in-cheek reference to a certain fictional plant-based intergalactic superhero.
## ...But why run an init inside proot?
This [Red Hat Developers article](https://developers.redhat.com/blog/2019/04/24/how-to-run-systemd-in-a-container) advocating for running systemd in a container also applies to proot.

However, proot is a different beast than chroot-based containers. As proot relies on using ptrace to isolate the guest filesystem from the host, proot cannot isolate the process view within the prooted distro. Therefore, the initial command run in proot will not be seen as PID-1. As a consequence of this, it's not possible to run a traditional init within proot without modification as they expect to be PID-1. So it was necessary to write a simple proof init that works with proot's limitations.
