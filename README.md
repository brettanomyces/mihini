[Mīhini Whakamaroke](http://www.maoridictionary.co.nz/search?idiom=&phrase=&proverb=&loan=&keywords=m%C4%ABhini+whakamaroke)

A simple switch that turns off after a period of X minutes.

Originally created to turn off my broken dryer, hence the (Māori) name.

## Description

Operate a relay module via an an arduino and two buttons, on and off.

If a user presses the on button the relay will turn on and stay on for 
a period of X.

If a user presses the off button the relay will turn off.

## Build

```
arduino --verify --verbose mihini/mihini.ino --pref build.path=build --pref sketchbook.path=.
```

## Upload

```
arduino --upload mihini/mihini.ino --pref build.path=build --pref sketchbook.path=.
```
