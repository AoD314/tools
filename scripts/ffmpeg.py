#!/usr/bin/python3

import os, subprocess, time, argparse

def print_time(sec):
    h = int(sec / (60 * 60))
    sec -= h * (60 * 60)
    m = int(sec / 60)
    sec -= m * 60
    s = int(sec)
    ms  = int((sec - s) * 100)
    print('encode time : {0:02}:{1:02}:{2:02}.{3:02}'.format(h, m, s, ms))

def create_cmd(fps, codec, bitrate, output):

    f = " -r {0} ".format(fps)

    input = " {0} -i bbb-png-big/output_%05d.png ".format(f)

    c = " -codec:v "
    if (codec == "H264"): c += "libx264 -preset placebo -pix_fmt yuv420p "
    if (codec == "H265"): c += "libx265 -preset placebo -pix_fmt yuv420p "
    if (codec == "vp8"): c += "libvpx -deadline best -f webm -lag-in-frames 0 "
    if (codec == "vp9"): c += "libvpx-vp9 -deadline best -f webm -lag-in-frames 0 "

    b = " -b:v {0}".format(bitrate)

    return input + "{0} {1} {2} {3} -threads 12 ".format(c, b, f, output)

def run_ffmpeg(cmd):
    start = time.time()
    print("\n\n\nffmpeg " + cmd + '\n\n\n')
    os.system('ffmpeg ' + cmd)
    finish = time.time()
    print_time(finish - start)

def main():
    parser = argparse.ArgumentParser(description='create video with FFmpeg.')
    parser.add_argument('-f', '--fps', type=str, default='60',
                        help='set fps for creating video')
    parser.add_argument('-o', '--output', type=str, default="output.mkv",
                        help='set name of output video file')
    parser.add_argument('-b', '--bitrate', type=str, default="40M",
                        help='set bitrate for output video file')
    parser.add_argument('-c', '--codec', choices=['H264', 'H265', 'vp8', 'vp9'],
                        default='H264', help='set fps for creating video')
    parser.add_argument('-n', type=bool, default=False, help='print cmd donnt run')
    args = parser.parse_args()

    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, args.output) + " -pass 1 -an -y ")
    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, args.output) + " -pass 2 -y ")
    pass

if __name__ == "__main__":
    main()
