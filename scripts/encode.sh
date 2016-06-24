#!/usr/bin/python3 

import os

only_print = False # False # True

codec = ['XVID', 'H264', 'WebM']
bt    = ['40M', '60M', '80M', '100M', '120M', '140M', '160M', '180M', '200M']
fps   = ['30', '60', '120']
res   = [(3840, 2160), (4096, 4096), (7680, 4320), (8192, 8192)]

for r in res:
    cmd = 'rm bbb-png-big/*.png'
    if only_print:
        print(cmd)
    else:
        os.system(cmd)

    w, h = r
    cmd = './matrix_image -w=' + str(w) + ' -h=' + str(h) + ' -c=1800 -s=5200 -i=bbb-png/big_buck_bunny_%05d.png -o=bbb-png-big/output_%05d.png'
    if only_print:
        print(cmd)
    else:
        os.system(cmd)

    for c in codec:
        for b in bt:
            for f in fps:
                cmd = './ffmpeg.py -f ' + str(f) + ' -b ' + str(b) + ' -c ' + str(c) + ' -o benchmark_' + str(w) + 'x' + str(h) + '_' + str(f) + '_'+str(b)+'_'+str(c)+'.mkv'

                if only_print:
                    print(cmd)
                else:
                    os.system(cmd)

