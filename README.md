# Rubber Dolphy
PoC about Bad USB for FlipperZero with exfiltration capabilities on device via mass storage

The idea is to have a way to copy some data into FlipperZero when using it as **BadUsb** device, to perfom data exfiltration. 

Right now the project it's in a early code stage, not more than a PoC and kind of "only works on my computers", I tested it on a **Arch Linux** and on a **Windows 11** computer. Testing this on a Mac OS still on the TODO list.

I have some ideas that I would like to try in order to improve the whole thing and push features to have a more useful and versatile FlipperZero BadUSB device. If I feel that the project has a good welcome, people try it and give support at least with :star: I will ponder continue with this ideas.

For now image for mass storage capabilities has 4.2 MB and type FAT (12-bit version)

## Demo

### Linux

[![Linux PoC](https://raw.githubusercontent.com/carvilsi/rubber-dolphy/main/.github/images/thumbnail_flipper_exfiltration_bad_usb_linux_poc.png)](https://raw.githubusercontent.com/carvilsi/rubber-dolphy/main/.github/images/flipper_exfiltration_bad_usb_linux_poc.mp4)

### Windows

[![Windows PoC](https://raw.githubusercontent.com/carvilsi/rubber-dolphy/main/.github/images/thumbnail_flipper_exfiltration_bad_usb_windows_poc.png)](https://raw.githubusercontent.com/carvilsi/rubber-dolphy/main/.github/images/flipper_exfiltration_bad_usb_windows_poc.mp4)

## Install and Run

Clone this repo somewhere on your machine. 

### Flipper Zero preparation

- Create *rubber_dolphy* folder on *SD Card/apps_data/*
- Create *msi* folder on *SD Card/apps_data/rubber_dolphy*
- Copy *rubber-dolphy/img/rdbdsbms.img* to *SD Card/apps_data/rubber_dolphy/msi/*

### Compile and launch it on Flipper Zero

Copy the *rubber_dolphy_app* folder into *applications_user* folder on flipperZero's firmware.

On the *flipperzero-firmware* folder:

`$ ./fbt launch APPSRC=rubber_dolphy`

### Ducky Scripts

Under *ducky_scripts_examples/* folder in this repo you'll find examples for Linux and Windows.

For now **Rubber Dolphy** still using the oficial *BadUSB* FlipperZero app assests folder, to deal with *layouts* and to select the *duckyscript* to run, therefore you must upload your duckyscripts to *SD Card/badusb/* folder.

---

⚠️ ADVISORY: This FlipperZero APP should be used for authorized penetration testing and/or educational purposes only. Any misuse of this software will not be the responsibility of the author or of any other collaborator. Use it at your own computers and/or with the computer owner's permission.

---

Feedback from usage and contributions are very welcome.
Also if you like it, please leave a :star: I would appreciate it ;)

