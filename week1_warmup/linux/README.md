## Getting Familiar With Linux

The goal of this part of the assignment is to get familiar with common (Linux) commands, <code>/proc</code> filesystem in Linux and process behaviour information, monitoring and control.

In Ubuntu, login and launch the command prompt (aka Terminal). **CTRL + ALT + T** is the keyboard
shortcut, or you can search for **Terminal** by clicking on the Show Applications button in the bottom-left corner.

### Useful References

- [Unix Tutorial for the Beginner](http://www.ee.surrey.ac.uk/Teaching/Unix/) ( Go through Tutorial 1 and Tutorial 2. Others are optional)
- [Basic Linux Commands](https://maker.pro/linux/tutorial/basic-linux-commands-for-beginners) (Optional)


### Basic commands
Following are some basic Linux commands. To know more about them use: <code> man \<command\> </code>. Start with <code> man man</code>.

 -  Make a new directory: <code>mkdir \<dirname\></code>
 -  Remove directory if it is empty else throw an error: <code>rmdir \<dirname\></code>
 -  Copy file: <code>cp \<source\> \<destination\></code>
 -  Create a new file: <code>touch \<filename\></code>
 -  Delete a single file: <code>rm \<filename\></code>
 -  Delete a whole folder: <code>rm -r \<foldername\></code>
 -  Change working directory: <code>cd \<path\></code>
 -  Move to parent directory: <code>cd ..</code>
    and Move to previous directory: <code>cd -</code>
 -  List contents of a folder: <code>ls</code>
 -  Print current directory: <code>pwd</code>

### Some More Commands
 -  <code>top</code> : top provides a continuous collective view of the system and operating system state.

 -  <code>ps</code> : The ps command is used to view the processes running on a system. It provides a snapshot of the processes along with detailed process information like process-id, cpu usage, memory usage etc.

 -  <code>lsof</code> : lsof is used to list open files. It lists details of the file itself and details of users, processes which are using the files..
 
 -  Understand the <code>/proc</code> filesystem in Linux. The <code>/proc</code> file system is a mechanism provided by Linux for the kernel to report information about the system and processes to users. The <code>/proc</code> file system is nicely documented in the proc man page. You can access this document by running the command <code>man proc</code> on a Linux system. Understand the system-wide <code>proc</code> files such as <code>meminfo</code> and <code>cpuinfo</code>, and per-process files such as <code>status</code> and <code>stat</code>. System related <code>proc</code> files are available in the directory <code>/proc/</code>, and process related <code>proc</code> files are available at <code>/proc/\<process-id\>/</code>

### Exercises

1. Find the variant of the <code>ls</code> command (i.e. argument(s) to be used) to list contents of a folder including its hidden files, the variant of <code>cp</code> to copy folder and the command to rename a file.

A) The variant of ls to list all the contents along with the hidden files (files started with .) is the "ls -a". 
B) The variant of cp to copy entire folders is the cp -R [source-path] [destination-path], where the R stands for recursively. So, in short it means recursively copy everything from the source path and paste it in the destination path. 
C) renaming a file can be done with the help of the move command (mv). we just move the file to the same location with a different name. 
mv -sourcefile_name- -destinationfile_name-

2. In this question, we will understand the hardware configuration of your working machine using the <code>/proc</code> filesystem.

    - Run command <code>more /proc/cpuinfo</code> and explain the following terms: <code>processor</code> and <code>cores</code>. Use the command <code>lscpu</code> to verify your definitions.
    - How many CPU sockets, cores, and processors does your machine have?
    - What is the frequency of each processor?
    - How much memory does your machine have?
    - How much of it is free and available? What is the difference between them?
    - What is the total number of user-level processes in the system?
    - What is the total number of number of forks since the boot in the system ?
    - How many context switches has the system performed since bootup?

First i will paste the results i got from lscpu and /proc/cpuinfo here
lscpu: 

Architecture:            x86_64
  CPU op-mode(s):        32-bit, 64-bit
  Address sizes:         43 bits physical, 48 bits virtual
  Byte Order:            Little Endian
CPU(s):                  8
  On-line CPU(s) list:   0-7
