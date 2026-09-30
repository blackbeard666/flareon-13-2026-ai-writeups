#!/bin/bash
mkdir -p ~/neon; cd ~/neon; rm -f core.*
cp /mnt/c/Users/cavila/Desktop/ctf/flareon13-2026/9-neonoutrun-attempt-2/neon_outrun ./no; chmod +x no
echo 0 | sudo -n tee /proc/sys/kernel/yama/ptrace_scope >/dev/null 2>&1
setsid nohup ./no >no.log 2>&1 < /dev/null &
sleep ${1:-12}
P=$(pgrep -x no | head -1); echo pid=$P
gcore -o ~/neon/core $P >/dev/null 2>&1
pkill -x no
ls -la ~/neon/
