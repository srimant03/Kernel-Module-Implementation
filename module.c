#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/sched/signal.h>
#include <linux/cred.h>

char *process_name;
module_param(process_name,charp,0000);

//print task struct of process_name
void print_task_struct(struct task_struct *task, char *process_name){
    for_each_process(task){
        if (process_name[0]==task->comm[0] && process_name[1]==task->comm[1] && process_name[2]==task->comm[2] && process_name[3]==task->comm[3]){
            printk("Process name: %s",task->comm);
            printk("Process ID: %d",task->pid);
            printk("Process UID: %d",task->cred->uid.val);
            printk("Process GID: %d",pid_vnr(task_pgrp(task)));
            printk("Process Command Path: %s",task->comm);
        }
    }
}

int init_module(void){
    struct task_struct *task;
    print_task_struct(task,process_name);
    return 0;
}

//exit function
void cleanup_module(void){
    printk("Exiting module");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Srimant Mohanty");
MODULE_DESCRIPTION("Process Task Struct");











