
# due to a bug in Arduino we need to use full paths, see https://github.com/arduino/Arduino/issues/1493
if test (uname) = 'Linux'
  set ARDUINO_EXE_PATH /usr/local/bin/arduino
  set BUILD_PATH ~/git/mihini/build
  set SKETCHBOOK_PATH ~/git/mihini
  set INO_PATH ~/git/mihini/mihini/mihini.ino
else  # Darwin
  set ARDUINO_EXE_PATH /Applications/Arduino.app/Contents/MacOS/Arduino
  set BUILD_PATH ~/workspace/mihini/build
  set SKETCHBOOK_PATH ~/workspace/mihini/
  set INO_PATH ~/workspace/mihini/mihini/mihini.ino
end

eval $ARDUINO_EXE_PATH --verify --verbose $INO_PATH \
  --pref build.path=$BUILD_PATH \
  --pref sketchbook.path=$SKETCHBOOK_PATH
