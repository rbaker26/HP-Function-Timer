# HP-Function-Timer
A High Performance Timing Class for C++17 

# WORK IN PROGRESS


Results of running main.cpp
```
std::sort(seq) - n=100:                 Time: 3.9e-06
std::sort(seq) - n=1000:                Time: 5.11e-05
std::sort(seq) - n=10000:               Time: 0.0006547
std::sort(seq) - n=100000:              Time: 0.0069744
std::sort(seq) - n=1000000:             Time: 0.0857641
std::sort(seq) - n=10000000:            Time: 1.12251
std::sort(seq) - n=100000000:           Time: 11.2943
std::sort(seq) - n=1000000000:          Time: 126.216

std::sort(par) - n=100:                 Time: 0.0002817
std::sort(par) - n=1000:                Time: 0.0010453
std::sort(par) - n=10000:               Time: 0.0014441
std::sort(par) - n=100000:              Time: 0.0042218
std::sort(par) - n=1000000:             Time: 0.0262924
std::sort(par) - n=10000000:            Time: 0.260179
std::sort(par) - n=100000000:           Time: 2.40641
std::sort(par) - n=1000000000:          Time: 27.7601

std::sort(par_unseq) - n=100:           Time: 5.87e-05
std::sort(par_unseq) - n=1000:          Time: 9.36e-05
std::sort(par_unseq) - n=10000:         Time: 0.0002704
std::sort(par_unseq) - n=100000:        Time: 0.0020708
std::sort(par_unseq) - n=1000000:       Time: 0.0232365
std::sort(par_unseq) - n=10000000:      Time: 0.245376
std::sort(par_unseq) - n=100000000:     Time: 2.46928
std::sort(par_unseq) - n=1000000000:    Time: 28.0575


std::cout:          Time: 0.000233
std::cout - endl:   Time: 0.0004664
```
