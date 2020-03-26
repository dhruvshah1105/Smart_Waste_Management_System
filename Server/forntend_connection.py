from flask import Flask,render_template
from socket import *
import mysql.connector
from datetime import datetime
import time
mydb = mysql.connector.connect(
    host="localhost",
    user="dhruv1105",
    passwd="dhruv1105",
    database="esp8266_1"
)

mycursor = mydb.cursor()
app = Flask(__name__)

@app.route('/')
@app.route('/Frontend_Index.html')
def index():
	s = socket()
	s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
	s.bind(('0.0.0.0',12345))
	s.listen(0)
	now = datetime.now()
	id = 1
	formatted_date = now.strftime('%Y-%m-%d %H:%M:%S')
	client, addr = s.accept()
	content = client.recv(32)
	try:
   		content = int(content.decode())
	except:
      		pass
	if(type(content) == type(10)):
       		print(content)
       		mycursor.execute("insert into esp8266_1(Date_Time, Level) values(%s,%s)",(formatted_date,content))
       		mydb.commit()
	client.close()
	return render_template('Frontend_Index.html',data = content)

@app.route('/aboutproject.html')
def aboutproject():
   return render_template('aboutproject.html')

@app.route('/contactus.html')
def contactus():
   return render_template('contactus.html')

if __name__=='__main__':
         app.run(debug=True)
