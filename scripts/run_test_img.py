#!/usr/bin/env python2

import subprocess
import numpy as np
import matplotlib.pyplot as plt

def run_experiments():
    f = open('output.txt', 'rt')
    text = f.read()
    f.close()    
    return text
   
def prase_all_output(out):
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

def draw_plt(y, x, yt, xt, t, leg):
    """ amount of draw < 9 """
    colors = ['#ff0000','#00ff00','#0000ff','#ffff00','#ff00ff','#00ffff','#ff8000','#000000','#c0c0c0']
    fig = plt.figure()
    plt.ylabel(yt)
    plt.xlabel(xt)
    plt.title(t)
    n = len(y) / len(x)
    width = (0.5 + (float(n) - 1.0) / ( 2.0 * float(n))) / float(n)
    ind = np.arange(len(x))
    l = []
    for i in range(n):
        l += [plt.bar(ind + i * width, y[i*len(x):(i+1)*len(x)], width, color=colors[i])[0]]
    lab = [str(i) for i in x]
    plt.xticks(ind + width * n / 2.0, lab)
    plt.legend(l, leg)
    plt.savefig(t.replace(' ', '_').replace('(','__').replace(')','__').lower() + '.svg')
    #plt.show()

def grep_data_by(table, format, params, w, h):
    l = []
    for i in table:
        if format != '*' and i['format'] != format:
            continue
        if params != '*' and i['params'] != params:
            continue
        if w != '*' and i['w'] != w:
            continue
        if h != '*' and i['h'] != h:
            continue
        l += [i]
    return l

def merge_arr(a1, a2):
    l = []
    for i in range(len(a1)):
        l += [float(a1[i]), float(a2[i])]
    return l

def get_array_by_table(table, val):
    a = []
    for i in table:
        a += [i[val]]
    return a


def main():
    output = run_experiments()
    table = prase_all_output(output)

    l = grep_data_by(table, '.webp', '*', '4096', '4096')
    x = get_array_by_table(l, 'params')



    l = grep_data_by(table, '.webp', '*', '4096', '4096')
    y_webp = get_array_by_table(l, 'psnr')

    l = grep_data_by(table, '.jpeg', '*', '4096', '4096')
    y_jpeg = get_array_by_table(l, 'psnr')

    y = merge_arr(y_webp, y_jpeg)
    
    draw_plt(y, x, "PSNR", "Quality", 'WebP vs Jpeg (Quality-PSNR)', ['webp', 'jpeg'])


    l = grep_data_by(table, '.webp', '*', '4096', '4096')
    y_webp = get_array_by_table(l, 'cmpr_size')

    l = grep_data_by(table, '.jpeg', '*', '4096', '4096')
    y_jpeg = get_array_by_table(l, 'cmpr_size')

    y = merge_arr(y_webp, y_jpeg)
    
    draw_plt(y, x, "Compression Size(kb)", "Quality", 'WebP vs Jpeg (Quality-Compression Size)', ['webp', 'jpeg'])

    #draw_plt([66, 68, 33, 35, 52, 55], [100, 90, 80], "YYY", 'XXX', 'test #02', ['only-x', 'only - y'])
    #x = range(3)
    #y = range(3*9)
    #draw_plt(y, x, "3*9", '3', 'test #03', ['#ff0000','#00ff00','#0000ff','#ffff00','#ff00ff','#00ffff','#ff8000','#000000','#c0c0c0'])
    pass

if __name__ == "__main__":
    main()