EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Molex_Dual_RJ45
LIBS:Temp_Humid-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "28 oct 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 6500 3800
NoConn ~ 6500 3900
NoConn ~ 6500 4000
NoConn ~ 6500 4250
NoConn ~ 6500 4350
NoConn ~ 6500 4450
NoConn ~ 6500 4550
NoConn ~ 6500 4650
NoConn ~ 6500 4750
NoConn ~ 6500 4850
NoConn ~ 6500 5000
NoConn ~ 6500 5100
NoConn ~ 6500 5200
NoConn ~ 6500 5300
NoConn ~ 6500 5400
NoConn ~ 4550 5450
NoConn ~ 4550 5350
NoConn ~ 4550 4750
NoConn ~ 4550 4650
NoConn ~ 4550 4450
NoConn ~ 4550 4350
NoConn ~ 4550 4250
NoConn ~ 4550 4000
NoConn ~ 4550 3900
NoConn ~ 4550 3800
NoConn ~ 4550 3700
NoConn ~ 4550 3150
NoConn ~ 4550 3050
NoConn ~ 4550 2950
NoConn ~ 4550 2850
NoConn ~ 4550 2750
NoConn ~ 4550 2650
NoConn ~ 4550 2550
NoConn ~ 6500 3700
NoConn ~ 6500 3600
NoConn ~ 6500 3500
NoConn ~ 6500 3150
NoConn ~ 6500 2550
NoConn ~ 6500 2450
NoConn ~ 5950 1950
$Comp
L R R3
U 1 1 52152F84
P 3700 2100
F 0 "R3" V 3780 2100 50  0000 C CNN
F 1 "470k" V 3700 2100 50  0000 C CNN
F 2 "" H 3700 2100 60  0001 C CNN
F 3 "" H 3700 2100 60  0001 C CNN
	1    3700 2100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 00000000
P 3450 1700
F 0 "#PWR01" H 3450 1790 20  0001 C CNN
F 1 "+5V" H 3450 1790 30  0000 C CNN
F 2 "" H 3450 1700 60  0001 C CNN
F 3 "" H 3450 1700 60  0001 C CNN
	1    3450 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 52152F91
P 2850 2300
F 0 "#PWR02" H 2850 2300 30  0001 C CNN
F 1 "GND" H 2850 2230 30  0001 C CNN
F 2 "" H 2850 2300 60  0001 C CNN
F 3 "" H 2850 2300 60  0001 C CNN
	1    2850 2300
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 52152F90
P 3500 4550
F 0 "R2" V 3580 4550 50  0000 C CNN
F 1 "300" V 3500 4550 50  0000 C CNN
F 2 "" H 3500 4550 60  0001 C CNN
F 3 "" H 3500 4550 60  0001 C CNN
	1    3500 4550
	0    -1   -1   0   
$EndComp
$Comp
L DS1820 U1
U 1 1 52152F8F
P 3100 1350
F 0 "U1" H 3100 650 60  0000 C CNN
F 1 "DS1820" H 3100 1350 60  0000 C CNN
F 2 "" H 3100 1350 60  0001 C CNN
F 3 "" H 3100 1350 60  0001 C CNN
	1    3100 1350
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 52152F8E
P 4100 4550
F 0 "D1" H 4100 4650 50  0000 C CNN
F 1 "LED" H 4100 4450 50  0000 C CNN
F 2 "" H 4100 4550 60  0001 C CNN
F 3 "" H 4100 4550 60  0001 C CNN
	1    4100 4550
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR03
U 1 1 52152F8D
P 2600 3650
F 0 "#PWR03" H 2600 3740 20  0001 C CNN
F 1 "+5V" H 2600 3740 30  0000 C CNN
F 2 "" H 2600 3650 60  0001 C CNN
F 3 "" H 2600 3650 60  0001 C CNN
	1    2600 3650
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 52152F8C
P 2600 4200
F 0 "R1" V 2680 4200 50  0000 C CNN
F 1 "10k" V 2600 4200 50  0000 C CNN
F 2 "" H 2600 4200 60  0001 C CNN
F 3 "" H 2600 4200 60  0001 C CNN
	1    2600 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 52152F8B
P 3150 4350
F 0 "#PWR04" H 3150 4350 30  0001 C CNN
F 1 "GND" H 3150 4280 30  0001 C CNN
F 2 "" H 3150 4350 60  0001 C CNN
F 3 "" H 3150 4350 60  0001 C CNN
	1    3150 4350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 52152F8A
