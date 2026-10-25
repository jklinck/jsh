# jsh - a mini unix shell

The shell used in Mac computers is zsh (z shell) and linux systems use bash (Born again shell). I decided to name this shell after myself as my first name is Joe, so it is aptly named jsh (Joe shell).

# Functionalities
This is a mini unix shell where you can run these commands:
    `cd`: to move from directory to another
    `pwd`: to view the filepath to your current directory
    `ls`: to list the files in your current directory
    `clear`: to clear the terminal screen
    `exit`: to exit the shell and return the original shell

# Dependencies
This project is equipped with a Makefile which compiles for x86_64 architecture. The project will run on Mac computers with a M1, M2 or M3 chip, but for M4 or higher you will need to install Rosetta first. 

# Running the project
To run the project you only need to run `make run`. This command will delete previous executables, generate the executable and then run it.

If you prefer to run everything manually you can delete the previous executable with `make clean`, run `make main` to recompile main and run `./main` to run the project.

To generate assembly code run `make asm`. 
