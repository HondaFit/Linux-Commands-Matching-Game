# Linux-Commands-Matching-Game

----------------- How to Build -----------------
1) “mkdir build”        :Create a new directory “build” in the working directory
2)"cmake –S . –B build" :-S: the path to the source files “.” represents the current directory, which is ~/CPTS-223-Examples/cmake-example -B: the path to build the project, in which we can find the executable files Here we set the newly created directory “build” as this build path
3)"cmake --buid build"  :“--build”: the command for building this project according to the configuration in CMakeLists.txt The second “build” is the newly created directory build

----------------- How to Run -----------------
build/pa1

----------------- Need to Know Commands -----------------

1) rm -fdr "folder name"    : removes forcefully the folder and all the contents within it (recursivly)
2) git clone "repo link" "local folder name"    : clones the repo into a local folder
3) git rm "file name"   : removes the file from local repo. needs to be commited and pushed for changes to apply 
4) git diff     :   will show the changes made in all files
5) git diff "file name"     : will show changes only in the files
6) git diff --name-only     : will show only files names that have been changed (not the content)

7)