P 3600 4000
F 0 "#PWR05" H 3600 4090 20  0001 C CNN
F 1 "+5V" H 3600 4090 30  0000 C CNN
F 2 "" H 3600 4000 60  0001 C CNN
F 3 "" H 3600 4000 60  0001 C CNN
	1    3600 4000
	1    0    0    -1  
$EndComp
$Comp
L CONN_3X2 P1
U 1 1 52152F89
P 3200 3600
F 0 "P1" H 3200 3850 50  0000 C CNN
F 1 "CONN_3X2" V 3200 3650 40  0000 C CNN
F 2 "" H 3200 3600 60  0001 C CNN
F 3 "" H 3200 3600 60  0001 C CNN
	1    3200 3600
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 52152F87
P 3300 4900
F 0 "C1" H 3350 5000 50  0000 L CNN
F 1 "22pf" H 3350 4800 50  0000 L CNN
F 2 "" H 3300 4900 60  0001 C CNN
F 3 "" H 3300 4900 60  0001 C CNN
	1    3300 4900
	0    -1   -1   0   
$EndComp
$Comp
L C C2
U 1 1 52152F86
P 3300 5500
F 0 "C2" H 3350 5600 50  0000 L CNN
F 1 "22pf" H 3350 5400 50  0000 L CNN
F 2 "" H 3300 5500 60  0001 C CNN
F 3 "" H 3300 5500 60  0001 C CNN
	1    3300 5500
	0    -1   -1   0   
$EndComp
$Comp
L CRYSTAL X1
U 1 1 52152F85
P 3700 5200
F 0 "X1" H 3700 5350 60  0000 C CNN
F 1 "16MHz" H 3700 5050 60  0000 C CNN
F 2 "" H 3700 5200 60  0001 C CNN
F 3 "" H 3700 5200 60  0001 C CNN
	1    3700 5200
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR06
U 1 1 52152F74
P 5550 1750
F 0 "#PWR06" H 5550 1840 20  0001 C CNN
F 1 "+5V" H 5550 1840 30  0000 C CNN
F 2 "" H 5550 1750 60  0001 C CNN
F 3 "" H 5550 1750 60  0001 C CNN
	1    5550 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 52152F83
P 5800 6250
F 0 "#PWR07" H 5800 6250 30  0001 C CNN
F 1 "GND" H 5800 6180 30  0001 C CNN
F 2 "" H 5800 6250 60  0001 C CNN
F 3 "" H 5800 6250 60  0001 C CNN
	1    5800 6250
	1    0    0    -1  
$EndComp
NoConn ~ 8250 3550
$Comp
L MCP2551 U4
U 1 1 52152F80
P 7700 3300
F 0 "U4" H 7700 3150 60  0000 C CNN
F 1 "MCP2551" H 7700 2600 60  0000 C CNN
F 2 "" H 7700 3300 60  0001 C CNN
F 3 "" H 7700 3300 60  0001 C CNN
	1    7700 3300
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR08
U 1 1 52152F7D
P 6750 1150
F 0 "#PWR08" H 6750 1240 20  0001 C CNN
F 1 "+5V" H 6750 1240 30  0000 C CNN
F 2 "" H 6750 1150 60  0001 C CNN
F 3 "" H 6750 1150 60  0001 C CNN
	1    6750 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 52152F7C
P 7700 1900
F 0 "#PWR09" H 7700 1900 30  0001 C CNN
F 1 "GND" H 7700 1830 30  0001 C CNN
F 2 "" H 7700 1900 60  0001 C CNN
F 3 "" H 7700 1900 60  0001 C CNN
	1    7700 1900
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR010
U 1 1 52152F79
P 8900 1050
F 0 "#PWR010" H 8900 1000 20  0001 C CNN
F 1 "+12V" H 8900 1150 30  0000 C CNN
F 2 "" H 8900 1050 60  0001 C CNN
F 3 "" H 8900 1050 60  0001 C CNN
	1    8900 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 52152F78
P 8400 5550
F 0 "#PWR011" H 8400 5550 30  0001 C CNN
F 1 "GND" H 8400 5480 30  0001 C CNN
F 2 "" H 8400 5550 60  0001 C CNN
F 3 "" H 8400 5550 60  0001 C CNN
	1    8400 5550
	1    0    0    -1  
$EndComp
$Comp
L AT90CAN32 U2
U 1 1 52152F75
P 5450 2850
F 0 "U2" H 5600 3600 60  0000 C CNN
F 1 "AT90CAN32" H 5250 2500 60  0000 C CNN
F 2 "" H 5450 2850 60  0001 C CNN
F 3 "" H 5450 2850 60  0001 C CNN
	1    5450 2850
	-1   0    0    -1  
