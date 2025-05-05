# Description
I have a camera and a set of four ND filters (ND1000, ND64, ND8, ND4), and I
want to capture long exposure photos without altering the base exposure.
The idea is to let the camera determine the correct exposure without any
filters attached. I then locate that shutter speed in the first column of a
table. Each row corresponds to that same base exposure, but with different
filter combinations applied (from no filter few filters applied at the same
time). This way, I can determine the appropriate BULB timer settings for any
given filter setup. Or determine filters needed for given shutter time.

# Example
For example, if I want a 2–4 minute exposure, I start by metering the scene
without filters and adjusting aperture and ISO to achieve the desired look.
Suppose the camera gives an exposure of 1/400s. I find the 400 row in the
table and check the values across that row. If I see 2' 44"
(2 minutes 44 seconds), that’s within my target range. I then check the
column header—1k 64—which tells me I need to use ND1000 and ND64 filters
to achieve that shutter duration.

# Not universal
Normally, I prefer projects that are generic and parametric (like I did with
SnapCalc). But in this case, I’m aiming for something quick and tailored
specifically to my camera and my filter kit. The syntax and value ranges are
chosen to match my gear and needs. If someone else wants to adapt it, they’re
welcome to, but out of the box it’s designed around my requirements.

# Other universal calculators
Why not use an existing solution? There are plenty of universal ND exposure
calculators out there, but I wanted something tailored specifically to my
workflow and gear. Generic tools are often too broad or require extra steps.
This project is built exactly around my use cases, with the filter
combinations, exposure ranges, and output formats I actually want to use.

# Output
The data is presented in a Markdown-style table, and also exported as a
CSV file for easy import into spreadsheet software. Also 2 files are available
for download in the releases section. A PDF and an Excel file, each containing
two pages. These are designed to be printed double-sided, cut, and laminated
to create a compact, durable cheat sheet that I can carry with me.

