#!/usr/bin/env python3 

import subprocess

def run_experiment(exp):
	cmd = './convert -i=' + exp
    return subprocess.getoutput(cmd)

def write_to_file(text):
	f = open('output.txt', 'a', encoding='utf-8')
	f.write(text)
	f.close()

experiments = ['4096x4096.png']

for exp in experiments:
    output = run_experiment(exp)
    write_to_file(output)
