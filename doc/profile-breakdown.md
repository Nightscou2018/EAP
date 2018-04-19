# Breakdown of oref0 profile code

This needs to be done to reimplement this code.
This code seems to be concerned with autotuning.
It reads in a profile.json file, of which an example can be
found [here](http://openaps.readthedocs.io/en/latest/docs/Customize-Iterate/autotune.html).
Look for 'profile.json' in the document.

## Definitions

BG: Blood Glucose
IOB: Insulin On Board
ISF: Insulin Sensitivity Factor
DIA: Duration of Insuline Activity

## Basal

### basalLookup

The basalLookup function is pretty simple.
It needs to return the basal rate (U/hr) at a given timeofday.

It's given the time that is requested with the name 'now',
which is pretty bad because the comment says 'at the provided timeofday',
which may or may not be 'now'.
It also has a schedules parameter, which seems to contain
the information that the pump has logged.

### maxDailyBasal

Returns the maximum basal from a given list (and doesn't check which day it is).
Also does something weird with (num * 1000) / 1000.
A classmate told me this might be a way to round the value(?).

### maxBasalLookup

Returns a variable somewhere down in an object, nothing special.
Not sure if this oneliner is one we should keep.
It is already expressed with the name of the variable looked up.

## Carbs

### carbRatioLookup

Takes 'inputs' as a parameter but doesn't use all of its functionality.
It takes the carbratio out of the inputs and then doesn't use the input
variable anywhere.

Proceeds to check if the 'units' are grams or 'exchanges'.
Takes the latest carbratio out of the carbratio.schedule.