# Final table
| no ND   |       4 |       8 |     8 4 |      64 |    64 4 |    64 8 |      1k |    1k 4 |    1k 8 |  1k 8 4 |  1k 8 4 |   1k 64 | 1k 64 4 |
| ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- |
|    4000 |    1000 |     500 |     125 |      63 |      16 |       8 |     0"3 |     1"0 |     2"0 |     8"2 |     8"2 |    16"4 |  1' 06" |
|    3200 |     800 |     400 |     100 |      50 |      13 |       6 |     0"3 |     1"3 |     2"6 |    10"2 |    10"2 |    20"5 |  1' 22" |
|    2500 |     625 |     313 |      78 |      39 |      10 |       5 |     0"4 |     1"6 |     3"3 |    13"1 |    13"1 |    26"2 |  1' 45" |
|    2000 |     500 |     250 |      63 |      31 |       8 |     0"3 |     0"5 |     2"0 |     4"1 |    16"4 |    16"4 |  0' 33" |  2' 12" |
|    1600 |     400 |     200 |      50 |      25 |       6 |     0"3 |     0"6 |     2"6 |     5"1 |    20"5 |    20"5 |  0' 41" |  2' 44" |
|    1250 |     313 |     156 |      39 |      20 |       5 |     0"4 |     0"8 |     3"3 |     6"6 |    26"2 |    26"2 |  0' 53" |  3' 30" |
|    1000 |     250 |     125 |      31 |      16 |     0"3 |     0"5 |     1"0 |     4"1 |     8"2 |  0' 33" |  0' 33" |  1' 06" |  4' 23" |
|     800 |     200 |     100 |      25 |      13 |     0"3 |     0"6 |     1"3 |     5"1 |    10"2 |  0' 41" |  0' 41" |  1' 22" |  5' 28" |
|     640 |     160 |      80 |      20 |      10 |     0"4 |     0"8 |     1"6 |     6"4 |    12"8 |  0' 52" |  0' 52" |  1' 43" |  6' 50" |
|     500 |     125 |      63 |      16 |       8 |     0"5 |     1"0 |     2"0 |     8"2 |    16"4 |  1' 06" |  1' 06" |  2' 12" |  8' 45" |
|     400 |     100 |      50 |      13 |       6 |     0"6 |     1"3 |     2"6 |    10"2 |    20"5 |  1' 22" |  1' 22" |  2' 44" | 10' 56" |
|     320 |      80 |      40 |      10 |       5 |     0"8 |     1"6 |     3"2 |    12"8 |    25"6 |  1' 43" |  1' 43" |  3' 25" | 13' 40" |
|     250 |      63 |      31 |       8 |     0"3 |     1"0 |     2"0 |     4"1 |    16"4 |  0' 33" |  2' 12" |  2' 12" |  4' 23" | 17' 29" |
|     200 |      50 |      25 |       6 |     0"3 |     1"3 |     2"6 |     5"1 |    20"5 |  0' 41" |  2' 44" |  2' 44" |  5' 28" | 21' 51" |
|     160 |      40 |      20 |       5 |     0"4 |     1"6 |     3"2 |     6"4 |    25"6 |  0' 52" |  3' 25" |  3' 25" |  6' 50" | 27' 19" |
|     125 |      31 |      16 |     0"3 |     0"5 |     2"0 |     4"1 |     8"2 |  0' 33" |  1' 06" |  4' 23" |  4' 23" |  8' 45" | 34' 58" |
|     100 |      25 |      13 |     0"3 |     0"6 |     2"6 |     5"1 |    10"2 |  0' 41" |  1' 22" |  5' 28" |  5' 28" | 10' 56" | 43' 42" |
|      80 |      20 |      10 |     0"4 |     0"8 |     3"2 |     6"4 |    12"8 |  0' 52" |  1' 43" |  6' 50" |  6' 50" | 13' 40" | 54' 37" |
|      60 |      15 |       8 |     0"5 |     1"1 |     4"3 |     8"5 |    17"1 |  1' 09" |  2' 17" |  9' 07" |  9' 07" | 18' 13" |  1h 12' |
|      50 |      13 |       6 |     0"6 |     1"3 |     5"1 |    10"2 |    20"5 |  1' 22" |  2' 44" | 10' 56" | 10' 56" | 21' 51" |  1h 27' |
|      40 |      10 |       5 |     0"8 |     1"6 |     6"4 |    12"8 |    25"6 |  1' 43" |  3' 25" | 13' 40" | 13' 40" | 27' 19" |  1h 49' |
|      30 |       8 |     0"3 |     1"1 |     2"1 |     8"5 |    17"1 |  0' 35" |  2' 17" |  4' 34" | 18' 13" | 18' 13" | 36' 25" |  2h 25' |
|      25 |       6 |     0"3 |     1"3 |     2"6 |    10"2 |    20"5 |  0' 41" |  2' 44" |  5' 28" | 21' 51" | 21' 51" | 43' 42" |  2h 54' |
|      20 |       5 |     0"4 |     1"6 |     3"2 |    12"8 |    25"6 |  0' 52" |  3' 25" |  6' 50" | 27' 19" | 27' 19" | 54' 37" |  3h 38' |
|      15 |     0"3 |     0"5 |     2"1 |     4"3 |    17"1 |  0' 35" |  1' 09" |  4' 34" |  9' 07" | 36' 25" | 36' 25" |  1h 12' |  4h 51' |
|      13 |     0"3 |     0"6 |     2"5 |     4"9 |    19"7 |  0' 40" |  1' 19" |  5' 16" | 10' 31" | 42' 01" | 42' 01" |  1h 24' |  5h 36' |
|      10 |     0"4 |     0"8 |     3"2 |     6"4 |    25"6 |  0' 52" |  1' 43" |  6' 50" | 13' 40" | 54' 37" | 54' 37" |  1h 49' |  7h 16' |
|       8 |     0"5 |     1"0 |     4"0 |     8"0 |  0' 32" |  1' 04" |  2' 08" |  8' 32" | 17' 04" |  1h 08' |  1h 08' |  2h 16' |  9h 06' |
|       6 |     0"7 |     1"3 |     5"3 |    10"7 |  0' 43" |  1' 26" |  2' 51" | 11' 23" | 22' 46" |  1h 31' |  1h 31' |  3h 02' | 12h 08' |
|       5 |     0"8 |     1"6 |     6"4 |    12"8 |  0' 52" |  1' 43" |  3' 25" | 13' 40" | 27' 19" |  1h 49' |  1h 49' |  3h 38' | 14h 33' |
|       4 |     1"0 |     2"0 |     8"0 |    16"0 |  1' 04" |  2' 08" |  4' 16" | 17' 04" | 34' 08" |  2h 16' |  2h 16' |  4h 33' | 18h 12' |
|     0"3 |     1"2 |     2"4 |     9"6 |    19"2 |  1' 17" |  2' 34" |  5' 08" | 20' 29" | 40' 58" |  2h 43' |  2h 43' |  5h 27' | 21h 50' |
|     0"4 |     1"6 |     3"2 |    12"8 |    25"6 |  1' 43" |  3' 25" |  6' 50" | 27' 19" | 54' 37" |  3h 38' |  3h 38' |  7h 16' | 29h 07' |
|     0"5 |     2"0 |     4"0 |    16"0 |  0' 32" |  2' 08" |  4' 16" |  8' 32" | 34' 08" |  1h 08' |  4h 33' |  4h 33' |  9h 06' | 36h 24' |
|     0"6 |     2"4 |     4"8 |    19"2 |  0' 39" |  2' 34" |  5' 08" | 10' 15" | 40' 58" |  1h 21' |  5h 27' |  5h 27' | 10h 55' | 43h 41' |
|     0"8 |     3"2 |     6"4 |    25"6 |  0' 52" |  3' 25" |  6' 50" | 13' 40" | 54' 37" |  1h 49' |  7h 16' |  7h 16' | 14h 33' | 58h 15' |
|     1"0 |     4"0 |     8"0 |  0' 32" |  1' 04" |  4' 16" |  8' 32" | 17' 04" |  1h 08' |  2h 16' |  9h 06' |  9h 06' | 18h 12' | 72h 49' |
|     1"3 |     5"2 |    10"4 |  0' 42" |  1' 24" |  5' 33" | 11' 06" | 22' 12" |  1h 28' |  2h 57' | 11h 49' | 11h 49' | 23h 39' | 94h 39' |
|     1"6 |     6"4 |    12"8 |  0' 52" |  1' 43" |  6' 50" | 13' 40" | 27' 19" |  1h 49' |  3h 38' | 14h 33' | 14h 33' | 29h 07' | x       |
|     2"0 |     8"0 |    16"0 |  1' 04" |  2' 08" |  8' 32" | 17' 04" | 34' 08" |  2h 16' |  4h 33' | 18h 12' | 18h 12' | 36h 24' | x       |
|     2"5 |    10"0 |    20"0 |  1' 20" |  2' 40" | 10' 40" | 21' 20" | 42' 40" |  2h 50' |  5h 41' | 22h 45' | 22h 45' | 45h 30' | x       |
|     3"2 |    12"8 |    25"6 |  1' 43" |  3' 25" | 13' 40" | 27' 19" | 54' 37" |  3h 38' |  7h 16' | 29h 07' | 29h 07' | 58h 15' | x       |
|     4"0 |    16"0 |  0' 32" |  2' 08" |  4' 16" | 17' 04" | 34' 08" |  1h 08' |  4h 33' |  9h 06' | 36h 24' | 36h 24' | 72h 49' | x       |
|     5"0 |    20"0 |  0' 40" |  2' 40" |  5' 20" | 21' 20" | 42' 40" |  1h 25' |  5h 41' | 11h 22' | 45h 30' | 45h 30' | 91h 01' | x       |
|     6"0 |    24"0 |  0' 48" |  3' 12" |  6' 24" | 25' 36" | 51' 12" |  1h 42' |  6h 49' | 13h 39' | 54h 36' | 54h 36' | x       | x       |
|     8"0 |  0' 32" |  1' 04" |  4' 16" |  8' 32" | 34' 08" |  1h 08' |  2h 16' |  9h 06' | 18h 12' | 72h 49' | 72h 49' | x       | x       |
|    10"0 |  0' 40" |  1' 20" |  5' 20" | 10' 40" | 42' 40" |  1h 25' |  2h 50' | 11h 22' | 22h 45' | 91h 01' | 91h 01' | x       | x       |
|    13"0 |  0' 52" |  1' 44" |  6' 56" | 13' 52" | 55' 28" |  1h 50' |  3h 41' | 14h 47' | 29h 34' | x       | x       | x       | x       |
|    15"0 |  1' 00" |  2' 00" |  8' 00" | 16' 00" |  1h 04' |  2h 08' |  4h 16' | 17h 04' | 34h 08' | x       | x       | x       | x       |
|    20"0 |  1' 20" |  2' 40" | 10' 40" | 21' 20" |  1h 25' |  2h 50' |  5h 41' | 22h 45' | 45h 30' | x       | x       | x       | x       |
|    25"0 |  1' 40" |  3' 20" | 13' 20" | 26' 40" |  1h 46' |  3h 33' |  7h 06' | 28h 26' | 56h 53' | x       | x       | x       | x       |
|    30"0 |  2' 00" |  4' 00" | 16' 00" | 32' 00" |  2h 08' |  4h 16' |  8h 32' | 34h 08' | 68h 16' | x       | x       | x       | x       |
