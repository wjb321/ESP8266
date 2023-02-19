
mqtt cofigure instructions:
step 1 AT+RST
step 2 AT+CWMODE=1
step 3 AT+CIPSNTPCFG=1,8, "ntp1.aliyun.com"
step 4 AT+CWJAP="WiFi name", "WiFi password"
step 5 AT+MQTTUSERCFG=0,1, "NULL", "username", "password",0,0,""
step 6 AT+MQTTCLIENTID=0, "ClienId" //clientId second parameter note the separator before each comma \
step 7 AT+MQTTCONN=0, "ConnectionDomain",1883,1
AT+MQTTSUB=0, "topic",1 //subscribe command
AT+MQTTPUB=0, "topic", "AJson format content",1,0 //publish command
Note: "preceded by an escape character \ preceded by an escape character