$EndComp
Text Label 3700 3100 0    60   ~ 0
PE1
Text Label 7150 3400 0    60   ~ 0
PE1
NoConn ~ 4550 3600
NoConn ~ 4550 3500
Text Label 7150 3300 0    60   ~ 0
PD1
Text Label 3250 4200 0    60   ~ 0
PD1
$Comp
L 7805 U3
U 1 1 52BC76CC
P 7700 1300
F 0 "U3" H 7850 1104 60  0000 C CNN
F 1 "7805" H 7700 1500 60  0000 C CNN
F 2 "" H 7700 1300 60  0000 C CNN
F 3 "" H 7700 1300 60  0000 C CNN
	1    7700 1300
	-1   0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 52BC77C3
P 7100 1500
F 0 "C3" H 7150 1600 50  0000 L CNN
F 1 "100nF" H 7150 1400 50  0000 L CNN
F 2 "" H 7100 1500 60  0000 C CNN
F 3 "" H 7100 1500 60  0000 C CNN
	1    7100 1500
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 52BC77D5
P 8100 1500
F 0 "C4" H 8150 1600 50  0000 L CNN
F 1 "0.33uF" H 8150 1400 50  0000 L CNN
F 2 "" H 8100 1500 60  0000 C CNN
F 3 "" H 8100 1500 60  0000 C CNN
	1    8100 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 52BCB805
P 2900 5750
F 0 "#PWR012" H 2900 5750 30  0001 C CNN
F 1 "GND" H 2900 5680 30  0001 C CNN
F 2 "" H 2900 5750 60  0000 C CNN
F 3 "" H 2900 5750 60  0000 C CNN
	1    2900 5750
	1    0    0    -1  
$EndComp
NoConn ~ 4550 4550
NoConn ~ 6500 2850
$Comp
L SW_PUSH SW1
U 1 1 54418504
P 4250 2050
F 0 "SW1" H 4400 2160 50  0000 C CNN
F 1 "SW_PUSH" H 4250 1970 50  0000 C CNN
F 2 "" H 4250 2050 60  0000 C CNN
F 3 "" H 4250 2050 60  0000 C CNN
	1    4250 2050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 54418511
P 4650 1800
F 0 "#PWR013" H 4650 1800 30  0001 C CNN
F 1 "GND" H 4650 1730 30  0001 C CNN
F 2 "" H 4650 1800 60  0001 C CNN
F 3 "" H 4650 1800 60  0001 C CNN
	1    4650 1800
	1    0    0    -1  
$EndComp
$Comp
L DS1820 U5
U 1 1 54456AA5
P 7250 5000
F 0 "U5" H 7250 4300 60  0000 C CNN
F 1 "HIH4000" H 7250 5000 60  0000 C CNN
F 2 "" H 7250 5000 60  0000 C CNN
F 3 "" H 7250 5000 60  0000 C CNN
	1    7250 5000
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR014
U 1 1 54456BCE
P 6800 4600
F 0 "#PWR014" H 6800 4690 20  0001 C CNN
F 1 "+5V" H 6800 4690 30  0000 C CNN
F 2 "" H 6800 4600 60  0001 C CNN
F 3 "" H 6800 4600 60  0001 C CNN
	1    6800 4600
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 544570D5
P 7500 2550
F 0 "K1" V 7450 2550 50  0000 C CNN
F 1 "CONN_3" V 7550 2550 40  0000 C CNN
F 2 "" H 7500 2550 60  0000 C CNN
F 3 "" H 7500 2550 60  0000 C CNN
	1    7500 2550
	1    0    0    -1  
$EndComp
NoConn ~ 4550 3300
$Comp
L C C5
U 1 1 544964C0
P 6050 1800
F 0 "C5" H 6100 1900 50  0000 L CNN
F 1 "100nF" H 6100 1700 50  0000 L CNN
F 2 "" H 6050 1800 60  0000 C CNN
F 3 "" H 6050 1800 60  0000 C CNN
	1    6050 1800
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 544964D7
P 6400 1950
F 0 "#PWR015" H 6400 1950 30  0001 C CNN
F 1 "GND" H 6400 1880 30  0001 C CNN
F 2 "" H 6400 1950 60  0001 C CNN
F 3 "" H 6400 1950 60  0001 C CNN
	1    6400 1950
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 544966BB
P 6300 6100
F 0 "C6" H 6350 6200 50  0000 L CNN
F 1 "100nF" H 6350 6000 50  0000 L CNN
F 2 "" H 6300 6100 60  0000 C CNN
F 3 "" H 6300 6100 60  0000 C CNN
	1    6300 6100
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR016
U 1 1 544966C1
P 6750 5850
F 0 "#PWR016" H 6750 5940 20  0001 C CNN
F 1 "+5V" H 6750 5940 30  0000 C CNN
F 2 "" H 6750 5850 60  0001 C CNN
F 3 "" H 6750 5850 60  0001 C CNN
	1    6750 5850
	1    0    0    -1  
