# FFX-Computer-Vision
A project that uses computer vision to complete the "Dodge 200 Lightning Strikes" challenge in FFX. The collected data was investigated through a data analysis to gain some insight into the game mechanics.

> _"Listen to my story...this may be our last chance"_
> _- Tidus_

## Problem Description

Final Fantasy 10 (FFX) is a game first released for the Playstation 2 console in 2001, then later released onto a wider variety of consoles between 2013 - 2019. It is a standard RPG-style game with side-quests deviating from the main storyline. One of these side-quests happens to be the (now infamous) "Dodge 200 Lightning Strikes" challenge which is essentially impossible to complete without extreme determination and focus. This is a project that avoids that demand for extreme determination and focus, and provides a solution through implementation of various hardware and software.

## Project Goals

There were two main goals for this project:

1. Create an automated solution to complete the "Dodge 200 Lightning Strikes" challenge.
2. Collect data to investigate the behaviour of and gain insight to the timing of the lightning strikes.

**Hypothesis for Second Goal:** We make the hypothesis that the timing between consecutive lightning strikes is random.

The first goal was completed successfully through our electronics setup. The setup consisted of a webcam connected to a Raspberry Pi 4 (Rpi4) that was picking up the video input from the game. The Rpi4 had an IoT connection with an Arduino Uno microcontroller that would press the required Playstation 4 controllor button at the right time.

The second goal was completed through a [data analysis](/blob/master/Lightning%20Data.ipynb). The IDE of choice for the analysis was a Jupyter Notebook. After importing the raw data and performing data cleaning procedures, new features were created and the subsequent majority of time was spent within the exploratory data analysis phase.

## Data Analysis Summary

The main goal of the data analysis was to gather insight into the timing of the lightning strikes. Below is a summary list of the main findings from the data analysis. Please continue reading through this report for more details:

1. The lightning strike frequency is NOT random, as we had hypothesized from the start!
2. The time interval between lightning strikes is either ~6s or ~11s.
3. The two time intervals between lightning strikes alternate.

Here is a link to the Jupyter Notebook: [FFX Data Analysis](/blob/master/Lightning%20Data.ipynb)

## Hardware and Software Used Used

* Python Version: 3.7
* Python Libraries: numpy, pandas, matplotlib, seaborn, plotly (via chart_studio), cufflinks, datetime, scipy, open-cv

* Raspberry Pi 4
* Arduino Uno
* Servo Motor SG90
* Logitech C922 Webcam

## Data Collection Methodology

We created a Python script that uses computer vision (CV) via the OpenCV library. A webcam aimed at the screen was set up to continuously detect the video feed from the game and  feed it into our program. By nature of video media, this meant our script was constantly receiving individual frames at a rapid frequency. These colored frames were then converted into grayscale. This OpenCV Python script was run on the Rpi4. 

The Rpi4 was connected in a circuit with an Arduino Uno microcontroller which we used to control a servo motor that presses the button on the PS4 controller. Because a lightning strike causes the screen to become very bright, our script sent a signal from the Rpi4 to the Arduino to activate it based on a certain grayscale threshold value. Hence, the electronics and software setup was able to successfully detect a lightning strike and send a signal to cause the PS4 controller button to be physically pressed.

Through this setup, we have collected two independent data sets. The first is what we call the 'smaller' data set with 1135 data points and the second is the 'larger' data set with 1859 points.

## Data Cleaning

Here is a summary of the data cleaning procedures that were done:

* Removed extraneous spaces in data set
* Convert the 'timings' column to DateTime object types
* Removed bad data points from raw data
  - Occurance was due to startup and shutdown of data collecting setup

## Feature Engineering

The main thing we are interested in is the timing of the lightning strikes. More specifically, we wish to investigate the amount of time between consecutive lightning strikes.

As such, the main feature we created was a 'time difference' feature. This was done simply by subtracting two consecutive datetime values throughout our cleaned data set. We also extracted the number of seconds between lightning strikes as a simple float data type.

## Exploratory Data Analysis

