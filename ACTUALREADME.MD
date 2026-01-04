**Hey there! Cucuzacu here!**



The main reason I made this fork is [this issue](https://github.com/shinh/elvm/issues/46).

*108 GIGABYTES*????? That's abnormal...

ELVM-Remastered compiles to just **2.40 MB**, which is way better!
Use this command to build(on Ubuntu): *make -j$(nproc)*

This project aims to turn the configuration files into something as simple as possible. The original Makefile was almost 20 KB, now it is 2 KB. The project is well-structured and easy to understand. I also aim on supporting more of the C library.

Try this:

*./build/bin/8cc -Isrc/8cc/include -S t.c -o t.eir*

*./build/bin/eli t.eir*

You should see the letter **"a"**!

To convert the code to js, do:
*./build/bin/elc -js t.eir > t.js*



Change **t.c** to any file you want to compile!!!

**t.eir** and **t.js** are the output; name them however you want.

Change the -js argument to any language you want(from the list).



If the project has more files, you have to create a **project.c** file containing:

**#include "file1.h"**

**#include "file1.c"**

**#include "main.c"**

**//all the other files...**

Then, do *./build/bin/8cc -Isrc/8cc/include -S project.c -o project.eir*

Now, you can run this with eli or compile it with elc!



I think that is all! Bye!

