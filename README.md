# BeagleBoneBackupCam V1.0

Supporting files for my element14 Project 14 BeagleBone AI Seeing/Talking Backup Camera:

https://www.element14.com/community/community/project14/visionthing/blog/2019/10/20/seeing-around-corners-beagle-bone-back-up-car-camera-part-1-introduction

Installation:

In the terminal, at a directory of choice, type the following:
  git clone https://github.com/RaisingAwesome/BeagleBoneBackupCam
    
Copy classification.tidl.cpp over the existing Cloud9 example:
  cloud9-->BeagleBone-->AI-->tidl-->classification.tidl.cpp
  
  edit the paths in classification.tidl.cpp line 104 to match your directory
  You'll need to mount a RAMDisk.  Do this in the terminal:
    mkdir ~/ramdisk
    sudo nano /etc/fstab
  Paste this at the bottom and save with CTRL X:
  myramdisk  /home/debian/ramdisk  tmpfs  defaults,size=64k,x-gvfs-show  0  0
  
  If you change code, you'll need to recompile.  type:
    gcc servoPot.c -o s #to recompile servoPot.c
    gcc tfmini.c -o t  #to recompile tfmini.c
    ./mymake #to recompile wally.cpp  
  
  Use the Cloud9 IDE to Run classification.tidl.cpp.  Set your runner to "BeagleBone C or C++"
