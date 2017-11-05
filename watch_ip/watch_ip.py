#--*--coding:utf-8--*--

import socket
import os
from mail import Mail
import requests

def GetConnectedState():
	return1 = os.system('ping 114.114.114.114 -c 2')
	if return1:
		return False
	else:
		return True
def CheckConnection():
	try:
		r1 = requests.get("http://www.baidu.com", timeout=5)
		if str(r1.status_code) == "200":
			return True
		return False
	except Exception as e:
		return False

def GetIP():
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		s.connect(('8.8.8.8', 80))
		ip = s.getsockname()[0]
	finally:
		s.close()
 
	return ip

def main():
	IsConnected = False
	ConnectedChanged = False
	if CheckConnection():
		IsConnected = True
		ConnectedChanged = True

	while True:
		IsConnected_new = CheckConnection()
		if IsConnected == IsConnected_new:
			ConnectedChanged = ConnectedChanged
		else:
			ConnectedChanged = not ConnectedChanged

		if ConnectedChanged:
			IsConnected = CheckConnection()
			if IsConnected:
				IP = GetIP()
				mail = Mail()
				server = mail.Login()
				mail.SendMail(server, IP)
				ConnectedChanged = False
			else:
				IsConnected = CheckConnection()	
		else:
			continue	
if __name__ == '__main__':
	main()
