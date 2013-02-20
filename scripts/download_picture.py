#! /usr/bin/python3

import urllib.request
import os
import time

def download_image(url, path):
	urllib.request.urlretrieve(url, path)

def main():
	count_images = 500
	for i in range(count_images):
		url  = "http://blender-mirror.kino3d.org/peach/png/big_buck_bunny_00{0}.png".format(i + 100)
		path = "big_buck_bunny_00{0}.png".format(i + 100)
		download_image(url, path)
		pr = (i + 1) * 100.0 / count_images
		print("{0}%     :".format(pr), url, " --> ", path)
		time.sleep(1) # for low level load on server
	print('done.')
	pass

if __name__ == "__main__":
	main()
	