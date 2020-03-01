import subprocess
import sys
import json

def install(package):
    try:
        install_command = [sys.executable, "-m", "pip", "install", package, "-q", "--user"]
        #call the command
        process = subprocess.check_call(install_command)
        
        #return 1 on successful installation of package
        return 1
    except:

        #return 0 on unsuccessful installation of package
        return 0

def installPackages():
    with open("./dependencies.json", "r") as input_file:
        dependencies = json.load(input_file)["Dependencies"]

    failed_packages = []

    #attempt to install every package
    for package in dependencies:
        if(install(package) == 0):
            failed_packages.append(package)

    #print result
    printStatus(failed_packages, dependencies)

def printStatus(failed_packages = [], dependencies = []):
    status = "Success"

    #if there are failed packages, log them
    if(len(failed_packages) > 0):
        status = "{} of {} given packages failed to download:-"
        print(status.format(len(failed_packages), len(dependencies)))

        for ind in range(0, len(failed_packages)):
            print(ind+1, failed_packages[ind])

    #else print Success
    else:
        print(status)

installPackages()