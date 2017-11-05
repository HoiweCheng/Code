
from email.mime.text import MIMEText 
import smtplib

from_addr = '**@qq.com'
user = '**@qq.com'
password = '**' #this is your smtp password
smtp_server = "smtp.qq.com"
to_addr = '**@qq.com'

class Mail(object):
	"""docstring for Mail"""
	def __init__(self):
		super(Mail, self).__init__()
		self.from_addr = from_addr
		self.user = user
		self.password = password
		self.smtp_server = smtp_server
		self.to_addr = to_addr
	
	def Login(self):
		try:
			server = smtplib.SMTP_SSL(self.smtp_server, 465) # SMTP协议默认端口是25
			#server.set_debuglevel(1)
			server.ehlo()
			server.login(self.user, self.password) 
			return server
		except smtplib.SMTPException:
			return None
		

	def SendMail(self, server, content):
		msg = MIMEText(content, 'plain', 'utf-8')
		msg['subject'] = 'lab server IP'
		if server != None:
			try:
				server.sendmail(self.from_addr, [self.to_addr], msg.as_string())
				server.close()
				return True
			except smtplib.SMTPException:
				return False
if __name__ == '__main__':
	mail = Mail()
	server = mail.Login()
	mail.SendMail(server, "hello")