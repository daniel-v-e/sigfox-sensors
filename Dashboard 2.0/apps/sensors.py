from app import app

import numpy as np
import pandas as pd

import plotly.graph_objects as go

import dash
import dash_core_components as dcc
import dash_html_components as html
import dash_bootstrap_components as dbc
from dash.dependencies import Input, Output

#----------------------------------------------------------------------------------------------------------------------#

def get_options(list_data):
    dict_list = []
    for i in list_data:
        dict_list.append({'label':i, 'value':i})

    return dict_list

df = pd.read_csv('aws/data/sensor_data.csv', parse_dates=True)
df.index = pd.to_datetime(df['timestamp'])

layout = html.Div([
    dbc.Container([
        dbc.Row([dbc.Col(html.H1("Sigfox Sensor Network"), className="mb-2")]),
        dbc.Row([dbc.Col(html.H6(children='Humidity, temperature, VOC, CO2, ADC'), className="mb-4")]),
        dbc.Row([dbc.Col(dbc.Card(html.H3(children='All Sensors',className="text-center bg-primary"),
                                  body=True,
                                  color="primary"),
                 className="mb-4")]),
        dbc.Row([
                dbc.Col(children=[
                            html.P('''Sensor type:'''),
                            dcc.Dropdown(id='dd_type',
                                         options=[{'label': 'STM32WL55', 'value': 'STM32WL55'},
                                                  {'label': 'S2LP', 'value': 'S2LP'},
                                                  {'label': 'TI', 'value': 'TI'}],
                                         style={'width': '330px', 'margin-bottom': '10px', 'color': 'black', 'background-color': 'white'}
                            ),
                        ]
                ),
                dbc.Col(children=[
                            html.P('''Sensor ID:'''),
                            dcc.Dropdown(id='dd_id',
                                         options=get_options(df['deviceId'].unique()),
                                         multi=True,
                                         style={'width': '330px', 'margin-bottom': '10px', 'color': 'black', 'background-color': 'white'}
                            ),
                        ]
                ),
                dbc.Col(children=[
                            html.P('''Data:'''),
                            dcc.Dropdown(id='dd_data',
                                         options=get_options(df['data'].unique()),
                                         style={'width': '330px', 'margin-bottom': '10px', 'color': 'black', 'background-color': 'white'}
                            )
                        ]
                )
            ]),

        dcc.Graph(id='timeseries', config={'displayModeBar': False}, animate=True),
        dcc.Graph(id='change', config={'displayModeBar': False}, animate=True),
        dcc.Interval(id='graph-update', interval=100*1000, n_intervals=0),

    ])
])

#----------------------------------------------------------------------------------------------------------------------#
# Callback function to enable/disable dd_id & dd_data based on dd_type and to set dd_id options
@app.callback([Output('dd_id', 'disabled'), Output('dd_id', 'value'), Output('dd_id', 'style'), Output('dd_id', 'options'),
               Output('dd_data', 'disabled'), Output('dd_data', 'value'), Output('dd_data', 'style'), Output('dd_data', 'options')],
               [Input('dd_type', 'value')])
def set_cities_options(value):
    style = {'width': '330px', 'margin-bottom': '10px', 'color': 'black', 'background-color': '#848a8e'}
    disabled = True
    options_id =  []
    options_data =  []
    if value:
        disabled = False
        style = {'width': '330px', 'margin-bottom': '10px', 'color': 'black', 'background-color': 'white'}
    if value == 'STM32WL55':
        options_id=get_options(df['deviceId'].unique())
        options_data=get_options(df['data'].unique())

    return [disabled, "", style, options_id, disabled, "", style, options_data]

