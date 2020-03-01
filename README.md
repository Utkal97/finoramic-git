# finoramic-git

## Install python packages script :-

Script : installer.py
Input file : dependencies.json

Format of the input file : {  "Dependencies" : [......(list of packages as string)...] } <br />
An example "dependencies.json" file is given in repository.

The script is written in python3. <br />
* installPackages is a function that takes all required dependencies listed in input file and calls install function.
* install function executes pip install command for the given package.
  *  If failed to install, it returns 0
  *  If succeeded to install, it returns 1 
* installPackages then checks if the package failed to install. 
  *  If install(package)==0, it appends the current package to failed_packages list.
* printStatus function prints whether all the packages have been successfully installed or not. If not, it lists all the failed packages.
