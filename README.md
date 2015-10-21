# Pipong
[![Build Status](https://travis-ci.org/pauis/pipong.svg)](https://travis-ci.org/pauis/pipong)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
> **Notice: This application is currently under development.**

## Support List
### x86_64
| GNU/Linux | OSX | Windows |
|:-:|:-:|:-:|
| O | TBD | TBD |

## Usage
### Software
#### Excutable file
Run the excutable file.
```
$ ./pipong
```

#### Makefile
This project supports [Make](http://www.gnu.org/software/make/). Makefile in this project supports some functions.
```
// Build excutable file
$ make

// (Optional) Remove excutable file and .o files
$ make clean
```

## Download and Install
### WiringPi
```
// Download wiringPi code.
$ git clone git://git.drogon.net/wiringPi

// Go to wiringPi directory.
$ cd wiringPi

// Run the 'build' script. It will automatically install the library.
$ ./build
```
### Pipong
```
// Download Pipong code.
$ git clone https://github.com/Pauis/pipong.git

// Go to Pipong directory.
$ cd pipong

// Build excutable file using Make.
$ make

// (If you want to build the project with Clang, attach arguments)
$ make CXX=clang++
```
## Update
### WiringPi
```
// Go to wiringPi directory.
$ cd wiringPi

// Download new code.
$ git pull origin

// Run the script.
$ ./build
```
### Pipong
```
// Go to Pipong directory.
$ cd pipong

// Download new code.
$ git pull origin

// Run Make.
$ make

// (If you want to build the project with Clang, attach arguments)
$ make CXX=clang++
```

## Notice
* This project is for Command Line Interface.
* This project uses [wiringPi](http://wiringpi.com/) library, [GCC](https://gcc.gnu.org/) (or Clang) and [Make](http://www.gnu.org/software/make/), so you need them before compiling Pipong.

## License
This project is based on Dong-jun Lim's contribution including *.c, *.h and Makefile.
Source code is distributed with MIT License.
