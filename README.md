Linux Loadable Kernel modules made with love
=======================

Hi! I see you happen to have stumbled upon my wonderful LKM playground. Here are a couple of LKM's that do some cool stuff. Right now I only made a helloworld lkm module and a systemhook-intercepting module. The software in references is stuff I didnt write, but I figured I would include it incase someone wanted to see some well commented code. Anyway, look around, its pretty neat.

you compile these bad boys with three simple steps.

1) install the linux-headers equivalent on your system

2) run make

3 )as root, insmod [module-name].ko


and then you can view the output of each rootkit by using dmesg
