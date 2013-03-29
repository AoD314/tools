#!/usr/bin/python3 

import os

only_print = False # True

codec = ['WebM', 'H264', 'XVID']
bt    = ['40M', '60M', '80M', '100M', '120M']
res   = [(4096, 4096), (3840, 2160), (7680, 4320), (8192, 8192)]

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

#	print("create raw video")
#	cmd = 'ffmpeg -i bbb-png-big/output_%05d.png -c:v rawvideo raw.mkv'
#	if only_print:
#		print(cmd)
#	else:
#		os.system(cmd)

	for b in bt:
		for c in codec:
			cmd = './ffmpeg.py -f 30.0  -b ' + str(b) + ' -c ' + str(c) + ' -o benchmark_' + str(w) + 'x' + str(h) + '_'+str(b)+'_'+str(c)+'.mkv'

#			if c == 'WebM':
#				cmd = '/work/libvpx/vpxenc --codec=vp8 --passes=2 --threads=6 --best --end-usage=vbr --cq-level=8 --psnr --threads=8 '\
#				'--width='+ str(w) +' --height=' + str(h) + ' --target-bitrate=' + str(int(b[:-1])*1000) + ' -v  --fps=30/1 '\
#				' --min-q=0 --max-q=60 --static-thresh=0 --drop-frame=0 -o benchmark_' + b + '_.webm raw.mkv'
#
#			if c == 'H264':
#				cmd = 'x264 --crf 20 --fps 30 --input-res ' + str(w) +'x' + str(h)+ ' --preset placebo --pass 1 --subme 11 '\
#				'--bitrate ' + str(int(b[:-1])*1000) + ' --verbose --output benchmark_' + b + '_.mkv raw.mkv && '\
#				'x264 --crf 20 --fps 30 --input-res ' + str(w) +'x' + str(h)+ ' --preset placebo --pass 2 --subme 11 '\
#				'--bitrate ' + str(int(b[:-1])*1000) + ' --verbose --output benchmark_' + b + '_.mkv raw.mkv '

			if only_print:
				print(cmd)
			else:
				os.system(cmd)
