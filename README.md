# FFX-Computer-Vision
A project that uses computer vision to complete the "Dodge 200 Lightning Strikes" side-quest in FFX. The collected data was investigated through a data analysis to gain some insight into the game mechanics.

> _"Listen to my story...this may be our last chance"_
> _- Tidus_

## Problem Description

Final Fantasy X (FFX) is a game first released for the Playstation 2 console in 2001, then later released onto a wider variety of consoles between 2013 - 2019. It is a standard RPG-style game with side-quests deviating from the main storyline. One of these side quests happens to be the (now infamous) "Dodge 200 Lightning Strikes" which is essentially impossible to complete without extreme determination and focus. This is a project that avoids that needed extreme determination and focus, and provides a solution through implementation of various hardware and software.

## Project Goals

There were two main goals for this project:

1. Create an automated solution to complete the "Lightning Dodge" challenge.
2. Collect data to investigate the behaviour of and gain insight to the timing of the lightning strikes.

The first goal was completed successfully through our electronics setup. The setup consisted of a webcam that was connected to a Raspberry Pi 4 (Rpi4) that was picking up the video input from the game. The Rpi4 had an IoT connection with an Arduino Uno that would press the Playstation 4 controllor button

The second goal was completed through a data analysis. The IDE of choice for the data analysis was a Jupyter Notebook. After importing the raw data and performing data cleaning procedures, I created new features and then spent the majority of time within the exploratory data analysis phase.

## Project Summary (Data Analysis)

The main goal of the data analysis was to gather insight into the timing of the lightning strikes.

Here are the main findings from the data analysis:
1. The lightning strike frequency is NOT random, as we had hypothesized from the start!
2. The time interval between lightning strikes is either ~6s or ~11s.
3. The two time intervals between lightning strikes alternate.


## Hardware and Software Used Used

* Python Version: 3.7
* Python Libraries: numpy, pandas, matplotlib, seaborn, plotly (via chart_studio), cufflinks, datetime, scipy, open-cv

* Raspberry Pi 4
* Arduino Uno
* Logitech C922 Webcam

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

## Future Steps

Here are some avenues to continue expanding on this, or other FFX-related, projects in the future:
* Finish analysis of the grayscale data
* Create solutions for other side quests (dodging birds, anyone?)
* Look into other FF series games and apply your electronics and data science skills!

## Authors

* **AJ Singh** (https://github.com/aj112358)
* **Lucas Ramos-Strankman** (https://github.com/LucasRStrankman)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* OpenCV creators and contributors for such a useful library
* Creators of the Final Fantasy videogame franchise including:
   - Yoshinori Kitase
   - Motomu Toriyama
   - Takayoshi Nakazato
   - Toshiro Tsuchida
   - Koji Sugimoto
   - Takashi Katano
   - Tetsuya Nomura
   - Yusuke Naora
   - Shintaro Takai
   - Kazushige Nojima
   - Daisuke Watanabe
   - Motomu Toriyama
   - Nobuo Uematsu
   - Masashi Hamauzu
   - Junya Nakano
   - ...and the many others who helped to develop the games!
* Viewers of my GitHub page. Thank you for visiting!
