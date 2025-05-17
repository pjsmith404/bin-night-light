# Bin Night Light

Here in my town we have three different bins for our rubbish:

- The red bin for general waste.
- The green bin for organic and food waste.
- The yellow bin for recyclables.

Every week our garbage gets collected on a Tuesday. However, only two bins get collected. The green bin always goes out, but the red and yellow alternate weeks. Occasionally, I will fail to sneak a peak at my neighbours' curbs and put out the wrong bin. This is quite vexing, because now I need to wait another 2 weeks to get a bin emptied that is probably already fairly full. My wife is unamused, I am unamused, my dog is unmoved. So! The plan here is to take the pile of electronics that can't fit in my overloaded bins and turn them into a useful reminder of which bin is meant to go out on which night.

# Achieving this goal

## Equipment

The following tools will be required:
- An **Arduino** to act as the brains of the operation.
- The guiding glow of **LEDs**.
- Some sort of module to help keep time. (Further research is required)
- Access to a wife with a 3D printer at work. Because what electronics project would be complete without a cute printed thing?

## The plan

1. **DONE** Get my Arduino programmable on whatever god forsaken operating system I'm using today.
2. **DONE** Get my Arduino operating an LED or two. I'll probably go for basic LEDs here, although something overly programmable could be fun.
3. Keep track of time with a time keeping module. I don't think Arduino's basic clock will be able to track dates in any particularly useful way. Although, it could be a fun maths problem.
4. Actually find out what day my bins are meant to go out on. This has proven a challenging task thus far.
5. Find a design for a small bin that will hold the Arduino and all its attachements.
6. Get said bin printed by my beautiful and loving wife.

# Notes

## 2025-05-17

I've introduced a switcher function that will just test one pin's state and swap the two LEDs around based on that.

For timekeeping, I've introduced a delay constant that I'll just crank up to be 7 days in milliseconds or something like that. Because calendars, time and an arduino's ability to track time are all pretty loose, this will not remain accurate. My lazy solution is some combination of power cycling and a switcher to swap the active light. I'll develop on that basis and then consider either a RTC or NTP to get more precise timekeeping. The timekeeping will likely just be determined by whether I think I should spend more time on it.

## 2025-05-16

With a basic circuit done up, I just need to determine a suitable way to keep track of time. I see a few options:

- Use the built in millis and try to keep track of a 7 day cycle to switch which LED is on. I could start the cycle from power on, then use a button to flip which bin LED should be lit up. As long as the right light is on on a Tuesday, it doesn't really matter the rest of the time what's on. Millis overflows after 50 days, so some appropriate handling will need to be considered there.
- Buy an RTC module and use a proper time keeper. This would require some mechanism for setting the date, but a control panel feels a bit much.
- I have an ESP8266 lying around. I might be able to use that to run NTP, which means no configuring dates, just setting wifi and appropriate weeks.

