# Pipong
[![Build Status](https://travis-ci.org/pauis/pipong.svg?branch=master)](https://travis-ci.org/pauis/pipong)
[![Build status](https://ci.appveyor.com/api/projects/status/9ow6e8p23wff3ilx/branch/master?svg=true)](https://ci.appveyor.com/project/pauis/pipong/branch/master)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Support List
| Linux | OSX | Windows |
|:-:|:-:|:-:|
| O | TBD | Experimental |

## Usage
### Command
#### Linux, OSX
```
// Run the executable.
~/pipong $ posix_out/pipong
```

#### Windows
Double-click the executable file, or run it on the Command Prompt.

### Default Key
| Description | Default Key |
|:-:|:-:|
| Start | <kbd>s</kbd> |
| Exit | <kbd>q</kbd> |
| Move Player 1's Paddle Up | <kbd>e</kbd> |
| Move Player 1's Paddle Down | <kbd>f</kbd> |
| Move Player 2's Paddle Up | <kbd>o</kbd> |
| Move Player 2's Paddle Down | <kbd>k</kbd> |

## Download and Install
### Linux, OSX
```
// Download Pipong code anywhere you want. It's an example for beginners.
~ $ git clone https://github.com/pauis/pipong.git

// Go to Pipong directory.
~ $ cd pipong

// Build executable using Make.
~/pipong $ make
```

### Windows
First, you need the latest Visual Studio. You can [download Visual Studio Community for limited purposes](https://www.visualstudio.com/).
After finishing the installation, click 'Open repository with...' and 'Visual Studio'.
Use Control+F5 to build the app.

## Update
### Linux, OSX
```
// Go to Pipong directory.
~ $ cd ~/pipong

// Download the latest code.
~/pipong $ git pull

// Run Make.
~/pipong $ make
```

### Windows
On Visual Studio's default screen, you can see the Team Explorer screen. Pull the latest code with it.

## License
This project is distributed with MIT License.
