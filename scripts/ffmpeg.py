#! /usr/bin/python3

import os
import time
import argparse

def print_time(sec):
    h = int(sec / (60 * 60))
    sec -= h * (60 * 60)
    m = int(sec / 60)
    sec -= m * 60
    s = int(sec)
    ms  = int((sec - s) * 100)
    print('encode time : {0:02}:{1:02}:{2:02}.{3:02}'.format(h, m, s, ms))

def create_cmd(fps, codec, bitrate, output):
    input = "-i big_buck_bunny_052%02d.png "

    f = " -r {0}".format(fps)

    c = " -vcodec "
    if (codec == "XVID"): c += "libxvid -aspect 16:9"
    if (codec == "H264"): c += "libx264 "

    b = " -b {0}".format(bitrate)

    return input + "{0} {1} {2} {3}".format(f, c, b, output)

def run_ffmpeg(cmd):
    start = time.time()
    print("\nRUN : ffmpeg " + cmd + '\n')
    os.system('ffmpeg ' + cmd)
    finish = time.time()
    print_time(finish - start)

def main():
    parser = argparse.ArgumentParser(description='create video with FFmpeg.')
    parser.add_argument('-f', '--fps', type=float, default=30.0,
                        help='set fps for creating video')
    parser.add_argument('-o', '--output', type=str, default="output.mp4",
                        help='set name of output video file')
    parser.add_argument('-b', '--bitrate', type=str, default="8500k",
                        help='set bitrate for output video file')
    parser.add_argument('-c', '--codec', choices=['XVID', 'H264', 'WebM'],
                        default='XVID', help='set fps for creating video')
    args = parser.parse_args()

    run_ffmpeg(" -version")
    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, args.output) + \
               " -pass 1 -an -y ")
    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, \
               '2' + args.output) + " -pass 2 -y ")
    pass

if __name__ == "__main__":
    main()
