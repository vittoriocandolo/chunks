#!/bin/bash

echo "$1" > /sys/class/backlight/amdgpu_bl0/brightness || echo "$1" > /sys/class/backlight/amdgpu_bl1/brightness || true
echo "$1" > /sys/class/backlight/nvidia_0/brightness
