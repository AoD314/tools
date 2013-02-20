
Usage: 

$ ./matrix_image -i=big_buck_bunny_0%4d.png -o=img -s=7580 -c=4
$ ls *.png
img_00000000.png  img_00000001.png  img_00000002.png  img_00000003.png

// start read image: 
 /home/aod314/work/PNG/big_buck_bunny_07580.png
 /home/aod314/work/PNG/big_buck_bunny_07581.png
 ...
 /home/aod314/work/PNG/big_buck_bunny_07583.png


// first version
$ ./convert 

image orig: img_00000000.png
image save: img_00000000.png.png(100)
time encode(sec):   5.9719
time decode(sec):   1.7873
PSNR            : 361.2020
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :   59766782 bytes ~    56.9980 Mb
save/orig       : 1.0000

image orig: img_00000000.png
image save: img_00000000.png.100.jpg(100)
time encode(sec):   0.9280
time decode(sec):   0.6629
PSNR            :  41.3001
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :   27998038 bytes ~    26.7010 Mb
save/orig       : 0.4685

image orig: img_00000000.png
image save: img_00000000.png.90.jpg(90)
time encode(sec):   0.4690
time decode(sec):   0.4047
PSNR            :  38.8306
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    6756668 bytes ~     6.4437 Mb
save/orig       : 0.1131

image orig: img_00000000.png
image save: img_00000000.png.80.jpg(80)
time encode(sec):   0.4396
time decode(sec):   0.3676
PSNR            :  37.0142
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    4574338 bytes ~     4.3624 Mb
save/orig       : 0.0765

image orig: img_00000000.png
image save: img_00000000.png.70.jpg(70)
time encode(sec):   0.4102
time decode(sec):   0.3555
PSNR            :  36.0590
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    3727115 bytes ~     3.5545 Mb
save/orig       : 0.0624

image orig: img_00000000.png
image save: img_00000000.png.60.jpg(60)
time encode(sec):   0.4011
time decode(sec):   0.3482
PSNR            :  35.4084
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    3231268 bytes ~     3.0816 Mb
save/orig       : 0.0541

image orig: img_00000000.png
image save: img_00000000.png.50.jpg(50)
time encode(sec):   0.3966
time decode(sec):   0.3434
PSNR            :  34.9236
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    2910389 bytes ~     2.7756 Mb
save/orig       : 0.0487

image orig: img_00000000.png
image save: img_00000000.png.40.jpg(40)
time encode(sec):   0.3894
time decode(sec):   0.3393
PSNR            :  34.4037
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    2616690 bytes ~     2.4955 Mb
save/orig       : 0.0438

image orig: img_00000000.png
image save: img_00000000.png.30.jpg(30)
time encode(sec):   0.3832
time decode(sec):   0.3327
PSNR            :  33.6290
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    2309108 bytes ~     2.2021 Mb
save/orig       : 0.0386

image orig: img_00000000.png
image save: img_00000000.png.20.jpg(20)
time encode(sec):   0.3753
time decode(sec):   0.3269
PSNR            :  32.4588
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    1940002 bytes ~     1.8501 Mb
save/orig       : 0.0325

image orig: img_00000000.png
image save: img_00000000.png.10.jpg(10)
time encode(sec):   0.3676
time decode(sec):   0.3188
PSNR            :  29.7705
size orig       :   59766782 bytes ~    56.9980 Mb
size save       :    1503802 bytes ~     1.4341 Mb
save/orig       : 0.0252
