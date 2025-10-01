#!/bin/bash
# BeagleBone Black LED setup for real PWMs

APP=./bbb_debug
PERIOD_NS=1000000   # 1 kHz

setup_pwm() {
    CHIP=$1
    CHANNEL=$2
    SYSFS=/sys/class/pwm/pwmchip${CHIP}/pwm${CHANNEL}

    if [ ! -d "$SYSFS" ]; then
        echo $CHANNEL | sudo tee /sys/class/pwm/pwmchip${CHIP}/export
    fi

    echo $PERIOD_NS | sudo tee ${SYSFS}/period
    echo 0 | sudo tee ${SYSFS}/duty_cycle
    echo 1 | sudo tee ${SYSFS}/enable
}

cleanup() {
    echo "Cleaning up..."
    for CHIP in 0 5; do
        for CHANNEL in 0 1; do
            SYSFS=/sys/class/pwm/pwmchip${CHIP}/pwm${CHANNEL}
            if [ -d "$SYSFS" ]; then
                echo 0 | sudo tee ${SYSFS}/enable
                echo $CHANNEL | sudo tee /sys/class/pwm/pwmchip${CHIP}/unexport
            fi
        done
    done
}
trap cleanup EXIT

echo "Configuring pins..."
sudo config-pin P9_42 pwm
sudo config-pin P9_14 pwm
sudo config-pin P9_16 pwm

echo "Exporting and enabling PWMs..."
setup_pwm 0 0   # P9.42 - LED1
setup_pwm 5 0   # P9.14 - LED2
setup_pwm 5 1   # P9.16 - LED3

echo "Starting program..."
$APP

