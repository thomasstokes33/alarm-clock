import machine
import utime
import network
import socket as sockImport
import time
import ntptime
# Configuration
SSID = "VM2B5E78"
WIFI_PASSWORD = "ysd5s4kXwjce"
WEB_SERVER_PORT = 8080
led= machine.Pin("LED", machine.Pin.OUT)


sensor_temp = machine.ADC(4)
conversion_factor = 3.3 / (65535) #used to convert reading to voltage
# Connect to wifi
 

def connect_wlan():
    sta_if = network.WLAN(network.STA_IF) #connects to a router
    print("is connected "+str(sta_if.isconnected()))

    print("Connecting")
    sta_if.active(True)
    sta_if.connect(SSID, WIFI_PASSWORD)
    max_wait = 10
    while max_wait>0:
        if sta_if.status()<0 or sta_if.status()>=3:
            break
        time.sleep(1)
        max_wait-=1
    if (sta_if.status()!=3):
        print("Failed to connect to wifi")
    else:
        print("Connected. Config:",sta_if.ifconfig()[0]) #tuple of address, subnet, router address and dns
        #what is return type of ifconfig?
        





print("Starting")
connect_wlan() 
led.value(1)
time.sleep(1)
led.value(0)
print("Local time now "+ str(time.localtime()))
ntptime.settime()
while True:
      print("Time is "+str(time.localtime()))
      time.sleep(2)
    
    