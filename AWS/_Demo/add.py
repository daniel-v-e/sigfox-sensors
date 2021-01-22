from botocore.exceptions import ClientError
from boto3.dynamodb.conditions import Key
import boto3

from datetime import datetime, timedelta
from decimal import Decimal
from pprint import pprint
import json

from plotly.subplots import make_subplots
import plotly.graph_objects as go
import plotly.express as px

from dash.dependencies import Input, Output
import dash_html_components as html
import dash_core_components as dcc
import dash

import math
import random
import pandas as pd
import numpy as np

import time
import sys

#----------------------------------------------------------------------------------------------------------------------#
def put_item_AWS(deviceId, timestamp, data, deviceTypeId, seqNumber, time, dynamodb=None):
    if not dynamodb:
        if online:
            dynamodb = boto3.resource('dynamodb',region_name='us-east-1')
        else:
            dynamodb = boto3.resource('dynamodb',endpoint_url="http://localhost:8000")

    table = dynamodb.Table(tableName)
    response = table.put_item(
        Item={
            'deviceId': deviceId,
            'timestamp': timestamp,
            'payload': {
                'data': data,
                'deviceTypeId': deviceTypeId,
                'seqNumber' : seqNumber,
                'time' : time
            }
        }
    )
    return response

#----------------------------------------------------------------------------------------------------------------------#
def now():
    return round(datetime.timestamp(datetime.now()))

def add_item():
    deviceId = '12CAC94'
    deviceTypeId = '5ff717c325643206e8d57c11'
    seqNumber = 25
    timestamp = now()
    time = timestamp
    data = round(1000*math.sin(0.1*random.randint(0,30)) * math.cos(random.randint(0,30)))
    item_resp = put_item_AWS(deviceId, timestamp, data, deviceTypeId, seqNumber, time)
    print("Item added")

#----------------------------------------------------------------------------------------------------------------------#
tableName = 'sigfox_demo'
num_items = 30
online = 0

#----------------------------------------------------------------------------------------------------------------------#
if __name__ == '__main__':
    while True:
        # Add a new item
        input('Press Enter to add an item')
        add_item()