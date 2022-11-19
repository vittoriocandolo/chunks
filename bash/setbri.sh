#!/bin/bash

# max value is 255
amd=$(($1<256 ? $1 : 255))

# max value is 100
nvidia=$((($1*100)/255))

echo $amd > /sys/class/backlight/amdgpu_bl0/brightness || echo $amd > /sys/class/backlight/amdgpu_bl1/brightness || true

echo $nvidia > /sys/class/backlight/nvidia_0/brightness
