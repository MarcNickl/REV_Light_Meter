# Light Meter
A semi Digital Light Meter (at the moment)

# Goals
To create a null/zero pointer measurement light meter.

simular to the Luna-Pro F light meter.

using anlog inputs where all values of exposure are already entered and a ± EV value is the output.

the best representative term is REV (Relative Exposure Value)

# Progress
As of writing this i have stripped down a gossen Luna F and gotten an arduino UNO

i am using the existing light sensor from the gossen as it has a really wide Dynamic range.

i have stolen the idea of having basicly two base iso's as there are 4 outputs on the light sensor so i can have a high gain and a low gain (using risistors)


# To Do List
calibrate the light meter to get an acurate Lux/EV Value 

Set up the potentiomitor in the dile

Find a way to make the nedle move 


# Functionality

- the ability to export a time log of all information gathered with the time at which it was optained - maybe useful for continuity

from a functionality perspective i really like the controlability of the arri alexa view finder.
- 1 dile for apiture when turned it incicates REV from the point selected
- Modifyer buttons to enable the dial to adjust the ISO/Shutter [speed/Angle]
- XY Button to switch light meter from lux to XY Chroma (requiring a 2 second press)
- Modifyer buttom (basicly an if this then that changing speed to iso and magic to menu also apiture to relative EV)
- HUE° and Satudation.


# Licence

This is a personal project for a problem that I aims to make my life easyer. The code maybe be freely copied for non-commerical purposes.

If you notice a problem with the code or have a better idea of implication please git in contact all sugestions are welcome. 
