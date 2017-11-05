#!/bin/bash

COUNT=$(ps -ef |grep watch_ip |grep -v "grep" |wc -l)
echo $COUNT
if [ $COUNT -eq 0 ]; then
        cd /home/zsx/ChengHao/Code
		python watch_ip.py
else
        echo is RUN
fi