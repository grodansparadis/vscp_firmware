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
LIBS:CAN_Power-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "17 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_1 P1
U 1 1 544C2F49
P 5000 3000
F 0 "P1" H 5080 3000 40  0000 L CNN
F 1 "CONN_1" H 5000 3055 30  0001 C CNN
F 2 "" H 5000 3000 60  0000 C CNN
F 3 "" H 5000 3000 60  0000 C CNN
	1    5000 3000
	0    1    1    0   
$EndComp
$Comp
L CONN_1 P7
U 1 1 544C2F60
P 5850 3000
F 0 "P7" H 5930 3000 40  0000 L CNN
F 1 "CONN_1" H 5850 3055 30  0001 C CNN
F 2 "" H 5850 3000 60  0000 C CNN
F 3 "" H 5850 3000 60  0000 C CNN
	1    5850 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 2850 5450 2850
Wire Wire Line
	5550 2500 5550 2850
Wire Wire Line
	5550 2850 5850 2850
$Comp
L CONN_1 P2
U 1 1 544C2F6A
P 5000 3500
F 0 "P2" H 5080 3500 40  0000 L CNN
F 1 "CONN_1" H 5000 3555 30  0001 C CNN
F 2 "" H 5000 3500 60  0000 C CNN
F 3 "" H 5000 3500 60  0000 C CNN
	1    5000 3500
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P3
U 1 1 544C2F70
P 5150 3500
F 0 "P3" H 5230 3500 40  0000 L CNN
F 1 "CONN_1" H 5150 3555 30  0001 C CNN
F 2 "" H 5150 3500 60  0000 C CNN
F 3 "" H 5150 3500 60  0000 C CNN
	1    5150 3500
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P8
U 1 1 544C2F76
P 5850 3500
F 0 "P8" H 5930 3500 40  0000 L CNN
F 1 "CONN_1" H 5850 3555 30  0001 C CNN
F 2 "" H 5850 3500 60  0000 C CNN
F 3 "" H 5850 3500 60  0000 C CNN
	1    5850 3500
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P6
U 1 1 544C2F7C
P 5700 3500
F 0 "P6" H 5780 3500 40  0000 L CNN
F 1 "CONN_1" H 5700 3555 30  0001 C CNN
F 2 "" H 5700 3500 60  0000 C CNN
F 3 "" H 5700 3500 60  0000 C CNN
	1    5700 3500
	0    -1   -1   0   
$EndComp
$Comp
L CONN_4 P5
U 1 1 544C2F84
P 5450 4400
F 0 "P5" V 5400 4400 50  0000 C CNN
F 1 "CONN_4" V 5500 4400 50  0000 C CNN
F 2 "" H 5450 4400 60  0000 C CNN
F 3 "" H 5450 4400 60  0000 C CNN
	1    5450 4400
	0    1    1    0   
$EndComp
$Comp
L CONN_3 K1
U 1 1 544C2F9D
P 5450 4900
F 0 "K1" V 5400 4900 50  0000 C CNN
F 1 "CONN_3" V 5500 4900 40  0000 C CNN
F 2 "" H 5450 4900 60  0000 C CNN
F 3 "" H 5450 4900 60  0000 C CNN
	1    5450 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5850 3650 5850 4050
Wire Wire Line
	5850 4050 5600 4050
Wire Wire Line
	5500 3650 5700 3650
Wire Wire Line
	5500 3650 5500 4050
Wire Wire Line
	5150 3650 5400 3650
Wire Wire Line
	5400 3650 5400 4050
Wire Wire Line
	5000 3650 5000 4050
Wire Wire Line
	5000 4050 5300 4050
$Comp
L RJ45_DUAL U1
U 1 1 544D5C0C
P 5450 6350
F 0 "U1" H 5450 5800 60  0000 C CNN
F 1 "RJ45_DUAL" H 5450 6900 60  0000 C CNN
F 2 "~" H 5450 6350 60  0000 C CNN
F 3 "~" H 5450 6350 60  0000 C CNN
	1    5450 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 5550 5550 5650
