cd dash
start /B python main.py
cd ../aws
start /B python demo.py
timeout 3 /nobreak
start "" http://127.0.0.1:8050/