$EndComp
$Comp
L RJ45_DUAL U6
U 1 1 544D40F4
P 9700 4050
F 0 "U6" H 9700 3500 60  0000 C CNN
F 1 "RJ45_DUAL" H 9700 4600 60  0000 C CNN
F 2 "~" H 9700 4050 60  0000 C CNN
F 3 "~" H 9700 4050 60  0000 C CNN
	1    9700 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 6100 6100 6100
Wire Wire Line
	5900 6100 5900 5950
Connection ~ 5800 6100
Connection ~ 3450 1850
Wire Wire Line
	3700 1850 3450 1850
Wire Wire Line
	2850 2300 2850 2050
Wire Wire Line
	2850 2050 3000 2050
Wire Wire Line
	3000 2050 3000 1900
Wire Wire Line
	3900 4550 3750 4550
Connection ~ 3050 4700
Wire Wire Line
	2600 4700 4250 4700
Wire Wire Line
	2600 4700 2600 4450
Wire Wire Line
	4550 5000 4250 5000
Wire Wire Line
	4250 5000 4250 4700
Wire Wire Line
	3050 4700 3050 3100
Wire Wire Line
	3050 3100 3150 3100
Wire Wire Line
	3150 3100 3150 3200
Wire Wire Line
	3250 3200 3250 3000
Wire Wire Line
	4250 3000 4250 3400
Wire Wire Line
	4250 3400 4550 3400
Wire Wire Line
	3350 3200 3350 3100
Connection ~ 3700 5500
Wire Wire Line
	3500 5500 4150 5500
Wire Wire Line
	4550 5150 4150 5150
Wire Wire Line
	4150 5150 4150 4900
Wire Wire Line
	5550 1800 5550 1750
Wire Wire Line
	5500 1950 5500 1800
Wire Wire Line
	6500 3050 6750 3050
Wire Wire Line
	6750 3050 6750 3850
Wire Wire Line
	6750 3850 7150 3850
Wire Wire Line
	6750 1150 6750 1250
Wire Wire Line
	6950 3650 7150 3650
Wire Wire Line
	7150 3550 6850 3550
Wire Wire Line
	6850 3550 6850 2950
Wire Wire Line
	6850 2950 6500 2950
Wire Wire Line
	5650 1800 5650 1950
Wire Wire Line
	5500 1800 5850 1800
Connection ~ 5550 1800
Wire Wire Line
	4550 5250 4150 5250
Wire Wire Line
	4150 5250 4150 5500
Wire Wire Line
	4150 4900 3500 4900
Connection ~ 3700 4900
Wire Wire Line
	3350 4000 3350 4100
Wire Wire Line
	3350 4100 3600 4100
Wire Wire Line
	3600 4100 3600 4000
Wire Wire Line
	3150 4000 3150 4350
Wire Wire Line
	2600 3650 2600 3950
Wire Wire Line
	3100 1900 3100 2750
Wire Wire Line
	3200 1900 3200 2050
Wire Wire Line
	3200 2050 3450 2050
Wire Wire Line
	3450 2050 3450 1700
Wire Wire Line
	3700 2350 3700 2450
Wire Wire Line
	5800 5950 5800 6250
Wire Wire Line
	5700 6100 5700 5950
Wire Wire Line
	3250 3000 4250 3000
Wire Wire Line
	6500 3400 7150 3400
Wire Wire Line
	3350 3100 3700 3100
Wire Wire Line
	6500 3300 7150 3300
Wire Wire Line
	6950 3650 6950 4150
Wire Wire Line
	7150 3750 6900 3750
Wire Wire Line
	6900 3750 6900 1250
Wire Wire Line
	3100 4900 2900 4900
Wire Wire Line
	3100 5500 2900 5500
Connection ~ 2900 5500
Wire Wire Line
	3250 4000 3250 4200
Connection ~ 8900 1250
Connection ~ 6900 1250
Wire Wire Line
	8100 1250 8900 1250
