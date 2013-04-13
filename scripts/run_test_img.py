#!/usr/bin/env python2

import subprocess
import numpy as np
import matplotlib.pyplot as plt

def run_experiments():
    f = open('output.txt', 'rt')
    text = f.read()
    f.close()    
    return text
   
def prase_output(out):
    list = out.split('}\n{')
    os = list[0].split('\n')

    t = []

    for i in list:
        l = i.split('\n')
        d = {'format':'', 'enc':'', 'dec':'', 'cmpr_size':'', 'orig_size':'', 'params':'', 'psnr':'', 'w':'', 'h':''}

        for j in l:            
            if j.find('format') >= 0:
                d['format'] = j[j.find(":")+1:j.find(";")]
            if j.find('params') >= 0:
                d['params'] = j[j.find(":")+1:j.find(";")]
            if j.find('enc') >= 0:
                d['enc'] = j[j.find(":")+1:j.find(";")]
            if j.find('dec') >= 0:
                d['dec'] = j[j.find(":")+1:j.find(";")]
            if j.find('cmpr size') >= 0:
                d['cmpr_size'] = j[j.find(":")+1:j.find(";")]
            if j.find('orig_size') >= 0:
                d['orig size'] = j[j.find(":")+1:j.find(";")]
            if j.find('PSNR') >= 0:
                d['psnr'] = j[j.find(":")+1:j.find(";")]
            if j.find('width') >= 0:
                d['w'] = j[j.find(":")+1:j.find(";")]
            if j.find('heigth') >= 0:
                d['h'] = j[j.find(":")+1:j.find(";")]

        t.append(d)

    return t

def draw_plt(t):
    fig = plt.figure()
    ax = plt.subplot(111)#, sharex='all', sharey='all')

    width = 0.35
    i = 0
    step  = 0.0

    colors = ['r', 'g', 'b']
    
    for f in ['.jpeg', 'png', '.webp']:
        x = []
        y = []
        for d in t:
            if (d['format'] == f):
                x.append(d['params'])
                y.append(float(d['psnr']))

        ind = np.arange(len(x))
        ax.bar(ind + step, y, width, color=colors[i])
        step += width
        i += 1
     
    ax.set_xticklabels([str(f) for f in x])

    plt.show()


def main():
    output = run_experiments()
    table = parse_output(output)
    draw_plt(table)
    pass

if __name__ == "__main__":
    main()