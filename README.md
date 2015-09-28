# Pipong
![License](https://img.shields.io/badge/License-MIT-blue.svg)
## Support List
### Raspberry Pi
| Raspberry Pi 1 Model A | Raspberry Pi 1 Model A+ | Raspberry Pi 1 Model B Rev. 1 | Raspberry Pi 1 Model B Rev. 2 | Raspberry Pi 1 Model B+ | Compute Module |
|:-:|:-:|:-:|:-:|:-:|:-:|
| O*1 | O*1 | O | O | O | X |

| Raspberry Pi 2 Model B |
|:-:|
| O |

*1: Manual transmission of source code or extra device for internet connection is needed.

### Operating System
| Raspbian | Third Party Operating System |
|:-:|:-:|
| O | X |

## Usage
### Hardware
First, gather these objects.

| For all options: |
|:-:|
| 1 Over 1024*768 display |
| 1 Raspberry Pi (recommend B series) |
| For GPIO options: |
| 2 Breadboards |
| 4 pushbutton switches |
| 4 LEDs |
| 4 1KOhm resistors |
| 4 100Ohm resistors |
| 8 jumper lines |
| 12 female-male lines |

And make the controller.
```
3.3 VDC - 1KOhm resistor - pushbutton switch - GPIO 0
                                   |
                                 Ground
```
```
3.3 VDC - 1KOhm resistor - pushbutton switch - GPIO 1
                                   |
                                 Ground 
```
```
GPIO 4 - 100Ohm resistor - LED - Ground
```
```
GPIO 5 - 100Ohm resistor - LED - Ground
```
```
3.3 VDC - 1KOhm resistor - pushbutton switch - GPIO 6
                                   |
                                 Ground
```
```
3.3 VDC - 1KOhm resistor - pushbutton switch - GPIO 7
                                   |
                                 Ground
```
```
GPIO 12 - 100Ohm resistor - LED - Ground
```
```
GPIO 13 - 100Ohm resistor - LED - Ground
```

### Software
#### Excutable file
Run the excutable file.
```
pi@raspberrypi ~/pipong $ sudo ./pipong
```

#### Makefile
This project supports [Make] (http://www.gnu.org/software/make/). Makefile in this project supports some functions.
```
// Build excutable file
pi@raspberrypi ~/pipong $ make
// (Optional) Remove excutable file and .o files
pi@raspberrypi ~/pipong $ make clean
```

## Download and Install
### WiringPi
```
// Download [wiringPi] (http://wiringpi.com/) code.
pi@raspberrypi ~ $ git clone git://git.drogon.net/wiringPi

// Go to wiringPi directory.
pi@raspberrypi ~ $ cd wiringPi

// Run the 'build' script. It will automatically install the library.
pi@raspberrypi ~/wiringPi $ ./build
```
### Pipong
```
// Download Pipong code.
pi@raspberrypi ~ $ git clone https://github.com/Pauis/pipong.git

// Go to Pipong directory.
pi@raspberrypi ~ $ cd pipong

// Build excutable file using Make.
pi@raspberrypi ~/pipong $ make
```
## Update
### WiringPi
```
// Go to wiringPi directory.
pi@raspberrypi ~ $ cd wiringPi

// Download new code.
pi@raspberrypi ~/wiringPi $ git pull origin

// Run the script.
pi@raspberrypi ~/wiringPi $ ./build
```
### Pipong
```
// Go to Pipong directory.
pi@raspberrypi ~ $ cd pipong

// Download new code.
pi@raspberrypi ~/pipong $ git pull origin

// Run Make.
pi@raspberrypi ~/pipong $ make
```

## Notice
* This project is for Command Line Interface.
* This project uses [wiringPi] (http://wiringpi.com/) library, [GCC] (https://gcc.gnu.org/) and [Make] (http://www.gnu.org/software/make/), so you need them before compiling Pipong.

## License
This project is based on Dong-jun Lim's contribution including *.c, *.h and Makefile.
Source code is distributed with MIT License.