# Callback function to update the timeseries based on the dropdown
@app.callback(Output('timeseries', 'figure'), [Input('dd_id', 'value'), Input('dd_data', 'value'), Input('graph-update', 'n_intervals')])
def update_timeseries(ids, data, n):

    df = pd.read_csv('aws/data/sensor_data.csv', parse_dates=True)
    df.index = pd.to_datetime(df['timestamp']) #remove this, make the graph read directly from the timestamp column if possible

    trace = []

    if ids and data:
        df_data = df[df['data']==data]
        xmin = df_data.index.min()
        xmax = df_data.index.max()
        ymin = df_data['value'].min()-0.05*np.abs(df_data['value'].max())
        ymax = df_data['value'].max()+0.05*np.abs(df_data['value'].max())
        for id in ids:
            df_data_id = df_data[df_data['deviceId']==id]
            trace.append(go.Scatter(x=df_data_id.index,
                                    y=df_data_id['value'],
                                    mode='lines',
                                    opacity=0.7,
                                    name=id,
                                    textposition='bottom center'
                        )
            )
    else:
        df_clear = df
        df_clear['value'].values[:] = 0
        xmin = df.index.min()
        xmax = df.index.max()
        ymin = -100
        ymax = 100
        trace.append(go.Scatter(x=df_clear.index,
                                y=df_clear['value'],
                                mode='lines',
                                opacity=0.7,
                                textposition='bottom center'
                    )
        )

    traces = [trace]
    data = [val for sublist in traces for val in sublist]

    figure = {'data': data,
              'layout': go.Layout(
                  colorway=['#FF4F00', '#FFF400', '#FF0056', "#5E0DAC", '#375CB1', '#FF7400'],
                  template='plotly_dark',
                  paper_bgcolor='rgba(0, 0, 0, 0)',
                  plot_bgcolor='rgba(0, 0, 0, 0)',
                  margin={'b': 15},
                  hovermode='x',
                  autosize=True,
                  title={'text': 'Sensor Data', 'font': {'color': 'white'}, 'x': 0.5},
                  xaxis={'range': [xmin, xmax]},
                  yaxis={'range': [ymin, ymax]},
              ),
    }

    return figure

# Callback function to update the change based on the dropdown
@app.callback(Output('change', 'figure'), [Input('dd_id', 'value'), Input('dd_data', 'value'), Input('graph-update', 'n_intervals')])
def update_change(ids, data, n):

    df = pd.read_csv('aws/data/sensor_data.csv', parse_dates=True)
    df.index = pd.to_datetime(df['timestamp']) #remove this, make the graph read directly from the timestamp column if possible

    trace = []

    if ids and data:
        df_data = df[df['data']==data]
        xmin = df_data.index.min()
        xmax = df_data.index.max()
        ymin = df_data['change'].min()-0.05*np.abs(df_data['change'].max())
        ymax = df_data['change'].max()+0.05*np.abs(df_data['change'].max())
        for id in ids:
            df_data_id = df_data[df_data['deviceId']==id]
            trace.append(go.Scatter(x=df_data_id.index,
                                    y=df_data_id['change'],
                                    mode='lines',
                                    opacity=0.7,
                                    name=id,
                                    textposition='bottom center'
                        )
            )
    else:
        df_clear = df
        df_clear['change'].values[:] = 0
        xmin = df.index.min()
        xmax = df.index.max()
        ymin = -10
        ymax = 10
        trace.append(go.Scatter(x=df_clear.index,
                                y=df_clear['change'],
                                mode='lines',
                                opacity=0.7,
                                textposition='bottom center'
                    )
        )

    traces = [trace]
    data = [val for sublist in traces for val in sublist]

    figure = {'data': data,
              'layout': go.Layout(
                  colorway=['#FF4F00', '#FFF400', '#FF0056', "#5E0DAC", '#375CB1', '#FF7400'],
                  template='plotly_dark',
                  paper_bgcolor='rgba(0, 0, 0, 0)',
                  plot_bgcolor='rgba(0, 0, 0, 0)',
                  margin={'t': 50},
                  height=250,
                  hovermode='x',
                  autosize=True,
                  title={'text': 'Change', 'font': {'color': 'white'}, 'x': 0.5},
                  xaxis={'range': [xmin, xmax]},
                  yaxis={'range': [ymin, ymax]},
              ),
    }

    return figure
