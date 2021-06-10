
//linux常用命令

/*
    linux常用工具命令
        1.监控
            free：显示当前系统未使用的和已使用的内存数目，还可以显示被内核使用的的内存缓
                冲去，不带参数默认将会以kb单位展示
            ping：ping一个ip，测试是否可以连接
            vmstat：虚拟内存统计
            iostat：用于报告中央处理器（CPU）统计信息和整个系统、适配器、tty设备、磁盘和
                CD-ROM的输入和输出统计信息。
            dstat：显示了cpu的使用情况，磁盘io情况，网络发包情况和换页情况，输出是彩色的，
                可读性较强，相对于vmstat和iostat的输入更加详细且较为直观。
            pidstat：主要用于监控全部或指定进程占用系统资源的情况，如CPU内存、设备IO、任务
                切换、线程等。
            top：命令的汇总区域显示了五个方面的系统性能信息：负载、进程状态、CPU使用率、
                内存使用、交换分区。
            iotop：linux进程实时监控工具，界面风格类似top命令
            htop：是linux系统中的一个互动的进程查看器，一个文本模式的应用程序（在控制台或者
                终端中），需要ncurses。
            mpstat：报告CPU统计信息。
            netstat：用于显示与IP、TCP、UDP和CMP协议相关的统计数据，一般用于检验本机各端口
                的网络连接情况。
            ps：显示当前进程的状态
            strace：跟踪程序执行过程中产生的系统调用及接收到的信号，帮助分析程序或命令执行中
                遇到的异常情况。
            ltrace：跟踪进程调用库函数的情况
            uptime：能够打印系统总共运行了多长时间和系统的平均负载，uptime命令最后输出的三个
                数字的含义分别是1分钟，5分钟，15分钟内系统的平均负荷。
            losf：是一个列出当前系统打开文件的工具  
            perf：是linux kernel自带的系统性能优化工具。优势在于与linux kernel的紧密结合，
                它可以最先应用到加入kernel的new feature，用于查看热点函数，查看cashe miss的
                比率，从而帮助开发者来优化程序性能。
            tcpdump：是一款灵活、功能强大的抓包工具，能有效地帮助排查网络故障问题。
            sar：是目前linux上最为全面的系统性能分析工具之一，可以从多方面对系统的活动进行报告，
                包括：文件的读写情况、系统调用的使用情况、磁盘I/O、CPU效率、内存使用状况、进程
                活动及IPC相关的活动等。
            blktrace：

        2.测试
            sysbench：是一个模块化、跨平台、多线程基准测试工具，可用于以下性能测试：
                1.CPU性能
                2.磁盘IO性能
                3.调度程序性能
                4.内存分配及传输速度
                5.POSIX线程性能
                6.数据库性能（OLTP基准测试）

            linux CPU使用率主要从以下几个维度进行统计：
                %usr：普攻进程在用户模式下执行的时间；
                %sys：进程在内核模式下的执行时间；
                %nice：被提高优先级的进程在用户模式下的执行时间；
                %idle：空闲时间；
                %iowait：等待I/O完成的时间；
                %irp：处理硬中断请求花费的时间；
                %soft：处理软中断请求花费的时间；
                %steal：是衡量虚拟机CPU的指标，是指分配给本虚拟机的时间片被同一宿主机别的虚拟机
                    占用，一般%steal值较高时，说明宿主机的资源使用已达到瓶颈；
                一般情况下，CPU大部分的时间片都是消耗在用户态和内核态上。
                    sys和usr间的比例是相互影响的，%sys比例高意味着被测服务频繁的进行用户态和系统
                    态之间的切换，会带来一定的CPU开销，这样分配处理业务的时间片就会较少，造成系统
                    性能的下降。对于IO密集型系统，对磁盘的读写需要占用大量的CPU，会导致%iowait的
                    值一定比例的升高，所以当出现%iowait较高时，需排查是否存在大量的不合理日志操作，
                    或者频繁的数据载入等情况。

        3.优化
            Linux performance tuning tools：linux性能调优工具

    基础命令和工具
        1.grep搜索字符
            grep命令用于在文件中执行关键词搜索，并显示匹配的效果。部分常用选项
            -c：仅显示找到的行数
            -i：忽略大小写
            -n：显示行号
            -v：反向选择 - 仅列出没有关键词的行。v 是 invert 的缩写。
            -r：递归搜索文件目录
            -C n：打印匹配行的前后n行

            在指定文件查找，查找login关键字
            grep login lmUser.cpp

            多个文件中搜索
            grep login lmUser.cpp MsgConn.cpp

            在多个文件搜索的时候，可以使用通配符。在以cpp结尾的文件中，搜索包含login的行
            grep login *.cpp

            递归搜索目录下所有文件，搜索msg_server目录下所有文件，打印出包含login的行。
            grep login -r msg_server/

            反向查找，查找文件中，不包含ClmUser的行
            grep -v ClmUser lmUser.cpp

            找出文件中包含login的行，并打印出行号
            grep -n login lmUser.cpp

            找出文件中包含login的行，打印出行号，并显示前后3行
            grep -C 3 -n login lmUser.cpp

            找出文件中包含login的行，打印出行号，并显示前后3行，并忽略大小写
            grep -C 3 -i -n login lmUser.cpp

        2.find查找文件
            通过文件名查找文件的所在位置，文件名查找支持模糊匹配
            find [指定查找目录] [查找规则] [查找完后执行的action]
            常用操作：
            find . -name timer.lua
            find . -iname TIMER.LUA 忽略文件名称大小写
            find /etc -maxdepth 1 -name timer.lua
            find /mnt -size 20K 查找/mnt文件大小近似20K的文件
            find /mnt -size +20K 查找/mnt文件大小大于20K的文件
            find /mnt -size -20K 查找/mnt文件大小小于20K的文件
            find /etc -maxdepth 2 -mindepth 2 -name *.conf 查找/etc/下名称中带有*.conf的文件，且只查找第二层
            find /mnt -type d 按type查找/mnt中目录
            find /mnt -type f 按type查找/mnt中文件
            find /mnt -cmin 10 查找/mnt中十分钟左右修改的
            find /mnt -cmin +10 查找/mnt中十分钟以上修改的
            find /mnt -cmin -10 查找/mnt中十分钟以内修改的
            find /mnt -ctime 10 查找/mnt中十天左右修改的
            find /mnt -ctime +10 查找/mnt中十天以上修改的
            find /mnt -ctime -10 查找/mnt中十天以内修改的

        3.ls显示文件
            -t 可以查看最新修改的时间
            -l 每行显示一个条目
            -h 可以结合显示文件的GB、MB等(human)
            -R 递归显示
            -n 显示组id和gid

            ls -lt 按最新修改的时间排序，新修改的在前面显示
            ls -ltR 按最新修改的时间排序，新修改的在前面显示，并显示子目录的文件信息
            ls -lh 以单位显示文件大小
        
        4.wc命令
            wc命令用于计算字数。利用wc指令我们可以计算文件的Byte数、字数、或是列数，若不指定文件名称、或是所给与的
            文件名为“-”，则wc指令会从标准输入设备读取数据。

            语法：wc [-clw][--help][--version][文件...]

            参数：
                -c或--bytes或--chars 只显示Bytes数
                -l或--lines 只显示行数
                -w或--words 只显示字数
                --help 在线帮助
                --version 显示版本信息

            练习：
                wc testflie         # testfile文件的统计信息
                7 92 607 testfile   # testfile文件的行数7、单词数92、字节数607

                wc -l testfile      # testfile文件的行数

        5.uptime机器启动时间+负载
            查看机器的启动时间、登录用户、平均负载等情况，通常用于在线上应急或者技术攻关中，确定操作系统的重启时间。

            uptime：13:01:52 up 46 days, 22:03, 4 users, load average：0.13， 0.08， 0.05
            从上面的输出可以看到如下信息：
                1.当前时间：13:01:52
                2.系统已经运行的时间：43天22小时3分钟
                3.前在线用户：4个用户，是总连接数量，不是不同用户数量（开一个终端连接就算一个用户）
                4.系统平均负载：0.13，0.08，0.05，为最近1分钟、5分钟、15分钟的系统负载情况

            系统的平均负载是指在特定的时间间隔内队列中运行的平均进程数。如果一个进程满足以下条件，它就会位于运行
            队列中。
                1.它没有在等待I/O操作的结果
                2.它没有主动进入等待状态（也就是没有调用‘wait’相关的系统API）
                3.没有被停止（例如：等待终止）

            如果每个CPU内核的当前活动进程数不大于3的话，那么系统的性能还算可以支持。
            如果每个CPU内核的任务数大于5，那么这台机器的性能有严重问题。
            如果你的linux主机是1个双核CPU的话，当load Average为6的时候说明机器已经被充分使用了。

            负载说明（现针对单核情况，不是单核时则乘以核数）：
            load < 1：没有等待
            load == 1：系统已无额外的资源跑更多的进程了
            load > 1：进程都堵着等待资源

            注意：
                load < 0.7：系统很闲，要考虑多部署一些服务
                0.7 < load < 1：系统状态不错
                load == 1：系统马上要处理不过来了，赶紧找一下原因
                load > 5：系统已经非常繁忙了

                不同load值说明的问题
                1）1分钟load > 5，5分钟load < 3，15分钟laod < 1
                    短期内繁忙，中长期空闲，初步判断是一个抖动或者拥塞前兆

                2）1分钟load > 5，5分钟load > 3，15分钟load < 1
                    短中内繁忙，中期内紧张，很可能是一个拥塞的开始

                3）1分钟load > 5，5分钟load > 5，15分钟load > 5
                    短中长期都繁忙，系统正在拥塞

                4）1分钟load < 1，5分钟load > 3，15分钟load > 5
                    短期内空闲，中长期繁忙，不用紧张，系统拥塞正在好转

            补充：
                查看CPU信息：cat /proc/cpuinfo
                直接获取CPU核数：grep 'model name' /proc/cpuinfo | wc -l
*/