Vendor ID:               AuthenticAMD
  Model name:            AMD Ryzen 5 3550H with Radeon Vega Mobile Gfx
    CPU family:          23
    Model:               24
    Thread(s) per core:  2
    Core(s) per socket:  4
    Socket(s):           1
    Stepping:            1
    Frequency boost:     enabled
    CPU max MHz:         2100.0000
    CPU min MHz:         1400.0000
    BogoMIPS:            4192.15
    Flags:               fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mc
                         a cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall n
                         x mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc rep_go
                         od nopl nonstop_tsc cpuid extd_apicid aperfmperf rapl p
                         ni pclmulqdq monitor ssse3 fma cx16 sse4_1 sse4_2 movbe
                          popcnt aes xsave avx f16c rdrand lahf_lm cmp_legacy sv
                         m extapic cr8_legacy abm sse4a misalignsse 3dnowprefetc
                         h osvw skinit wdt tce topoext perfctr_core perfctr_nb b
                         pext perfctr_llc mwaitx cpb hw_pstate ssbd ibpb vmmcall
                          fsgsbase bmi1 avx2 smep bmi2 rdseed adx smap clflushop
                         t sha_ni xsaveopt xsavec xgetbv1 xsaves clzero irperf x
                         saveerptr arat npt lbrv svm_lock nrip_save tsc_scale vm
                         cb_clean flushbyasid decodeassists pausefilter pfthresh
                         old avic v_vmsave_vmload vgif overflow_recov succor smc
                         a sme sev sev_es
Virtualization features: 
  Virtualization:        AMD-V
Caches (sum of all):     
  L1d:                   128 KiB (4 instances)
  L1i:                   256 KiB (4 instances)
  L2:                    2 MiB (4 instances)
  L3:                    4 MiB (1 instance)
NUMA:                    
  NUMA node(s):          1
  NUMA node0 CPU(s):     0-7
Vulnerabilities:         
  Itlb multihit:         Not affected
  L1tf:                  Not affected
  Mds:                   Not affected
  Meltdown:              Not affected
  Mmio stale data:       Not affected
  Spec store bypass:     Mitigation; Speculative Store Bypass disabled via prctl
                          and seccomp
  Spectre v1:            Mitigation; usercopy/swapgs barriers and __user pointer
                          sanitization
  Spectre v2:            Mitigation; Retpolines, IBPB conditional, STIBP disable
                         d, RSB filling
  Srbds:                 Not affected
  Tsx async abort:       Not affected

/proc/cpuinfo: 
processor	: 0
vendor_id	: AuthenticAMD
cpu family	: 23
model		: 24
model name	: AMD Ryzen 5 3550H with Radeon Vega Mobile Gfx
stepping	: 1
microcode	: 0x8108102
cpu MHz		: 1400.000
cache size	: 512 KB
physical id	: 0
siblings	: 8
core id		: 0
cpu cores	: 4
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 13
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov 
pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp
 lm constant_tsc rep_good nopl nonstop_tsc cpuid extd_apicid aperfmperf rapl pni
 pclmulqdq monitor ssse3 fma cx16 sse4_1 sse4_2 movbe popcnt aes xsave avx f16c 
rdrand lahf_lm cmp_legacy svm extapic cr8_legacy abm sse4a misalignsse 3dnowpref

A) in proc/cpuinfo the processor number relates the processor which is being run at the moment, the virtual or logical number given to that processor(if you have multiple, it will display all of them), in my case it is 0 (because i have only 1 processor). Cores refers to the amount of cores or processing units present within the processor. This means that the processor can perform 4 actions in each of the cores simultaneous. 

B) My pc has 1 socket for the CPU, which contains 4 cores and each having 2 threads and hence 8 CPU units with a logical ID of 0 through 7.

C) The frequency of my cpu ranges from 1400-2100 based on the requirements. 

D) Address sizes:         43 bits physical, 48 bits virtual
This means that the cpu can hold only 43 bits of memory at a time. whereas the virtual means the amount of virtual address spaces which any process may contain. therefore, the virtual address space is just pointers to actual memory which can be used with demand paging. Hence, the virtual address space is organised by the OS to know which virtual address is refered to using a table which stores this. 

E) when i run free -h the result is: 
               total        used        free      shared  buff/cache   available
Mem:           7.6Gi       3.3Gi       2.1Gi       203Mi       2.1Gi       3.8Gi
Swap:          2.0Gi          0B       2.0Gi

