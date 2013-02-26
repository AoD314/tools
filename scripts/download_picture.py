#! /usr/bin/python3

import urllib.request
import os
import time

def download_image(url, path):
	urllib.request.urlretrieve(url, path)

def main():
	start_frame  = 5200
	count_images = 1800
	for i in range(count_images):
		# http://media.xiph.org/sintel/sintel-4k-png/00000001.png
		# http://blender-mirror.kino3d.org/peach/png/big_buck_bunny_00000.png
		url  = "http://blender-mirror.kino3d.org/peach/png/big_buck_bunny_{0:05}.png".format(i + start_frame)
		path = "big_buck_bunny_{0:05}.png".format(i + start_frame)
		download_image(url, path)

		print("{:7.2%}   :  ".format(i / count_images), url, " --> ", path)
		time.sleep(0.5) # for low level load on server
	print('done.')
	pass

if __name__ == "__main__":
	main()
