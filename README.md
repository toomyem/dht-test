# dht-test
Test DHT module for SimbaOS project.

Before my change from branch https://github.com/eerimoq/simba/pull/196 I was getting many read errors:
```
> miniterm.py /dev/ttyUSB0 76800
--- Miniterm on /dev/ttyUSB0  76800,8,N,1 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
..........t:24.899999, h:54.000000 (0/2) n:10
...............t:25.000000, h:54.000000 (0/3) n:15
.....t:25.000000, h:50.000000 (0/4) n:5
...............t:25.000000, h:54.000000 (0/5) n:15
................err: -71
.....t:25.000000, h:50.000000 (1/7) n:5
(...)
```

After the change:
```
> miniterm.py /dev/ttyUSB0 76800
--- Miniterm on /dev/ttyUSB0  76800,8,N,1 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
t:25.000000, h:50.000000 (0/1) n:0
t:25.000000, h:52.000000 (0/2) n:0
t:25.000000, h:50.000000 (0/3) n:0
t:25.000000, h:51.000000 (0/4) n:0
t:25.000000, h:50.000000 (0/5) n:0
(...)
```
