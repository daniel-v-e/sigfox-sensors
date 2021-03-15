import dash_core_components as dcc
import dash_html_components as html
import dash_bootstrap_components as dbc
from dash.dependencies import Input, Output, State

# must add this line in order for the app to be deployed successfully on Heroku
# from app import server
from app import app
import configuration, statistics, home, downlink

dropdown = dbc.DropdownMenu(
    children=[
        dbc.DropdownMenuItem("Home", href="/home", style={'color': 'white'}),
        dbc.DropdownMenuItem("Statistics", href="/statistics", style={'color': 'white'}),
        dbc.DropdownMenuItem("Configuration", href="/configuration", style={'color': 'white'}),
        dbc.DropdownMenuItem("Downlink", href="/downlink", style={'color': 'white'}),
    ],
    nav = True,
    in_navbar = True,
    label = "Explore",
    toggle_style = {'color': 'white'}
)

navbar = dbc.Navbar(
    dbc.Container(
        [
            dbc.Col(width=1),
            html.A(
                dbc.Row([
                        dbc.Col(html.Img(src="/assets/divigraph.png", height="40px"), width=1, align="center"),
                        dbc.Col(dbc.NavbarBrand("Divigraph", className="ml-2"), width=1, align="center"),
                        ],
                        align="center",
                        no_gutters=True,
                ),
                href="/home",
            ),
            dbc.NavbarToggler(id="navbar-toggler2"),
            dbc.Collapse(
                dbc.Nav([dropdown], className="ml-auto", navbar=True),
                id="navbar-collapse2",
                navbar=True,
            ),
            dbc.Col(width=1),
        ],
        fluid = True
    ),
    color="primary",
    dark=True,
    className="mb-4",
)

def toggle_navbar_collapse(n, is_open):
    if n:
        return not is_open
    return is_open

for i in [2]:
    app.callback(
        Output(f"navbar-collapse{i}", "is_open"),
        [Input(f"navbar-toggler{i}", "n_clicks")],
        [State(f"navbar-collapse{i}", "is_open")],
    )(toggle_navbar_collapse)

app.layout = html.Div([
    dcc.Location(id='url', refresh=False),
    navbar,
    html.Div(id='page-content')
])

@app.callback(Output('page-content', 'children'),
              [Input('url', 'pathname')])
def display_page(pathname):
    if pathname == '/configuration':
        return configuration.layout
    elif pathname == '/statistics':
        return statistics.layout
    elif pathname == '/downlink':
        return downlink.layout
    else:
        return home.layout

if __name__ == '__main__':
    # app.run_server(debug=False, dev_tools_ui=False, dev_tools_props_check=False)
    app.run_server(debug=True)