Wire Wire Line
	4700 5650 5700 5650
Wire Wire Line
	4700 5650 4700 6050
Wire Wire Line
	4800 5650 4800 6050
Connection ~ 4800 5650
Wire Wire Line
	4900 6050 4900 5650
Connection ~ 4900 5650
Wire Wire Line
	5500 6050 5500 5650
Connection ~ 5500 5650
Wire Wire Line
	5600 5650 5600 6050
Connection ~ 5550 5650
Wire Wire Line
	5700 5650 5700 6050
Connection ~ 5600 5650
Wire Wire Line
	5400 6050 5400 5600
Wire Wire Line
	5400 5600 5450 5600
Wire Wire Line
	5450 5600 5450 5250
Wire Wire Line
	5300 6050 5300 5950
Wire Wire Line
	5200 5950 5400 5950
Connection ~ 5400 5950
Wire Wire Line
	5200 6050 5200 5950
Connection ~ 5300 5950
Wire Wire Line
	6000 6050 6000 5700
Wire Wire Line
	5400 5700 6200 5700
Connection ~ 5400 5700
Wire Wire Line
	6100 5700 6100 6050
Connection ~ 6000 5700
Wire Wire Line
	6200 5700 6200 6050
Connection ~ 6100 5700
Wire Wire Line
	5000 6050 5000 5800
Wire Wire Line
	5000 5800 5800 5800
Wire Wire Line
	5800 5800 5800 6050
Wire Wire Line
	5100 6050 5100 5900
Wire Wire Line
	5100 5900 5900 5900
Wire Wire Line
	5900 5900 5900 6050
Wire Wire Line
	6200 5850 6750 5850
Connection ~ 6200 5850
Wire Wire Line
	4350 2500 4350 7050
Wire Wire Line
	4350 7050 6750 7050
Connection ~ 6500 6400
Wire Wire Line
	4000 6400 4400 6400
$Comp
L GND #PWR01
U 1 1 544D5E6E
P 6500 6100
F 0 "#PWR01" H 6500 6100 30  0001 C CNN
F 1 "GND" H 6500 6030 30  0001 C CNN
F 2 "" H 6500 6100 60  0000 C CNN
F 3 "" H 6500 6100 60  0000 C CNN
	1    6500 6100
	1    0    0    -1  
$EndComp
NoConn ~ 5350 5250
$Comp
L CONN_2 P9
U 1 1 544D6287
P 6100 5400
F 0 "P9" V 6050 5400 40  0000 C CNN
F 1 "FUSE" V 6150 5400 40  0000 C CNN
F 2 "" H 6100 5400 60  0000 C CNN
F 3 "" H 6100 5400 60  0000 C CNN
	1    6100 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 5250 5750 5250
Wire Wire Line
	5750 5250 5750 5300
Wire Wire Line
	5550 5550 5750 5550
Wire Wire Line
	5750 5550 5750 5500
Wire Wire Line
	6500 5850 6500 6100
Wire Wire Line
	6500 7050 6500 6400
$Comp
L GNDPWR #PWR02
U 1 1 544FF692
P 4000 6650
F 0 "#PWR02" H 4000 6700 40  0001 C CNN
F 1 "GNDPWR" H 4000 6570 40  0000 C CNN
F 2 "" H 4000 6650 60  0000 C CNN
F 3 "" H 4000 6650 60  0000 C CNN
	1    4000 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 6650 4000 6400
Connection ~ 4350 6400
$Comp
L CONN_3 K2
U 1 1 544FF6DC
P 5450 2150
F 0 "K2" V 5400 2150 50  0000 C CNN
F 1 "CONN_3" V 5500 2150 40  0000 C CNN
F 2 "" H 5450 2150 60  0000 C CNN
F 3 "" H 5450 2150 60  0000 C CNN
	1    5450 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5450 2850 5450 2500
Wire Wire Line
	5350 2500 4350 2500
Wire Wire Line
	6750 7050 6750 5850
Connection ~ 6500 7050
Connection ~ 6500 5850
$EndSCHEMATC
