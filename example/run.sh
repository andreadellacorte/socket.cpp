#!/bin/bash
cd /opt/zeuz/gameserver/ & ./server $1 > logs.txt & sleep 1 && tail -n 5000 -f ./logs.txt
sleep infinity
