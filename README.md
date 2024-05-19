# ca
CA is a Linux command line utility offering file manipulation, system info retrieval, and text processing. Simplify tasks like file copying and viewing, enhancing your command line experience.

Introducing 'ca' - the CLI command that bravely admits it's not the most efficient or fast alternative to 'cat'! Say goodbye to sluggish file viewing and hello to... well, slightly less sluggish file viewing. With ca, you'll experience a refreshing honesty about its performance!

# CA Usage Guide

## Introduction
CA is a versatile command line utility designed to simplify common tasks in Linux environments. From file manipulation to system information retrieval, CA offers a range of functionalities to enhance your command line experience.

## Usage

- ca -p {chars_separated_with_underscores}
- ca sf filePath [here sf = show file]
- ca sf-l [to show file with number lines]
- ca cp SourceFile DistFile
- ca finfo FileName [to get info about a specific file]
- ca lines FileName

System:
- ca -p 'text'
- ca -sysinfo
- ca -sysS [to show storage capacity]
- ca -time
- ca -del FileName


## Options
- `-p`: Print characters separated with underscores.
- `sf`: Show the contents of a specified file.
- 'c': Create a blank file
- `sf-l`: Show the contents of a file with line numbers.
- `cp`: Copy a source file to a destination file.
- `finfo`: Display information about a specific file.
- `lines`: Display the number of lines in a file.
- `-sysinfo`: Show system information.
- `-sysS`: Display storage capacity.
- `-time`: Show current date and time.
- `-del`: Delete a specified file.

## Installation
1. Clone the repository
2. cd into the repository folder
3. run : chmod +x install.sh
    or, sudo chmod +x install.sh
4. ./install.sh
5. start using "ca"

## Note
CA strives to simplify command line tasks, but please note that it may not always be the most efficient solution.



