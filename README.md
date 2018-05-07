# Acid.Cam.v2.Qt


Acid Cam distorts video to create art. It is designed to bo used with other software or on its own. There is multiple versions of the program for macOS, Linux, and Windows as well as a command line version of the program.

This project was created in hopes of providing some entertainment, or for the Glitch artist to give you a starting image/video to use with other tools.

I call the art that I create with Acid Cam an Acid Glitch, but you can call it whatever you want. It is just meant to be a tool to use with other programs to help aid in the creation of artistic images/videos.

Acid Cam's effects are created by using Acid Cam 'filters', or pieces of code that distort an image and can be combined to produce some interesting results. The project currently has 200 filters to mix and match.

![AnimatedImage](https://github.com/lostjared/Acid.Cam.v2.Qt/blob/master/screens/jaredpeace.gif "screenshot")

First download GCC/Automake/Autoconf with g++ compiler and make then compile on Debian install libqt4-dev and libopencv-dev via Terminal with

	$ sudo apt-get install libqt4-dev libopencv-dev

Also install pkg-config

You will also need libacidcam

Download libacidcam from: https://github.com/lostjared/libacidcam

Compile and install the library

$ ./autogen.sh && ./configure && make && sudo make install

Then (on Linux) use ldconfig 

	$ sudo ldconfig

Next download this project via git clone or zip enter the src directory

	$ qmake

Then to build project

	$ make 

Then Run the program

For sample videos and updates about this software view the Facebook page: http://facebook.com/AcidCam

This is an application that will allow you to generate video files/images with live video or video files. This is accomplished by mixing different 'filters' 
in different orders to produce different results. This program could be useful to you for generating basic artwork to be manipulated further. Also I have seen 
it used to create video for music videos or just for fun. 

Cross platform version of Acid Cam written in C++11 

To compile on Linux watch this video: https://youtu.be/ntsoGTglWzY

To develop C++ filters that the program will load dynamically see the example
filter in the plugins directory. The program will look for two functions:

void pixel(int x, int y, unsigned char *buffer);

void complete();

pixel is called once for every pixel in the frame and complete is called
when every pixel has been drawn. 

The output from the program video file size can be very large. This is because OpenCV records at a very high bitrate. I usually load the file into Final Cut and share as H.264.
You also could use Handbrake of FFmpeg to adjust the file size for uploading to the internet.


For the Windows version of this program requires the Visual Studio 2013 Runtime Redistributable:
https://www.microsoft.com/en-us/download/confirmation.aspx?id=40784

Currently program works best when ran in Video mode, I have not been able to test
on host os of windows or linux, just a guest virtual machine.  But in the VM webcam 
resolution is maximum of 640x480.

Screen shots of program on different Operating Systems:

Screenshot from Windows:

![ScreenShot](https://github.com/lostjared/Acid.Cam.v2.Qt/blob/master/screens/acidcam.1.win.jpg?raw=true "screenshot 1")

Screenshot from Linux:

![ScreenShot](https://github.com/lostjared/Acid.Cam.v2.Qt/blob/master/screens/acidcam.2.lin.jpg?raw=true "screenshot 2")

Screenshot from macOS:

![ScreenShot](https://github.com/lostjared/Acid.Cam.v2.Qt/blob/master/screens/acidcam.3.osx.jpg?raw=true "screenshot 3")