*NOTE: Plots related to the smaller data set are colored red; those related to the larger dataset are colored blue.*

The first thing to investigate was the very obvious dual modality of the time difference feature. A basic rugplot helps us to visualize this dual moadality:

![alt text][rugplot1]

As we can see, both images show the time difference data clustered around 6 & 11.25 seconds. In the larger data set, we clearly see five values that do not lie in these clusters. We considered these five values to be outliers and removed them from our data set, as seen in the rugplot below:

![alt text][rugplot2]

The logical next step, was to investigate the two clusters individually. A few scatter plots show this clustering behaviour more readily:

![alt text][scatter1a]
![alt text][scatter1b]

We split each scatter plot into their low and high values:

![alt text][scatter2]

In each split scatter plot above, we see that there is minimal dispersion of the time difference values about their mean. In both data sets, we see the range of the data values to be approximately 0.2 seconds and 0.25 seconds for the low and high modes, respectively.

We then used histograms to visualize the distribution of the time difference feature. One histogram is shown below:

![alt text][histogram1]

Once again, we see the bi-modal behaviour but more interestingly, we now see that the time difference values seem to be equally distributed between the two modes. This suggests that the time difference between lightning strikes must be alternating between the two modes! We choose to investigate this idea later, and continue to look into the individual clusters themselves.

Continuing our analysis, we split the above histograms into their two modes as seen in the figure below:

![alt text][histogram2]

These four histograms are close to a normal distribution. We can be certain that with a much larger data set this would indeed be the case. Here is a table that summarizes the mean and standard deviation of each histogram:

|  || Small Dataset || Large Dataset |
--- | --- | --- | --- | ---
|| Mean | Std. | Mean | Std. |
| Smaller Mode | 6.008 | 0.0317 | 6.011 | 0.0326 |
| Larger Mode | 11.180 | 0.0460 | 11.172 | 0.0466 |

For each pair of mean and standard deviation values, we can compute the coefficients of variance to assess the meaning of the standard deviation in each case:

| CoV | Small Dataset | Large Dataset |
--- | --- | ---
| Smaller Mode | 0.005270 | 0.005429 |
| Largeer Mode | 0.004111 | 0.004175 | 

Since the coefficient of variance is very small in all four cases, we conclude that the time difference values are very tightly clustered around their respective means.

Finally, we investigated the suspected alternating pattern. Recall from the first histogram above, we hypothesized that the lightning strikes occur in an alternating fashion, first with ~6s between them, then ~11.25s. Indeed, we created a function to determine if this were true and the answer is a resounding 'yes'! *(See [detailed data analysis](/blob/master/Lightning%20Data.ipynb) for more information)*

## Conclusion

In conclusion, our analysis revealed very unexpected results! We had originally believed (or perhaps, **perceived** during gameplay) that the timing between lightning strikes was random. In fact, it turns out that it is not random at all, and actually alternates between 6s and 11.25s.

## Future Steps

Here are some avenues one may take to continue expanding on our work or investigate other FFX-related projects in the future:
* Finish analysis of the grayscale data
* Create solutions for other side quests in FFX (dodging birds, anyone?)
* Look into other FF series games and apply your electronics and data science skills

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
   - Nobuo Uematsu
   - Masashi Hamauzu
   - Junya Nakano
   - ...and the many others who helped to develop the games!
* Viewers of my GitHub page. Thank you for visiting!

<!-- Image References -->

[boxwhisker]: Plots_for_Readme/boxwhisker1.png "Dataset quartiles"
[histogram1]: Plots_for_Readme/histogram1.png "Overview of timings distribution"
[histogram2]: Plots_for_Readme/histogram2.png "Histogram of timings"
[rugplot1]: Plots_for_Readme/rugplot1.png "Before cleaning"
[rugplot2]: Plots_for_Readme/rugplot2.png "After cleaning"
[scatter1a]: Plots_for_Readme/scatter1a.png "First dataset"
[scatter1b]: Plots_for_Readme/scatter1b.png "Second dataset"
[scatter2]: Plots_for_Readme/scatter2.png "Timings scatterplot"
