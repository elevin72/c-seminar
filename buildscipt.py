#!/bin/python3

# Usage: buildscipt.py [director(ies) containing c files]
# if no arguments given, then defaults to cwd
# will recursively search all directories given
# assumes each directory that contains *.c is a seperate project and gets it's own /docs and executable

import sys
import os
import subprocess

CALLING_DIR = os.getcwd()

def walk_down_dir_structure(dir=CALLING_DIR):
    if not os.path.isdir(dir):
        print(dir + " was not found")
        return
    for file_or_dir in os.listdir(dir):
        rel_path = dir + "/" + file_or_dir
        if os.path.isdir(rel_path):
            walk_down_dir_structure(rel_path)
        elif os.path.isfile(rel_path) and rel_path.endswith(".c"):
            print("building files in " + str(dir))
            build_in(dir)

def edit_dconfig(dir):
    dconfig = open("dconfig", "r")
    list_of_lines = dconfig.readlines()
    for i,line in enumerate(list_of_lines):
        if line.startswith("OUTPUT_DIRECTORY       ="):
            list_of_lines[i] = "OUTPUT_DIRECTORY       = " + dir + "/docs\n"
        elif line.startswith("INPUT                  ="):
            list_of_lines[i] = "INPUT                  = " + dir + "\n" 
    dconfig = open("dconfig", "w")
    dconfig.writelines(list_of_lines)
    dconfig.close()

def build_in(dir):
    edit_dconfig(dir)
    if not os.path.isdir(dir + "/docs"):
        os.mkdir(dir + "/docs")
    print("doxygening")
    doxygen_output = subprocess.run(['doxygen', 'dconfig'], capture_output=True)
    if doxygen_output.returncode == 0:
        print("doxygenation succesful")
    else:
        print("doxygenation unsuccesful")
        print(doxygen_output.stdout.decode())
    print("compiling")
    compile_output = subprocess.run('gcc -Wall -Werror -pedantic -std=c11 -o'+ dir + '/a.out ' + dir + '/*.c', shell=True)
    if compile_output.returncode == 0:
        print("compilation succesful")
    else:
        print("compilation unsuccesful")
    print("")
        
def walk_up_to_root():
    cwd = os.getcwd()
    file_list = os.listdir(cwd)
    while ".git" not in file_list and "buildscript.py" not in file_list:
        os.chdir("..")
        cwd = os.getcwd()
        if cwd == "/":
            print("call script from somewhere inside project")
            exit()
        file_list = os.listdir(cwd)


# main code
walk_up_to_root()
if sys.argv[1:] == []:
    walk_down_dir_structure()
else:
    for dir in sys.argv[1:]:
        walk_down_dir_structure(dir)

