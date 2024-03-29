# Remote Metering Sigfox/AWS/Dash App

## About this app

A distributed sensor network sends data via the Sigfox LPWAN to an AWS database.
This application retrieves that data and visualizes it in a Dash GUI.
```main.py```  runs the GUI. ```aws_app.py``` retrieves the data from AWS.
They can be used independently or concurrently. If used concurrently, the 
GUI will display live updates of incoming sensor data (approx. once every 
six hours).

Note that for demonstration purposes, the app scans the entire DynamoDB database once
per second, and updates the local copy of the data accordingly. However, for
practical implementation, the sampling rate (sampling_rate in aws_app.py)
can be set to once per day, for example. Ideally, a Lambda function should be
written as to notify the app when entries are added to the DynamoDB database,
but this has not been implemented as of yet. Reading the database at a high
rate will eventually incur a cost, but remains well within the free tier for 
demonstration purposes.

In order for the application to have access to DynamoDB, the AWS config and
credentials need to be set. Create the files if they do not exist. 

Linux:  
~/.aws/credentials  
~/.aws/config  

Windows:  
C:\Users\<username>\.aws\credentials  
C:\Users\<username>\.aws\config  

'credentials' should contain:  
[default]  
aws_access_key_id = YOUR_ACCESS_KEY_ID  
aws_secret_access_key = YOUR_SECRET_ACCESS_KEY  

'config' should contain:  
[default]  
region = YOUR_REGION



## How to run this app

This application requires Python 3. Clone this repository and open a terminal
inside the root folder. Create and activate a new virtual environment 
(recommended) by running the following:

Create a virtual environment:  
```python -m venv venv```

Activate the virtual environment:  
```source venv/bin/activate```   (Windows: ```.\venv\Scripts\activate```)

Install the requirements:
```pip install -r requirements.txt```  

Run the GUI only:

```python main.py```  

Run the AWS app only:

```python aws_app.py```  

Run the full dashboard:

```python main.py``` and ```python aws_app.py``` in separate terminal windows.  

The browser should open at http://127.0.0.1:8050. Refresh the page if it does not load immediately - 
it might take a while, depending on your hardware.



## Screenshots

Channel view:
![channel.png](channel.png)

Device view:
![device.png](device.png)

Location view:
![location.png](location.png)
