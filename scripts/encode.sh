#!/usr/bin/python3 

import os

only_print = False # False # True

codec = ['XVID', 'H264', 'WebM']
bt    = ['60M', '80M', '100M']
fps   = ['300/10', '600/10']
res   = [(3840, 2160), (3600, 3600), (4000, 4000), (4096, 4096), (8192, 8192), (7680, 4320)]

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

	for b in bt:
		for c in codec:
			for f in fps:
				cmd = './ffmpeg.py -f ' + str(f) + ' -b ' + str(b) + ' -c ' + str(c) + ' -o benchmark_' + str(w) + 'x' + str(h) + '_' + str(f) + '_'+str(b)+'_'+str(c)+'.mkv'

				if only_print:
					print(cmd)
				else:
					os.system(cmd)