This means that there is 2.1gb of memory which is not used for anything. This means that when more programs come they can be used, but for the time being it is completely empty and not doing anything. Whereas the available memory is the memory which can be used by a new program without incurring much time to switch out the memory which is already in use. 

F) ps command: 
   PID TTY          TIME CMD
   3805 pts/0    00:00:00 bash
   8323 pts/0    00:00:00 ps
This means that there are 2 processes which are running at the moment which is the bash and the ps command which had been made to check the processes. 

G) vmstat -f 
         8999 forks
it says i have 8999 forks since booting the device 

H) vmstat 1
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0      0 1672964 120460 2133088    0    0    34    23  213  393  3  1 97  0  0
 0  0      0 1672768 120476 2133088    0    0     0   148  484  527  0  0 99  0  0
 0  0      0 1673972 120476 2133984    0    0     0     0 1058 1364  1  0 99  0  0
 1  0      0 1674028 120484 2133984    0    0     0   164  455  460  0  0 100  0  0
 0  0      0 1674532 120484 2133984    0    0     0     0  418  406  0  0 100  0  0
 0  0      0 1678312 120492 2129864    0    0     0    96  476  516  1  0 99  0  0
 0  0      0 1678060 120492 2130028    0    0     0     0  617  700  0  0 99  0  0
 0  0      0 1678060 120500 2130028    0    0     0   148  755  897  0  1 99  0  0
 0  0      0 1685312 120500 2126152    0    0     0  1588  665  683  0  0 100  0  0
 0  0      0 1686244 120500 2125928    0    0     0     0 2689 4681  1  1 99  0  0
 0  0      0 1683724 120500 2130280    0    0     0     0 3488 5045  7  1 92  0  0

here under the cs header which stands for context switches it says how many context switches are occurring each second since the command is run. 

3. In this question, we will understand how to monitor the status of a running process using the <code>top</code> command. Compile the program [cpu.c](cpu.c) given to you and execute it in the bash or any other shell of your choice as follows.
    ```console
    gcc --version
    # If gcc is not installed then run :- sudo apt-get install gcc
    gcc cpu.c -o cpu
    ./cpu
    ```
    This program runs in an infinite loop without terminating. Now open another terminal, run the <code>top</code> command and answer the following questions about the cpu process.

    - What is the PID of the process running the cpu command?
    - How much CPU and memory does this process consume?
    - What is the current state of the process? For example, is it running or in a blocked state or a zombie state?


    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
  11128 george    20   0    2640    940    852 R 100.0   0.0   0:48.42 cpu      
   1354 george    20   0 5951708 330248 138388 R   7.0   4.2   5:09.04 gnome-s+ 
   3787 george    20   0  577100  65432  42656 S   3.0   0.8   0:45.37 gnome-t+ 
  10682 root      20   0       0      0      0 I   0.7   0.0   0:00.58 kworker+ 
   6899 george    20   0   40.5g 131296  94896 S   0.3   1.7   0:01.29 chrome   
  10863 root      20   0       0      0      0 I   0.3   0.0   0:00.48 kworker+ 
  11025 george    20   0   40.5g 162064 105452 S   0.3   2.0   0:07.84 chrome   
  11154 george    20   0   21976   4260   3300 R   0.3   0.1   0:00.15 top      
      1 root      20   0  166668  11804   8112 S   0.0   0.1   0:01.56 systemd  
      2 root      20   0       0      0      0 S   0.0   0.0   0:00.01 kthreadd 
      3 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 rcu_gp   
      4 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 rcu_par+ 
      5 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 netns    
      7 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 kworker+ 
     10 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 mm_perc+ 
     11 root      20   0       0      0      0 S   0.0   0.0   0:00.00 rcu_tas+ 
     12 root      20   0       0      0      0 S   0.0   0.0   0:00.00 rcu_tas+ 

A) The pid of the process running the cpu command is 11128 which can be found in the first row of the table. 
B) it uses 100% of the cpu and 0% of the memory which makes sense because it doesnt store anything apart from the commands themselves which would be optimised to take the least memory over multiple repetitions and probably stored in the ccache and hence increasing cache hits. The VIRT column stands for the virtual memory used by the process along with RES which is the actual physical storage used by the same process. 
C) The current state is given by the column S under which it is R which stands for running. 