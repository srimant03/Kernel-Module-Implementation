# Kernel-Module-Implementation
Writing a your own small kernel module. Implementing a kernel system call as a module

## Writing the module

The task of the system call
is to read the entries of the process task_struct corresponding to any
given process name (supplied as input via command line argument) and print the
values of the following fields: process id(PID), user id(UID), process group id (PGID) and command
path.

`init_module()` & `cleanup_module()` are used to tell the kernel which functions to call while loading and unloading the modules respectively.

`printk()` is used to print he output generated to the kernel logs  

## Loading the module

Run `make` using the makefile to successfully compile the module. This generates the corresponding `.ko` file; ready to loaded into the kernel.

Run the following commands to run the module, check the output and later remove the module

```
insmod module.ko process_name="[process_name]"

dmesg

rmmod module

```

## Resources used

https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234 