Wire Wire Line
	6750 1250 7300 1250
Connection ~ 7700 1700
Wire Wire Line
	7700 1550 7700 1900
Wire Wire Line
	7100 1700 8100 1700
Wire Wire Line
	7100 1300 7100 1250
Connection ~ 7100 1250
Wire Wire Line
	8100 1300 8100 1250
Wire Wire Line
	4350 4550 4300 4550
Wire Wire Line
	2900 4900 2900 5750
Wire Wire Line
	3250 4550 2900 4550
Wire Wire Line
	2900 4550 2900 3850
Wire Wire Line
	2900 3850 2600 3850
Connection ~ 2600 3850
Wire Wire Line
	6850 2750 6500 2750
Wire Wire Line
	6800 2650 6500 2650
Wire Wire Line
	4550 4150 3950 4150
Wire Wire Line
	3950 4150 3950 2750
Wire Wire Line
	3950 2750 3100 2750
Wire Wire Line
	4550 2450 4250 2450
Wire Wire Line
	4250 2450 4250 2350
Wire Wire Line
	4250 1750 4250 1550
Wire Wire Line
	4250 1550 4650 1550
Wire Wire Line
	4650 1550 4650 1800
Wire Wire Line
	3700 2450 3100 2450
Connection ~ 3100 2450
Wire Wire Line
	6500 4150 6850 4150
Wire Wire Line
	6850 4150 6850 4300
Wire Wire Line
	6850 4300 7250 4300
Wire Wire Line
	7250 4300 7250 4450
Wire Wire Line
	7150 4450 6950 4450
Wire Wire Line
	6950 4450 6950 4750
Wire Wire Line
	6950 4750 6800 4750
Wire Wire Line
	6800 4750 6800 4600
Wire Wire Line
	7150 2650 6850 2650
Wire Wire Line
	6850 2650 6850 2750
Wire Wire Line
	7150 2550 6800 2550
Wire Wire Line
	6800 2550 6800 2650
Wire Wire Line
	7150 2450 7150 1700
Connection ~ 7150 1700
Wire Wire Line
	4550 4850 4350 4850
Wire Wire Line
	4350 4850 4350 4550
Connection ~ 5650 1800
Wire Wire Line
	6250 1800 6400 1800
Wire Wire Line
	6400 1800 6400 1950
Connection ~ 5900 6100
Wire Wire Line
	6500 6100 6750 6100
Wire Wire Line
	6750 6100 6750 5850
Wire Wire Line
	8750 1250 8750 4800
Connection ~ 8750 1250
Wire Wire Line
	8900 1250 8900 1050
Wire Wire Line
	7350 4450 7350 4300
Wire Wire Line
	8400 3850 8250 3850
Wire Wire Line
	6950 4150 8400 4150
Connection ~ 8400 4150
Wire Wire Line
	7350 4300 9400 4300
Connection ~ 8400 4300
Wire Wire Line
	8750 4800 9400 4800
Wire Wire Line
	9400 4700 8750 4700
Connection ~ 8750 4700
Wire Wire Line
	9400 4600 8750 4600
Connection ~ 8750 4600
Wire Wire Line
	9400 4000 8750 4000
Connection ~ 8750 4000
Wire Wire Line
	9400 3900 8750 3900
Connection ~ 8750 3900
Wire Wire Line
	9400 3800 8750 3800
Connection ~ 8750 3800
Wire Wire Line
	8250 3750 8900 3750
Wire Wire Line
	8900 3700 8900 4500
Wire Wire Line
	8900 4500 9400 4500
Wire Wire Line
	9000 4400 9400 4400
Wire Wire Line
	9000 3600 9000 4400
Wire Wire Line
	9000 3650 8250 3650
Wire Wire Line
	9400 3700 8900 3700
Connection ~ 8900 3750
Wire Wire Line
	9400 3600 9000 3600
Connection ~ 9000 3650
Wire Wire Line
	8400 4200 9400 4200
Connection ~ 8400 4200
Wire Wire Line
	8400 4100 9400 4100
Connection ~ 8400 4100
Wire Wire Line
	8400 3500 9400 3500
Connection ~ 8400 3850
Wire Wire Line
	9400 3400 8400 3400
Connection ~ 8400 3500
Wire Wire Line
	8400 3300 9400 3300
Connection ~ 8400 3400
Connection ~ 8400 3300
Wire Wire Line
	8400 3300 8400 5550
NoConn ~ 9750 5100
NoConn ~ 9750 3000
$EndSCHEMATC
