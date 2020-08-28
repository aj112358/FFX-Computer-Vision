# FFX-Computer-Vision
A project that uses computer vision to complete the "Dodge 200 Lightning Strikes" side-quest in FFX. The collected data was investigated through a data analysis to gain some insight into the game mechanics.

_"Listen to my story...this may be our last chance"_
        
_- Tidus_

## Problem Description

Final Fantasy X (FFX) is a game first released for the Playstation 2 console in 2001, then later released onto a wider variety of consoles between 2013 - 2019.

## Project Goals

There were two main goals for this project:

1. Create an automated solution to complete the "Lightning Dodge" challenge.
2. Collect data to investigate the behaviour of and gain insight to the timing of the lightning strikes.

The first goal was completed successfully through our electronics setup. The setup consisted of a webcam that was connected to a Raspberry Pi 4 (Rpi4) that was picking up the video input from the game. The Rpi4 had an IoT connection with an Arduino Uno that would press the Playstation 4 controllor button




The second goal was completed through a data analysis. I did the data analysis using a Jupyter Notebook as the main IDE. I started by importing the raw data and performing some data cleaning procedures. I then created some new features and went into the exploratory data analysis phase.


## Project Summary (Data Analysis)

The main goal of the data analysis was to gather insight into the timing of the lightning strikes.

Here are the main findings from the data analysis:
1. The lightning strike frequency is NOT random, as we had hypothesized from the start!
2. The time interval between lightning strikes is either ~6s or ~11s.
3. The two time intervals between lightning strikes alternate.


## Python Libraries Used

* Python Version: 3.7

* Libraries: numpy, pandas, matplotlib, seaborn, plotly (via chart_studio), cufflinks, datetime, scipy

* Libraries for data collection: open-cv


## Data Collection Methodology

We created a Python script that uses computer vision (CV) via the OpenCV library. A webcam aimed at the screen was set up to continuously detect the video-feed from the game feed it into our script. By nature of video media, this meant our script was constantly receiving individual frames at a rapid frequency. These colored frames were then converted into grayscale. This OpenCV Python script on a Raspberry Pi 4 (Rpi4). 

The Rpi4 was connected in a circuit with an Arduino Uno microcontroller which we used to control the button presses on the PS4 controller. Because a lightning strike causes the screen to become bright, our script sent a signal from the Rpi4 to the Arduino to activate based on a certain grayscale threshold value. Hence, the electronics and software setup was able to successfully detect a lightning strike and send a signal to cause the PS4 controller button to be physically pressed.

## Data Cleaning

I had to clean the data a lot. Here are some specifics:

* boom
* shaka
* laka

## Feature Engineering

The main thing I was interested in was the timing of the lightning strikes.

## Exploratory Data Analysis

Here is what I discovered...

## Authors

* **AJ Singh** (https://github.com/aj112358)
* **Lucas Ramos-Strankman** (https://github.com/LucasRStrankman)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* OpenCV creators and contributors for such a useful library
* Creators of the Final Fantasy videogame franchise: Yoshinori Kitase, Motomu Toriyama, Takayoshi Nakazato, Toshiro Tsuchida, Koji Sugimoto, Takashi Katano, Tetsuya Nomura, Yusuke Naora, Shintaro Takai, Kazushige Nojima, Daisuke Watanabe, Motomu Toriyama, Nobuo Uematsu, Masashi Hamauzu, Junya Nakano, and all others who helped to develop the games
* Viewers of my GitHub page. Thank you for visiting!
