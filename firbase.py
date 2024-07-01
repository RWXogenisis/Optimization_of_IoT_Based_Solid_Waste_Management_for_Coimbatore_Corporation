import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
import time
import serial

# Initialize the app with the credentials file
cred = credentials.Certificate('firebase-credentials.json')
firebase_admin.initialize_app(cred, {
    'databaseURL':'https://xxxxxxxxxx.firebaseio.com'
})

# Get a reference to the database root
root = db.reference('/')
ser = serial.Serial('/dev/cu.usbmodem11301', 9600) # Replace with your own port and baud rate

try:
    while True:
        # Get the current time and format it as a string
        line = ser.readline().decode().strip()

        # Write the timestamp to the database
        if 'distance1: ' in line:
                print("inside the condition")
                if int(line[-2::1])<5:
                    root.update({'Peelamedu': 2})
                elif int(line[-2::1])>=5 and int(line[-2::1])<=9:
                    root.update({'Peelamedu': 1})
                else:
                    root.update({'Peelamedu': 0})
                root.update({'Peelamedu_distance': int(line[-2::1])})
                
                    
        
        # Print the line to the console
        print(line)
        

        # Wait for 1 second
        time.sleep(1)

except KeyboardInterrupt:
    # Close the file and serial port
    ser.close()
