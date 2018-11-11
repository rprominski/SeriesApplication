# Series Application

Application for managing your movies, series etc.

## Getting Started

### Prerequisites

Make sure, that you have this two programs installed:

cmake version 3.10 

c++ compiler supports c++14 standard

```
~$ cmake -version
cmake version 3.10.2

~$ gcc --version
gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

```

### Installing

```
git clone https://github.com/rprominski/SeriesApplication.git
cd SeriesApplication
mkdir build && cd build
cmake .. && make
```

### Running

Go to SeriesApplication/bin folder and just run the SeriesApplication
```
cd ~/SeriesApplication/bin
./SeriesApplication
```

##Demo
The usage is not complicated. Just choose the operation from menu and follow the instructions.
For example: if you want to update the number of watched episodes of following series:
```
1.Add new
2.Add series to following
3.Show all
4.Remove series from following
5.Remove
6.Update
7.Propose something to watching
8.Print statistics of following series
9.Show info about film
10.Show all following series
11.Exit

6

1.Movie
2.Series
3.Following series
4.LiveStream

3

Give a name
Dom z papieru

What do you want update?
1.Nothing
2.Descryption
3.Rate
4.Duration
5.Number of episodes
6.Broadcast days
7.Number of watched episodes

7

New value:

2
```

And that's all.



